#pragma once
#include <chrono>	// for timer
#include <iostream>
#include <iomanip>
namespace common {
class timer
{
public:
	timer();			// constructor, but also start the timer
	double time();		// return the value of the timer now
	void reset();		// reset the timer	
	void display();		// display the value of timer, and append a \n

private:
	std::chrono::time_point<std::chrono::system_clock> _start;
	std::chrono::time_point<std::chrono::system_clock> _end;
	std::chrono::duration<double> _diff;
};
}
