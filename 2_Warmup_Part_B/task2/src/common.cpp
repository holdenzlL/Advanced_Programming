#include "common.h"
common::timer::timer() {
	_start = std::chrono::system_clock::now();
}
double common::timer::time()
{
	this->_end = std::chrono::system_clock::now();
	_diff = _end - _start;
	return _diff.count();
}
void common::timer::reset()
{
	_start = std::chrono::system_clock::now();
}
void common::timer::display()
{
	std::ios oldState(nullptr);
	oldState.copyfmt(std::cout);	// save the state of std cout

	std::cout << std::fixed << std::setprecision(9) << std::left;
	std::cout << this->time() << std::endl;

	std::cout.copyfmt(oldState);	// restore the state of std cout
}