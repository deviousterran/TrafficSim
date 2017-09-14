#include "stdafx.h"
#include "Sim.h"
#include "Vehicle.h"
#include "windows.h"


Sim::Sim()
{
	createWindow();
	ShowConsoleCursor(false);
	//console[x][y];

}


Sim::~Sim()
{
}

void Sim::createWindow() {
	//assigns the var console to the current console window
	HWND console = GetConsoleWindow();
	//build a rectangle object
	RECT r;
	//
	GetWindowRect(console, &r);
	//sets the window to a standard size
	MoveWindow(console, r.left, r.top, 600, 800, TRUE);
}


void Sim::setCursorTo(int x, int y)
{
	HANDLE handle;
	COORD position;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(handle, position);
}

void Sim::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

Vehicle Sim::spawnVehicle() {


	Vehicle temp;
	return temp;
	//this does nothing yet!!
	

}

void Sim::writeToConsole(int x, int y, std::string text) {
	setCursorTo(x, y);
	std::cout << text;

}

void Sim::clearConsole() {
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

		// Get the Win32 handle representing standard output.
		// This generally only has to be done once, so we make it static.
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO csbi;
		COORD topLeft = { 0, 0 };

		// std::cout uses a buffer to batch writes to the underlying console.
		// We need to flush that to the console because we're circumventing
		// std::cout entirely; after we clear the console, we don't want
		// stale buffered text to randomly be written out.
		std::cout.flush();

		// Figure out the current width and height of the console window
		if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
			// TODO: Handle failure!
			abort();
		}
		DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

		DWORD written;

		// Flood-fill the console with spaces to clear it
		FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

		// Reset the attributes of every character to the default.
		// This clears all background colour formatting, if any.
		FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

		// Move the cursor back to the top left for the next sequence of writes
		SetConsoleCursorPosition(hOut, topLeft);

}