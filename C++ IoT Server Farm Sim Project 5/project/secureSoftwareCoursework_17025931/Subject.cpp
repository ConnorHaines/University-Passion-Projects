#include "Subject.h"
#include <iostream>
#include <string>

using namespace std;

Subject::Subject(string a, string pass) : id(a), password(pass)
{
	proofID = "";
}

Subject::Subject()
{
	cout << "\nEnter UserID : ";
	cin >> id;
	cout << "\nEnter password : ";
	cin >> password;
}

string Subject::getId()
{
	return id;
};
string Subject::getPassword()
{
	return password;
};

void Subject::setproofofID(string proof)
{
	proofID = proof;
};

string Subject::getproofofID()
{
	return proofID;
};