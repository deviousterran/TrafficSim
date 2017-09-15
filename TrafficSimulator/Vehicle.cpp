#include "stdafx.h"
#include "Vehicle.h"
#include "Light.h"

//states:
//stopped
//stopping
//accelerating
//moving


Vehicle::Vehicle()
{
	position = 0;

}


Vehicle::~Vehicle()
{
}


Vehicle::Vehicle(Light *l1, Light *l2, int carID) {
	bool firstLightPassed = false;
	bool secondLightPassed = false;
	Vehicle::carID = carID;
	position = 0;

}

void Vehicle::swap(Vehicle input) {

}

void Vehicle::changeState() {

	switch (CurrentState)
	{
	case Vehicle::Stop:
		if (!firstLightPassed)
		{
			if (Light1->lightColor == Light::green && canMove)
			{
				CurrentState = Go;
				position++;
			}

		}

		if (firstLightPassed && !secondLightPassed && canMove)
		{
			if (Light2->lightColor = Light::green)
			{
				CurrentState = Go;
				position++;
			}
		}
		break;
	case Vehicle::Go:
		if (Light2->lightColor == Light::red || Light2->lightColor == Light::yellow || !canMove  && firstLightPassed)
		{
			CurrentState = Stop;
		}

		if (!canMove)
		{
			CurrentState = Stop;
		}

		break;

	default:
		break;
	}
	
	
	



}


void Vehicle::update() {

}