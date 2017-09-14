#pragma once
#include "Sim.h"



//agent class is the base class for the lights and vehicles so i only have to build messaging and state changes once.  I hate re-typing code!!!
class Agent : public Sim
{
public:
	Agent();
	~Agent();

	//void changeState();
	void sendMessage();
	void receiveMessage(int &message);//receive a enumerated message and react to it.
};

