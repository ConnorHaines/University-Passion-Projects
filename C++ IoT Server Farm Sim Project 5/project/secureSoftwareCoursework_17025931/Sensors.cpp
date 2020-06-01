#include "Sensors.h"
#include <Windows.h>
#include "Logger.h"

void basicLogger(int sensorData, string fileName) {
	ofstream myfile;
	myfile.open(fileName, ios::app);

	if (myfile.fail()) {
		cout << "File could not be opened!\n";
		system("PAUSE");
	}
	else {
		myfile << sensorData << "\n";
		myfile.close();
	}
}

void TemperatureSensor::genValue() {

	int16_t generatedValue = 0;
	string fileName = "TemperatureSensor.txt";
	string sign = "'C";
	system("cls");
	uint16_t logData = 0;
	cout << "Would you like to log the data from this session? (Y = 1, N = 2)\n";
	cin >> logData;
	system("cls");

	if (logData == 1) {
		cout << "This data is being logged!\n------------------------------\n";
	}
	while (thetryguys < 10)
	{



		random_device rd;
		mt19937 RNG(rd());
		uniform_int_distribution<int16_t> UD(20, 25);
		generatedValue = UD(RNG);

		while (generatedValue > INT16_MAX || generatedValue < INT16_MIN) {
			generatedValue = UD(RNG);
		}
		cout << generatedValue << endl;

		thetryguys++;
		if (logData == 1) {
			basicLogger(generatedValue, fileName);
		}
		Sleep(200);
	}

	if (thetryguys == 10) {
		cout << "The temperature is relatively stable. Turning off the fans\n";
		while (thetryguys < 25) {
			random_device rd;
			mt19937 RNG(rd());
			uniform_int_distribution<int16_t> UD(35, 50);
			generatedValue = UD(RNG);

			while (generatedValue > INT16_MAX || generatedValue < INT16_MIN) {
				generatedValue = UD(RNG);
			}
			cout << generatedValue << endl;

			thetryguys++;
			if (logData == 1) {
				basicLogger(generatedValue, fileName);
			}
			Sleep(200);
		}
	}




	lastValue = currentValue;
	currentValue = generatedValue;
	process(generatedValue);



}

void TemperatureSensor::process(uint16_t) {

	if (thetryguys == 25) {
		cout << "The servers are getting pretty hot; turning the fans on...\n";
		cout << "Cooling down the servers.. please wait a few seconds\nOtherwise, press Esc to exit!\n" << endl;
		Sleep(5000);
		cout << "Fans are now cool; logging restarting\n";

		thetryguys = 0;
	}


}

//--------------------------------------------------------------------------------------------------------------------------


void HumiditySensor::genValue() {

	int16_t generatedValue = 0;
	string fileName = "HumiditySensor.txt";
	string sign = "'C";
	system("cls");
	uint16_t logData = 0;
	cout << "Would you like to log the data from this session? (Y = 1, N = 2)\n";
	cin >> logData;
	system("cls");

	if (logData == 1) {
		cout << "This data is being logged!\n------------------------------\n";
	}




	while (smosh < 15)
	{

		random_device rd;
		mt19937 RNG(rd());
		uniform_int_distribution<int16_t> UD(25, 50);
		generatedValue = UD(RNG);

		while (generatedValue > INT16_MAX || generatedValue < INT16_MIN) {
			generatedValue = UD(RNG);
		}
		cout << generatedValue << endl;

		smosh++;
		if (logData == 1) {
			basicLogger(generatedValue, fileName);
		}
		Sleep(200);
	}

	if (smosh == 15) {
		cout << "The humidity in the server farm is fluctuating too regularly. Turning on dehumidifier...\n";
		while (smosh < 40) {
			random_device rd;
			mt19937 RNG(rd());
			uniform_int_distribution<int16_t> UD(0, 5);
			generatedValue = UD(RNG);

			while (generatedValue > INT16_MAX || generatedValue < INT16_MIN) {
				generatedValue = UD(RNG);
			}
			cout << generatedValue << endl;

			smosh++;
			if (logData == 1) {
				basicLogger(generatedValue, fileName);
			}
			Sleep(200);
		}
	}




	lastValue = currentValue;
	currentValue = generatedValue;
	process(generatedValue);



}

void HumiditySensor::process(uint16_t) {

	if (smosh == 40) {
		cout << "The humidity is pretty stable, turning off dehumidifier\n";
		cout << "Turning dehumidifier off. Please wait a few seconds...\nOtherwise, press Esc to exit!\n" << endl;
		Sleep(5000);
		cout << "Dehumidifier off; logging restarting\n";

		smosh = 0;
	}


}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

void VoltageSensor::genValue() {

	int16_t generatedValue = 0;
	string fileName = "VoltageSensor.txt";
	string sign = "'C";
	system("cls");
	uint16_t logData = 0;
	cout << "Would you like to log the data from this session? (Y = 1, N = 2)\n";
	cin >> logData;
	system("cls");

	if (logData == 1) {
		cout << "This data is being logged!\n------------------------------\n";
	}




	while (buzzfeedunsolved < 10)
	{

		random_device rd;
		mt19937 RNG(rd());
		uniform_int_distribution<int16_t> UD(230, 232);
		generatedValue = UD(RNG);

		while (generatedValue > INT16_MAX || generatedValue < INT16_MIN) {
			generatedValue = UD(RNG);
		}
		cout << generatedValue << endl;

		buzzfeedunsolved++;
		if (logData == 1) {
			basicLogger(generatedValue, fileName);
		}
		Sleep(200);
	}

	if (buzzfeedunsolved == 10) {
		cout << "The fans have been turned off. Voltage will be slightly lower.\n";
		while (buzzfeedunsolved < 25) {
			random_device rd;
			mt19937 RNG(rd());
			uniform_int_distribution<int16_t> UD(200, 203);
			generatedValue = UD(RNG);

			while (generatedValue > INT16_MAX || generatedValue < INT16_MIN) {
				generatedValue = UD(RNG);
			}
			cout << generatedValue << endl;

			buzzfeedunsolved++;
			if (logData == 1) {
				basicLogger(generatedValue, fileName);
			}
			Sleep(200);
		}
	}




	lastValue = currentValue;
	currentValue = generatedValue;
	process(generatedValue);



}

void VoltageSensor::process(uint16_t) {

	if (buzzfeedunsolved == 25) {
		cout << "The fans are being turned on. Voltage will be higher.\n";
		cout << "Fans are slowly being turned on. Voltage rising...\nPlease wait a few seconds...\nOtherwise, press Esc to exit!\n\n" << endl;
		Sleep(5000);
		cout << "Fans are now on. Voltage stable.\n";

		buzzfeedunsolved = 0;
	}


}