#include<iostream>
#include<vector>

using namespace std;

enum state { Out_Of_Chocolate, No_Credit, Has_Credit, Dispenses_Chocolate, Maintenance_Mode }; //used for the state of the vending machine

class StateContext;

class State 
{
protected:
	StateContext* CurrentContext; //creates a pointer names current context which allows us to point to statecontext;
public:
	State(StateContext* Context) { CurrentContext = Context; } //a constructor for the class called state and the parameter creates a pointer called context
	virtual ~State(void) {}//deconstructor for state has no parameters
};

class StateContext
{
protected:
	State* CurrentState = nullptr;//setting a new pointer called currentstate to equal nullptr so it isn't pointing to anything as its default
	int stateIndex = 0; //this is used to store the current state
	vector<State*> availableStates; //this is a vector that stores  the values of variables like chocolate and credit...
public:
	virtual ~StateContext(void); //deconstructor for StateContext
	virtual void setState(state newState);//setting of the state
	virtual int getStateIndex(void); // returns the current state index
};

StateContext::~StateContext(void)
{
	for (int i = 0; i < this->availableStates.size(); i++) delete this->availableStates[i]; //vector is looped deleted it one by one
	this->availableStates.clear(); //precautionary clearing of the state
}

void StateContext::setState(state newState)
{
	this->CurrentState = availableStates[newState]; //sets the available states with newstate to currentstate
	this->stateIndex = newState; //sets the stateindex from newstate
}

int StateContext::getStateIndex(void)
{
	return this->stateIndex; //returns stateIndex
}

class Transition
{
public:
	virtual bool insertMoney(int) { cout << "Error!" << endl; return false; }   //all of these....
	virtual bool makeSelection(int) { cout << "Error!" << endl; return false; }
	virtual bool moneyRejected(void) { cout << "Error!" << endl; return false; }
	virtual bool addChocolate(int) { cout << "Error!" << endl; return false; }
	virtual bool dispense(void) { cout << "Error!" << endl; return false; }
	virtual bool enterPin(int pin) { cout << "Error!" << endl; return false; }
	virtual bool exit(void) { cout << "Error!" << endl; return false; } //...are defaults in case the virtual bools are not defined or something has gone wrong
};

class ChocoState : public State, public Transition
{
public:
	ChocoState(StateContext* Context) : State(Context) {} 
};

class OutOfChocolate : public ChocoState
{
public:
	OutOfChocolate(StateContext* Context) : ChocoState(Context) {} //passes on the variable state context to statecontext context
	bool enterPin(int pin); //declares enterpin function for outofchocolate
	bool moneyRejected(void);//declares moneyrejected function for outofchocolate
	bool addChocolate(int number);//declares addchocolate function for outofchocolate
};

class NoCredit : public ChocoState
{
public:
	NoCredit(StateContext* Context) : ChocoState(Context) {} //passes on the variable state context to statecontext context
	bool insertMoney(int credit); //declares insertmoney function for nocredit
	bool enterPin(int pin); //declares enterpin function for nocredit
};

class HasCredit : public ChocoState
{
public:
	HasCredit(StateContext* Context) : ChocoState(Context) {}//passes on the variable state context to statecontext context
	bool insertMoney(int credit); //declares insertmoney function for hascredit
	bool makeSelection(int option); //declares makeselection function for hascredit
	bool moneyRejected(void); //declares moneyrejected function for hascredit
};

class DispensesChocolate : public ChocoState
{
public:
	DispensesChocolate(StateContext* Context) : ChocoState(Context) {}//passes on the variable state context to statecontext context
	bool dispense(void);//declares dispense function for dispensechocolate
};

class MaintenanceMode : public ChocoState
{
public:
	MaintenanceMode(StateContext* Context) : ChocoState(Context) {}//passes on the variable state context to statecontext context
	bool exit(void); //declares exit function for maintenance mode
	bool addChocolate(int number); //declares addchocolate function for maintenance mode
};

class Chocolate_Dispenser : public StateContext, public Transition
{
	friend class OutOfChocolate;
	friend class NoCredit;
	friend class HasCredit;
	friend class DispensesChocolate;
	friend class MaintenanceMode;
private:
	int inventory = 0; //number of chocolate
	int credit = 0; //a measure of the number of bars that can be purchased and not money
	int pin = 54321; //secret pin for maintenance mode - *DO NOT CHANGE*
public:
	Chocolate_Dispenser(void);
	bool insertMoney(int credit); 
	bool makeSelection(int option);
	bool moneyRejected(void);
	bool addChocolate(int number);
	bool dispense(void);
	bool enterPin(int pin);
	bool exit(void);
};

Chocolate_Dispenser::Chocolate_Dispenser(void)
{
	this->availableStates.push_back(new OutOfChocolate(this));
	this->availableStates.push_back(new NoCredit(this));
	this->availableStates.push_back(new HasCredit(this));
	this->availableStates.push_back(new DispensesChocolate(this));
	this->availableStates.push_back(new MaintenanceMode(this));

	this->setState(Out_Of_Chocolate);
}

bool Chocolate_Dispenser::insertMoney(int credit)
{
	return ((ChocoState*)CurrentState)->insertMoney(credit);
}
bool Chocolate_Dispenser::makeSelection(int option)
{
	return ((ChocoState*)CurrentState)->makeSelection(option);
}
bool Chocolate_Dispenser::moneyRejected(void)
{
	return ((ChocoState*)CurrentState)->moneyRejected();
}
bool Chocolate_Dispenser::addChocolate(int number)
{
	return ((ChocoState*)CurrentState)->addChocolate(number);
}
bool Chocolate_Dispenser::dispense(void)
{
	return ((ChocoState*)CurrentState)->dispense();
}

bool Chocolate_Dispenser::enterPin(int pin)
{
	return ((ChocoState*)CurrentState)->enterPin(pin);
}

bool Chocolate_Dispenser::exit(void)
{
	return ((ChocoState*)CurrentState)->exit();
}

bool OutOfChocolate::enterPin(int pin)
{
	cout << "You are attempting to go into maintenance mode" << endl; 

	if (((Chocolate_Dispenser*)CurrentContext)->pin != pin) //...if the pin inputted is the incorrect pin
	{
		cout << "Sorry! You have input an invalid pin" << endl; //...outputs this
		return false;
	}
	else  //.....otherwise.....
	{

		cout << "Correct Pin - going into maintenance mode!" << endl; //...outputs this and...

		CurrentContext->setState(Maintenance_Mode);//...sets state to maintenance mode

		return true;
	}


}

bool OutOfChocolate::moneyRejected(void)
{
	cout << "Rejecting Money...." << endl; //if theres no chocolate then the money will be rejected
	((Chocolate_Dispenser*)CurrentContext)->credit = 0; //sets credit to 0
	CurrentContext->setState(Out_Of_Chocolate); //sets the state to out of chocolate
	return false;
}

bool OutOfChocolate::addChocolate(int number)
{
	((Chocolate_Dispenser*)CurrentContext)->inventory += number; //if out of chocolate then you can addchocolate (in maintenance mode) 
	cout << "Adding chocolate... Inventory = " << ((Chocolate_Dispenser*)CurrentContext)->inventory << endl; //outputs the new inventory count
	CurrentContext->setState(No_Credit); //sets state back to no credit
	return true;
}

bool NoCredit::insertMoney(int credit)
{
	((Chocolate_Dispenser*)CurrentContext)->credit += credit; //if theres no credit and you put credit in it will add credit 
	cout << "Adding credit... Credit = " << ((Chocolate_Dispenser*)CurrentContext)->credit << endl; //outputs current credit amount
	CurrentContext->setState(Has_Credit); //sets state to has credit
	return true;
}

bool NoCredit::enterPin(int pin)
{
	cout << "You are attempting to go into maintenance mode" << endl;

	if (((Chocolate_Dispenser*)CurrentContext)->pin != pin) //same thing as other enterpin
	{
		cout << "Sorry! You have input an invalid pin" << endl;
		return false;
	}
	else
	{

		cout << "Correct Pin - going into maintenance mode!" << endl;

		CurrentContext->setState(Maintenance_Mode);

		return true;
	}
}

bool HasCredit::insertMoney(int credit)
{
	((Chocolate_Dispenser*)CurrentContext)->credit += credit;
	cout << "Adding credit... Credit = " << ((Chocolate_Dispenser*)CurrentContext)->credit << endl; //same thing as other insertmoney
	return true;
}

bool HasCredit::makeSelection(int option) //in this example option = number of bars, but could be used to represent other products

{	
	cout << "You have selected this many bars of chocolate: " << option << endl;

	if (((Chocolate_Dispenser*)CurrentContext)->inventory < option) //if the user tries to get more chocolate than is in the machine...
	{
		cout << "Sorry! You have selected more chocolate bars than the machine has" << endl; //..this is outputted
		return false; //and it will return false
	}
	if (((Chocolate_Dispenser*)CurrentContext)->credit < option) //if the user doesn't have enough credit...
	{
		cout << "Sorry! You don't have enough credit to make that purchase" << endl;//...this will be outputted
		return false;//and it will return false

	}
	cout << "Credit and investory sufficiently satisfied - checking out order now" << endl; //otherwise this will be outputted

	((Chocolate_Dispenser*)CurrentContext)->inventory -= option; //this minus' the option from inventory
	((Chocolate_Dispenser*)CurrentContext)->credit -= option; //this minus' the option from credit

	CurrentContext->setState(Dispenses_Chocolate); //sets state to dispense chocolate
	return true;
}

bool HasCredit::moneyRejected(void)
{
	cout << "Rejecting money...." << endl; 
	((Chocolate_Dispenser*)CurrentContext)->credit = 0; //sets credit to 0
	CurrentContext->setState(No_Credit); //sets state to no credit
	return true;
}

bool DispensesChocolate::dispense(void)
{
	cout << "Dispensing product..." << endl;
	cout << "Inventory = " << ((Chocolate_Dispenser*)CurrentContext)->inventory << endl; //outputs current inventory
	cout << "Credit = " << ((Chocolate_Dispenser*)CurrentContext)->credit << endl; //outputs current credit

	if (((Chocolate_Dispenser*)CurrentContext)->inventory == 0) CurrentContext->setState(Out_Of_Chocolate); //if inventory is equal to 0 then setstate to out of chocolate
	else if (((Chocolate_Dispenser*)CurrentContext)->credit == 0) CurrentContext->setState(No_Credit);//if credit is equal to 0 then setstate to nocredt
	else CurrentContext->setState(Has_Credit);//otherwise set state to has credit
	return true;
	
}

bool MaintenanceMode::exit(void)
{
	cout << "Exiting... " << endl;

	if (((Chocolate_Dispenser*)CurrentContext)->inventory == 0) CurrentContext->setState(Out_Of_Chocolate); //same as above
	else if (((Chocolate_Dispenser*)CurrentContext)->credit == 0) CurrentContext->setState(No_Credit);//same as above
	else CurrentContext->setState(Has_Credit);
	return true;
}

bool MaintenanceMode::addChocolate(int number)
{
	((Chocolate_Dispenser*)CurrentContext)->inventory += number; //same as other add chocolate function
	cout << "Adding chocolate... Inventory = " << ((Chocolate_Dispenser*)CurrentContext)->inventory << endl;
	return true;
}

int main(void)
{
	Chocolate_Dispenser MyDispenser;

	MyDispenser.enterPin(2543);
	MyDispenser.enterPin(54321);
	MyDispenser.addChocolate(10);
	MyDispenser.exit();
	MyDispenser.insertMoney(10);
	MyDispenser.makeSelection(20);
	MyDispenser.makeSelection(10);
	MyDispenser.dispense();

	system("PAUSE");

	return 0;

}



