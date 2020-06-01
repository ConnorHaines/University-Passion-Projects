#include "Authenticator.h"
#include "AuthenticationInfo.h"
#include <iostream>
#include <string>
//#include "User.cpp"
#include "ProofofID.h"
using namespace std;

Authenticator::Authenticator() {};

ProofofID * Authenticator::authenticateUser(Subject &s)
{
	AuthenticationInfo ainfo;
	ProofofID *proofofID = nullptr;
	string Id = s.getId();
	string pass = s.getPassword();
	string token = "";
	if (ainfo.validatesUser(Id, pass))
	{
		cout << "\nWelcome!";
		cout << "\nAuthenticated!\n";
		token = encryptDecrypt(Id + pass);
		proofofID = new ProofofID(token);
		s.setproofofID(token);
	}//if
	else
		cout << "Invalid user ID or Password. Please try again.";
	return proofofID;
};

string Authenticator::encryptDecrypt(string toEncrypt)
{
	char key = 'A';
	string output = toEncrypt;
	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key;
	return output;
}