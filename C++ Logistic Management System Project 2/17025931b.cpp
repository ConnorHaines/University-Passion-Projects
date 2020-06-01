#pragma once				//causes the current source file to be included only once in a single compilation
#include<iostream>		    //will not compile unless this is added because you need to read or write to the standard input/output streams
#include<string>			// need for when you use a variable that has type std::string.
#include<fstream>			
#include<vector>

using namespace std;

class OrganisationRecord 
{
private:

public:
	
	string name;
	string occupation;
	string department;

};

class HRRecord
{
private:

public: 
	string address; 
	string phonenumber;
	string ninumber;
};

class PayrollRecord
{
private:

public:
	string ninumber;
	double salary;
};

class PayrollProcessing
{
private:
	ifstream inputfile;
	ofstream outputfile;
	vector<OrganisationRecord> OrganisationRecords;
	vector<HRRecord> HRRecords;
	vector<PayrollRecord> PayrollRecords;

public:
	void loadOrganisationRecords(string filename);
	void loadHRRecords(string filename);
	void loadPayrollRecords(string filename);
	void displayEmployeeOfSalaryGTE(double salary);
	//GTE Greater Than or Equal To
};


void PayrollProcessing::loadOrganisationRecords(string filename)
{
	string line;                                                  //declare string line
	OrganisationRecord OrgRecCall;                                // create OrgRecCall to connect to OrganisationRecord for later use
	inputfile.open(filename);
	if (!inputfile)
	{
		cout << "Error! The file  '" << filename << "'could not be found!"  << endl;

	}
	else {

		while (getline(inputfile, line)) //whilst there is still information in the input file it will continue to grab data from the file.
		{
		 
				getline(inputfile, OrgRecCall.name); // store name 
				getline(inputfile, OrgRecCall.occupation); // store occupation data
				getline(inputfile, OrgRecCall.department); //store department data

				OrganisationRecords.push_back(OrgRecCall); //push data into vector

		}
			

	}
	inputfile.close();


}


void PayrollProcessing::loadHRRecords(string filename)
{
		string line; //reads the current line for storage
		HRRecord HrRecCall;// for all information you want to get out	//create integer employee number

	inputfile.open(filename);  //open the chosen file
	if (!inputfile) //if there is no input file then...
	{
		cout << "Error! File " << filename << "could not be found!" << endl; //...error is printed out 

	}
	else {



		while  (getline(inputfile, line)) //while there is data in the file
		{
	
			getline(inputfile, HrRecCall.address); //store address
			getline(inputfile, HrRecCall.phonenumber); //read salary data
			getline(inputfile, HrRecCall.ninumber); //store ninumber

			HRRecords.push_back(HrRecCall); //push the data into the vector

		}


	}
	inputfile.close();


}

void PayrollProcessing::loadPayrollRecords(string filename)
{

	string line;  //reads the current line for storage
	string salary; //salary needs to be a string right now so you can change it into double later using stod
	PayrollRecord PayRecCall; //an object for vector storage on PayrollRecords
	inputfile.open(filename);  //open the chosen file



	if (!inputfile) //if there is no input file then...
	{
		cout << "Error! File " << filename << "could not be found!" << endl; //...error is printed out 

	}
	else {


		while (getline(inputfile, line)) //while the file still has data
		{
			getline(inputfile, PayRecCall.ninumber); //store ninumber
			getline(inputfile, salary); //read salary data
			PayRecCall.salary = stod(salary); //store string inside class variable as a double

			PayrollRecords.push_back(PayRecCall); //push the data into the vector

		}


	}
	inputfile.close();


}

void PayrollProcessing::displayEmployeeOfSalaryGTE(double salary) //processing and outputs all records in salary
{
	for (int count = 0; count < PayrollRecords.size(); count++)
	{
		if (PayrollRecords[count].salary >= salary) //if the persons salary is greater than or equal to 20000
		{
			cout << " Name : " << OrganisationRecords[count].name << endl; //display name
			cout << " Address : " << HRRecords[count].address << endl; //display address
			cout << " Department: " << OrganisationRecords[count].department << endl; //display department
			cout << " Salary : " << PayrollRecords[count].salary << endl; //display salary
			cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; // splits up each individual
		}
	}

}

int main(void) 
{
	PayrollProcessing Result; //creates an object "result" for payrollprocessing 
	Result.loadOrganisationRecords("organisation.txt"); //calls loadOrganisationRecords function and opens the text file 
	Result.loadHRRecords("hr.txt"); //calls loadHRRecords function and opens the text file
	Result.loadPayrollRecords("payroll.txt");  //calls loadPayrollRecords function and opens the text file

	Result.displayEmployeeOfSalaryGTE(20000);

	return 0;
}