#pragma once
class Clock
{
public:
	Clock();
	~Clock();
	unsigned int timeElapsed;
	
	
	void advanceTime();
	void advanceEntity();
	void start();

	double tickStart;
	double tickEnd;

	void tock();

	void setClockSpeed(double speed) { clockSpeed = speed; };
	double getClockSpeed() { return clockSpeed; };
	
private:
	double clockSpeed;




};

