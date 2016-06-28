/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _STOPWATCH_CLOCK_HPP_
#define _STOPWATCH_CLOCK_HPP_ 2016062801

#include "stopwatch.hpp"
#include <ctime>

class StopwatchClock : public Stopwatch {
private:
	std::clock_t time_begin_;

public:
	StopwatchClock() {}
	~StopwatchClock() {}

	void start() {
		time_begin_ = std::clock();
	}

	double stop() {
		return static_cast<double>(clock() - time_begin_) * 1000 / CLOCKS_PER_SEC;
	}
};


#endif