#pragma once
#include <vector>
#include "Vehicle.h"


class Sim
{
public:
	Sim();
	~Sim();
	long startTime;
	long endTime;
	std::vector<Vehicle> vehcileSpawner;

	Vehicle spawnVehicle();




};

