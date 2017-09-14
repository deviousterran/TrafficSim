#pragma once
#include "Agent.h"

class Agent;

class Vehicle : public Agent
{
public:
	Vehicle();
	~Vehicle();
	int maxSpeed;
	int acceleration;
	int deceleration;
	void changeState();

};

