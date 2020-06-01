#pragma once
#include <string>
using namespace std;

class Subject
{
private:
	string id;
	string password;
	string proofID;

public:
	Subject(string a, string pass);
	Subject();
	string getId();
	string getPassword();
	void setproofofID(string proof);
	string getproofofID();
};