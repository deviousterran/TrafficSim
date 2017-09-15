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
#include "Vehicle.h"
#include <vector>

int main()
{
	bool exit = false;

	//create sim object
	Sim sim;
	Clock grandfatherClock;
	int vehicleCounter = 1;
	int counter = 21;
	Light light1(10, 2, 5, &grandfatherClock);
	Light light2(15, 3, 8, &grandfatherClock);
	int spawntimer = 3;
	bool recentspawn = false;
	int roadway[20];
	//
	std::vector<Vehicle> queue;

	sim.writeToConsole(10, 20, light1.reportState());
	sim.writeToConsole(10, 40, light2.reportState());
	do {
		sim.writeToConsole(1, 1, "time index:" + std::to_string(clock()));
		sim.writeToConsole(1, 2, "number of cars spawned:" + std::to_string(vehicleCounter));
		sim.writeToConsole(1, 3, "spawntimer:" + std::to_string(spawntimer));

		sim.writeToConsole(10, 20, light1.reportState());
		sim.writeToConsole(10, 40, light2.reportState());

		//grandfatherClock.tock();
		if (clock() / 1000 == spawntimer)
		{
			sim.clearConsole();
			queue.push_back(Vehicle(&light1, &light2, vehicleCounter));
			vehicleCounter++;
			sim.writeToConsole(1, 2, "number of cars spawned:" + std::to_string(vehicleCounter));
			spawntimer = spawntimer + 3;
			sim.writeToConsole(1, 3, "spawntimer:" + std::to_string(spawntimer));
		}



		if (light1.updateState()) {
			sim.clearConsole();
			sim.writeToConsole(10, 20, light1.reportState());
			sim.writeToConsole(10, counter, "@");
		}
		if (light2.updateState()) {
			sim.clearConsole();
			sim.writeToConsole(10, 40, light2.reportState());
			sim.writeToConsole(10, counter, "@");
		}

		//only update the screen if the state of the light changes





		
 


	} while (!exit);




	//great way to pause execution
	while (1)
	{
		if (getchar())
			break;
	}
	return 0;
}

