#ifndef AUTH_H
#define AUTH_H
#include <iostream>
#include <string>
#include "Subject.h"
#include "ProofofID.h"

using namespace std;

//Authenticator class
class Authenticator
{
public:
	Authenticator();
	ProofofID * authenticateUser(Subject &s);
private:
	string encryptDecrypt(string toEncrypt);
};
#endif