// TrafficSimulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include "windows.h"
#include <ctime>
#include "conio.h"
#include "Sim.h"
#include "Clock.h"
#include "Light.h"

int main()
{
	bool exit = false;

	//create sim object
	Sim sim;
	Clock grandfatherClock;
	int counter = 1;
	Light light(10, 2, 5, &grandfatherClock);



	do {
		//sim.clearConsole();
		sim.writeToConsole(10, 20, "                           \n               \n               \n");
		sim.writeToConsole(10, 20, light.debugOutput());
		
		grandfatherClock.tock();
		light.updateState();
			//program execution
			//sim.writeToConsole(10, 20, "this is another test " + counter);
		counter++;
 


	} while (!exit);




	//great way to pause execution
	while (1)
	{
		if (getchar())
			break;
	}
	return 0;
}

