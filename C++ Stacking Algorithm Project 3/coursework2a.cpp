#include <iostream> //allows use of standard in/out stream

using namespace std; //where features of the C++ Standard Library are declared

 

class Node //class representing a node in a data structure

{
private: //can be accessed only through methods of the class
	
    int value;  //integer variable called value
	Node* pNext = nullptr; //this sets the default of pNext as null

public: //are accessible outside the class.
    
	void setvalue(int value); //setter method called setvalue
	int getvalue(); //getter method called get value
	void setpNext(Node* pNext); //setter method called setpNext
	Node* getpNext(); //creating getter method called getpNext
	Node(); //contructor that loads the default values for variables
	~Node(); //destructor for the Node class

};

 

class Stack

{

   private:

       int count = 0; //declares count

       Node *pTop = nullptr; //declares and sets pTop to null as default

       Node* nodePop(void); //declares nodePop

   public:

       ~Stack(void); //declares destructor for Stack

       void push(int value); //declares the push function

       void pop(void); //declares the pop function

 

};

void Node::setvalue(int value)
{
	this->value = value; //sets value
}


int Node::getvalue()
{
	return value; //returns value
}

void Node::setpNext(Node* pNext)
{
	this->pNext = pNext; //sets pNext
}

Node * Node::getpNext()
{
	return pNext; //returns the value in pNext
}


Node::~Node() //destructor for Node Class
{
    int value = 0; //sets int value to 0
    Node* pNext = nullptr; //sets pNext to null
}


Stack::~Stack(void) //destructor for the Stack Class

{

    while (pTop != nullptr) //while pTop has a value (or is not equal to null)...

    {

        delete nodePop(); //...it will delete nodePop


    }

}

 

void Stack::push(int value) //function for pushing a value onto the stack

{

    Node* pTmp = new Node; //creates a temporary new Node

    pTmp->setvalue(value); //this sets a value in the temporary new node

    pTmp->setpNext(pTop); //as this is has been the most recent node made it will be at the top of the stack, this line sets pTmp as pTop

    pTop = pTmp; //this is setting pTmp to the same value as pTop

    count++; //increments count by 1

    cout << "Value of " << value << " pushed onto stack. \n"; //this outputs what the newest value being pushed onto the stack is

}

Node* Stack::nodePop(void)

{

    Node *pTmp = pTop; //pTmp will equal pTop

    if(pTop != nullptr) pTop = pTop->getpNext(); //if pTop has something in it, it will make pTop point to getpNext

    return pTmp; //return the value in pTmp

}

void Stack::pop(void)

{

    if (count == 0) throw "Stack Empty!"; //if count equals 0 throw an error and print out "Stack Empty" to user

    Node *pTmp = nodePop(); //gets value from pTmp

    if (pTmp != nullptr) //if pTmp has a value in it..

    {

        cout << "Value of " << pTmp->getvalue() << " popped off of stack. \n"; //.. output to the user what the newest value being popped off the stack is...

        delete pTmp; //...deletes pTmp...
    
        count--; //...will decrement count by 1...

    }
    else //...otherwise will...
    {
        throw "Error!"; //...throw error with a message outputting for user
    }

}



