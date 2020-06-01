#include "AuthenticationInfo.h"
#include <iostream>
#include <string>
//#include "User.cpp"
#include <map>
using namespace std;

AuthenticationInfo::AuthenticationInfo()
{
	Users.insert(pair<string, string>("Connor", "boss"));
	Users.insert(pair<string, string>("Cullen", "fail"));
	Users.insert(pair<string, string>("Georgio", "babe"));
};

bool AuthenticationInfo::validatesUser(string name, string pass)
{
	bool validUser = false;
	map<string, string>::iterator it;
	it = Users.find(name);
	if (it != Users.end())
	{
		if (!(it->second.compare(pass)))
		{
			validUser = true;
		}
	}
	return validUser;
}