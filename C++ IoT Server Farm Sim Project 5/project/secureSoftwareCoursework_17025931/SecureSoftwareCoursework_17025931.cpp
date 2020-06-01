#include <iostream>
#include "Sensors.h"
#include <windows.h>
#include <fstream>
#include "Authenticator.h"
#include "Logger.h"

uint16_t adminMenu();

void readFile(string sensor, string fileName, string sign)
{
	cout << sensor << ":\n-------------------------------\n";
	uint16_t readout = 0;
	string line;
	ifstream myfile(fileName);
	if (myfile.fail()) {
		cout << "File could not be loaded!\n";
		system("PAUSE");
	}
	else {
		while (getline(myfile, line)) {
			cout << "Readout " << readout + 1 << ": " << line << sign << "\n";
			readout++;
		}
		myfile.close();
		cout << "\n";
		system("PAUSE");
		adminMenu();
	}
}


using namespace std;
//User userObject;
//User loggingfile;

const uint16_t Menu_Quit = 3;




void showTempSensors() {
	system("cls");
	cout << "	Temperature Sensors:	\n";
	cout << "	-----------------------	\n";

	TemperatureSensor tmp_sns;
	

	bool exit = false;

	while (!exit) {
		tmp_sns.genValue();


		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit = true;
			adminMenu();
		}

	}

}

void showHumidSensors() {

	system("cls");
	cout << "	Humidity Sensors:	\n";
	cout << "	-----------------------	\n";
	HumiditySensor hmd_sns;

	bool exit = false;

	while (!exit) {

		hmd_sns.genValue();

		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit = true;
			adminMenu();
		}

	}

}

void showVoltSensors() {

	system("cls");
	cout << "	Voltage Sensors:	\n";
	cout << "	-----------------------	\n";

	VoltageSensor vlt_sns;

	bool exit = false;

	while (!exit) {

		vlt_sns.genValue();

		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit = true;
			adminMenu();
		}

	}

}

uint16_t adminMenu() {
	uint16_t sensorChoice;
	uint16_t adminInput = 0;

	system("cls");
	cout << "	_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
	cout << "	|	What would you like to do?			|\n";
	cout << "	|	--------------------------			|\n";
	cout << "	|	1: View Temperature Sensor Output		|\n";
	cout << "	|	2: View Humidity Sensor Output			|\n";
	cout << "	|	3: View Voltage Sensor Output			|\n";
	cout << "	|	4: Read Data					|\n";
	cout << "	|	5: Return to Main Menu				|\n";

	cout << "	_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
	cout << "		Your Choice: ";
	cin >> adminInput;

	switch (adminInput) {

	case 1:
		showTempSensors();
		break;
		system("PAUSE");
	case 2: showHumidSensors();
		break;
		system("PAUSE");
	case 3: showVoltSensors();
		break;
		system("PAUSE");
	case 4:
		system("cls");
		cout << "Read Data:\n-----------------------------------------\n";
		cout << "1)Temperature\n2)Humidity\n3)Voltage\nWhich sensor would you like to see data from?\n";
		cin >> sensorChoice;
		system("cls");
		if (sensorChoice == 1) {
			string fileName = "TemperatureSensor.txt";
			readFile("Temperature", fileName, "'c");
			
		}
		else if (sensorChoice == 2) {
			string fileName = "HumiditySensor.txt";
			readFile("Humidity", fileName, "%");
		}
		else if (sensorChoice == 3) {
			string fileName = "VoltageSensor.txt";
			readFile("Voltage", fileName, "%");
		}
		else {
			cout << "invalid choice\n";
			system("PAUSE");
			adminMenu();
		}


		break;

	case 5: cout << "Returning you to main menu, please wait a second...";
		Sleep(2000);
		adminMenu();
		break;
		

	default:

		break;
	}

	cin.clear();
	cin.ignore();


	return 0;

}



uint16_t mainMenu() {
	//read input, as long as it isn't exit, then display choice
	uint16_t input = 0;


	system("cls");
	cout << "	_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
	cout << "	|	Welcome to the Haiking Server Farm!		|\n";
	cout << "	|	Select from the following options		|\n";
	cout << "	|	----------------------------------------	|\n";
	cout << "	|	1: Information about the Server Farm		|\n";
	cout << "	|	2: Log-in					|\n";
	cout << "	|	3: Quit						|\n";
	cout << "	_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
	cout << "		Your Choice : ";


	cin >> input;

	Subject* s = nullptr;
	ProofofID *proofofID;
	Authenticator* a = nullptr;
	switch (input) {

	case 1:
		system("cls");
		cout << "	_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
		cout << "	|	Our server farm or server cluster		|\n";
		cout << "	|	is a collcetion of computer servers		|\n";
		cout << "	|	maintained by Haiking to supply server  	|\n";
		cout << "	|	functionality far beyond the capability		|\n";
		cout << "	|	of a single machine. 				|\n";
		cout << "	_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n\n\n";

		system("pause");
		break;


	case 2:
		system("cls");
		s = new Subject;
		a = new Authenticator;
		proofofID = a->authenticateUser(*s);
		if (proofofID != nullptr) {
			cout << "subject proof of id" << s->getproofofID() << endl;
			cout << "system proof of id" << proofofID->getproofID() << endl;
			system("PAUSE");

			adminMenu();
		}

		break;

	case 3:
		input = 3;
		break;

	default:

		break;


	}
	cin.clear();
	cin.ignore();

	delete s;
	delete a;
	return input;


}

void startup() {
	cout << "Starting system...\n";
	Sleep(2000);
	cout << "\nInitializing users...\n";
	//load user

	Sleep(2000);
	cout << "\nInitiating Logger...\n";
	//load logger
	Sleep(2000);
	cout << "\nInitiating Sensor 1...\n";
	//load sensor 1
	Sleep(2000);
	cout << "\nInitiating Sensor 2...\n";
	//load sensor 2
	Sleep(2000);
	cout << "\nInitiating Sensor 3...\n";
	//load sensor 3
	Sleep(2000);
	cout << "\nSystem Startup Complete\n";
	Sleep(1000);
	system("PAUSE");
}

int main()
{

	startup();


	uint16_t ui8userChoice = 0;

	while (ui8userChoice != Menu_Quit)
	{
		ui8userChoice = mainMenu();
	}
	
	system("cls");
	cout << "Thank you, Goodbye!! \n";
	Sleep(2000);

}