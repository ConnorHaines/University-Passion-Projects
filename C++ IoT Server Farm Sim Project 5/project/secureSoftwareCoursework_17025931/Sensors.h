#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <string>
#include <random>

using namespace std;



class Sensors
{
public:
	virtual void process(uint16_t value) {};


private:
	uint16_t lastValue = 0;
	uint16_t currentValue = 0;

};

class TemperatureSensor
{
public:
	void genValue();
	void process(uint16_t value);


private:
	uint16_t lastValue = 0;
	uint16_t currentValue = 0;
	uint16_t thetryguys = 0;
};




class HumiditySensor
{
public:
	void genValue();
	void process(uint16_t value);




private:
	uint16_t lastValue = 0;
	uint16_t currentValue = 0;
	uint16_t smosh = 0;

};



class VoltageSensor
{
public:
	void genValue();
	void process(uint16_t value) ;



private:
	uint16_t lastValue = 0;
	uint16_t currentValue = 0;
	uint16_t buzzfeedunsolved = 0;

};


#endif // !SENSOR_H
