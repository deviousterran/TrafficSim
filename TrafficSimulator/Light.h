#pragma once
#include "Agent.h"
class Light :
	public Agent
{
public:
	Light();
	~Light();
	int currentState;
	enum Color {green, yellow, red};
	Color lightColor;
	



};

