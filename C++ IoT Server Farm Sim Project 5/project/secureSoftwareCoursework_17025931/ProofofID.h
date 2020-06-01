#ifndef PROOF_H
#define PROOF_H
#include <iostream>
#include <string>


using namespace std;

class ProofofID
{
private:
	string proofID;
public:
	ProofofID() {};
	ProofofID(string);
	string getproofID();
	void setproofID(string);
};
#endif