#ifndef AUTHINF_H
#define AUTHINF_H
#include <string>
#include <iostream>
#include <map>
using namespace std;

//AuthenticationInfo class
class AuthenticationInfo
{
private:
	map<string, string> Users; // userId password
public:
	AuthenticationInfo(); // constructor sets attributes
	bool validatesUser(string name, string password);
};
#endif