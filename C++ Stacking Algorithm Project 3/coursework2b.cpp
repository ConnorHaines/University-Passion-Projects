#include<iostream> //allows use of standard in/out stream
using namespace std; //where features of the C++ Standard Library are declared

template<typename T>
class Node//class representing a node in a data structure
{
private: //can be accessed only through methods of the class
	
    T value; //variable called value
	Node* pNext;
    
public: //are accessible outside the class.
    
	void setvalue(T value); //setter method called setvalue
	T getvalue(); //getter method called get value
 	void setpNext(Node* pNext); //setter method called setpNext
    Node* getpNext(); //creating getter method called getpNext
	Node(); //contructor that loads the default values for variables
    ~Node(); //destructor for the Node class
};

template <typename T>
class Stack {
private:
	int count = 0; //declares count
	Node<T> *pTop = nullptr; //declares and sets pTop to null as default
	Node<T>* nodePop(void); //declares nodePop
public:
	~Stack(void); //declares destructor for Stack
	void push(T value); //declares the push function
	T pop(void); //declares the pop function
	int size(void); //declares the size function

};



template<typename T>
Node<T>* Stack<T>::nodePop(void)
{
	Node<T> *pTmp = pTop; //pTmp will equal pTop
	if (pTop != nullptr) pTop = pTop->getpNext(); //if pTop has something in it, it will make pTop point to getpNext
	return pTmp;//return the value in pTmp
}

template<typename T>
Stack<T>::~Stack(void) //destructor for the Stack Class
{
	while (pTop != nullptr) //while pTop has a value (or is not equal to null)...
	{
		delete nodePop(); //...it will delete nodePop
	}
}

template<typename T>
Node<T>::Node() //constructor for Node Class
{
	T value = 0; //sets int value to 0

    Node* pNext = nullptr;  //sets pNext to null
}

template<typename T>
Node<T>::~Node() //constructor for Node Class
{
    T value = 0; //sets int value to 0
    
    Node* pNext = nullptr;  //sets pNext to null
}

template<typename T>
void Node<T>::setvalue(T value)
{
	this->value = value; //sets value
}


template<typename T>
T Node<T>::getvalue()
{
	return value; //returns value
}


template<typename T>
void Node<T>::setpNext(Node * pNext)
{
	this->pNext = pNext; //sets pNext
}

template<typename T>
Node<T>* Node<T>::getpNext()
{
	return pNext; //returns the value in pNext
}



template<typename T>
void Stack<T>::push(T value) //function for pushing a value onto the stack
{
	Node<T>* pTmp = new Node<T>; //creates a temporary new Node
	
    pTmp->setvalue(value); //this sets a value in the temporary new node
	
    pTmp->setpNext(pTop); //as this is has been the most recent node made it will be at the top of the stack, this line sets pTmp as pTop
	
    pTop = pTmp; //this is setting pTmp to the same value as pTop
	
    count++; //increments count by 1
}


template<typename T>
T Stack<T>::pop(void)
{
	if (count == 0) throw "\nStack Empty Warning!\n"; //if count equals 0 throw an error and print out "Stack Empty" to user

    Node<T> *pTmp = nodePop();  //gets value from pTmp

	T ret; //declares ret

	if (pTmp != nullptr) { //if pTmp has a value in it..
		ret = pTmp->getvalue(); //ret is assigned as pTmp, which calls getvalue
	}
	else { //if pTmp is equal to null..

		throw "\nERROR!!\n"; //throw an error outputting "Error"
	}

	delete pTmp; //deletes pTmp
	
    count--; //decrements count by 1
	
    return ret; //returns the value in ret
}

template<typename T>
int Stack<T>::size(void)
{

	return count; //return value in count
}


