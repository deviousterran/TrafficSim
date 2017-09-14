#include "stdafx.h"
#include "Clock.h"
#include <ctime>
#include <thread>
#include <chrono>


Clock::Clock()
{
	//set clock tick to .5 seconds
	setClockSpeed(.5);
	tickStart = clock();
}


Clock::~Clock()
{
}


void Clock::advanceTime() {
	//whatever whatever advance time or something.  Am i right????
	tickStart = clock();
	tickEnd = tickStart + (clockSpeed * 1000);
}

void Clock::tock() {
	tickStart = clock();
	tickEnd = tickStart + (clockSpeed * 1000);
}

void Clock::advanceEntity() {
	//sends a signal to advance a entity;  possibly to all children??


}