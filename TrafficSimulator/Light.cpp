#include "stdafx.h"
#include "Light.h"



Light::Light()
{
	lightColor = green;
	

}

Light::Light(double lenOfGreenTime, double lenOfyellowTime, double lenOfredTime, Clock *plocalClock) {
	greenTime = lenOfGreenTime*1000;
	yellowTime = lenOfyellowTime * 1000;
	redTime = lenOfyellowTime * 1000;
	lightColor = green;
	timerStart = clock();
	pLocalClock = plocalClock;
}

Light::~Light()
{
}

void Light::updateState() {
	

	switch (lightColor)
	{
	case Light::green:
		if (greenTime + timerStart < clock())
		{
			lightColor = yellow;
			timerStart = clock();
		}
		break;
	case Light::yellow:
		if (yellowTime + timerStart < clock())
		{
			lightColor = red;
			timerStart = clock();
		}
		break;
	case Light::red:
		if (redTime + timerStart < clock())
		{
			lightColor = green;
			timerStart = clock();
		}
		break;
	default:
		break;
	}
}


std::string Light::reportState() {
	switch (lightColor)
	{
	case Light::green:
		return "GREEN";
		break;
	case Light::yellow:
		return "YELLOW";
		break;
	case Light::red:
		return "RED";
		break;
	default:
		break;
	}
}


std::string Light::debugOutput() {

	return "update counter:" + std::to_string(timerStart) + "\nupdate rate:" + std::to_string(clock())
		+ "\n" + reportState()
		+ "\nGreen time:" + std::to_string(greenTime);

}

//get beginning time index
//calculate time index till state change
//change state
//report changed state

