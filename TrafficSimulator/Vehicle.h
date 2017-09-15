#pragma once
#include "Agent.h"
#include "Light.h"

class Agent;
class Light;

class Vehicle : public Agent
{
public:
	Vehicle();
	
	Vehicle(Light *l1, Light *l2, int carID);
	~Vehicle();
	enum State
	{
		Stop,
		Go
	};
	bool firstLightPassed;
	bool secondLightPassed;
	Light *Light1;
	Light *Light2;
	State CurrentState;
	int carID;
	

	bool canMove;
	void changeState();
	void update();


};

