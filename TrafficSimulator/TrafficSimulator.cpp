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


void updateConsole();
void updateRoadway(std::vector<Vehicle> &road);

Sim sim;
Clock grandfatherClock;
Light light1(10, 2, 5, &grandfatherClock);
Light light2(15, 3, 8, &grandfatherClock);
int vehicleCounter = 1;
int counter = 21;
int spawntimer = 3;
double vehicleTick = 0.5;
bool roadway[18];

int main()
{
	bool exit = false;
	bool recentspawn = false;
	std::vector<Vehicle> queue;
	std::vector<Vehicle> onRoadway;
	for (int i = 0; i < sizeof(roadway); i++)
	{
		roadway[i] = false;
	}
	roadway[2] = true;
	roadway[5] = true;
	roadway[7] = true;


	updateConsole();
	do {

		//for vehicle spawning
		if (clock() / 1000 == spawntimer)
		{
			queue.push_back(Vehicle(&light1, &light2, vehicleCounter));
			vehicleCounter++;
			spawntimer = spawntimer + 3;
			updateConsole();
		}
		if (clock() / 1000 == vehicleTick)
		{
			if (!queue.empty() && !roadway[0] && light1.lightColor == Light::green )
			{
				
				Vehicle temp = queue.front();
				queue.erase(queue.begin());
				temp.position = 1;
				onRoadway.push_back(temp);
			}
			updateRoadway(onRoadway);

		}

		if (light1.updateState()) {
			updateConsole();
		}
		if (light2.updateState()) {
			updateConsole();
		}


	} while (!exit);




	//great way to pause execution
	while (1)
	{
		if (getchar())
			break;
	}
	return 0;
}

void updateConsole() {
	sim.clearConsole();
	sim.writeToConsole(1, 1, "time index:" + std::to_string(clock()));
	sim.writeToConsole(1, 2, "number of cars spawned:" + std::to_string(vehicleCounter));
	sim.writeToConsole(1, 3, "spawntimer:" + std::to_string(spawntimer));

	sim.writeToConsole(10, 20, light1.reportState());
	sim.writeToConsole(10, 40, light2.reportState());
	for (int i = 0; i < sizeof(roadway); i++)
	{
		if (roadway[i])
		{
			sim.writeToConsole(10, 21+i, "@");
		}
	}

}

void updateRoadway(std::vector<Vehicle> &road) {
	for (int i = 0; i < road.size; i++)
	{

	}

	for (int i = 0; i < sizeof(roadway); i++)
	{
		for (int i = 0; i < road.size; i++)
		{
			if (road.at(i).position = roadway[i])
			{
				roadway[i] = true; // this shows that there is a car on the roadway
			}
		}


	}
}