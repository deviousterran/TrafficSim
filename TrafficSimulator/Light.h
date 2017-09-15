#pragma once
#include "Agent.h"
#include <iostream>
#include "Clock.h"
#include <string>

class Clock;

class Light : public Agent
{
public:
	Light();
	Light(double greenTime, double yellowTime, double redTime, Clock *plocalClock);
	~Light();
	int currentState;
	enum Color {green, yellow, red};
	Color lightColor;
	double yellowTime;
	double greenTime;
	double redTime;
	double timerStart;
	Clock *pLocalClock;
	double updateRate;//in seconds passed from the clock object during construction

	std::string debugOutput();//returns a string of class variables for easy printing

	std::string reportState();
	bool updateState();



};

