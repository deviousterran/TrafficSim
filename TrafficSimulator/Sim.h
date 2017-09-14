#pragma once
#include <vector>
#include <chrono>
#include "windows.h"
#include <ctime>
#include "conio.h"
#include <iostream>
#include <string>


class Vehicle;
class Light;

class Sim
{
public:
	Sim();
	~Sim();
	const int x = 12;
	const int y = 25;


	long startTime;
	long endTime;
	std::vector<Vehicle> vehcileSpawner;

	Vehicle spawnVehicle();
	//char console[][];

	void createWindow();
	void ShowConsoleCursor(bool showFlag);
	void setCursorTo(int x, int y);
	void writeToConsole(int x, int y, std::string text);
	void clearConsole();

};

