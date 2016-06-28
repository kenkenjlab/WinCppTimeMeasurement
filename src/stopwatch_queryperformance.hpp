/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _STOPWATCH_QUERYPERFORMANCE_HPP_
#define _STOPWATCH_QUERYPERFORMANCE_HPP_ 2016062801

#include "stopwatch.hpp"
#include <windows.h>

class StopwatchQueryPerformance : public Stopwatch {
private:
	LARGE_INTEGER freq_, time_begin_, time_end_;

public:
	StopwatchQueryPerformance() {}
	~StopwatchQueryPerformance() {}

	void start() {
		QueryPerformanceFrequency(&freq_);
		QueryPerformanceCounter(&time_begin_);
	}

	double stop() {
		QueryPerformanceCounter(&time_end_);
		return static_cast<double>(time_end_.QuadPart - time_begin_.QuadPart) / freq_.QuadPart * 1000;
	}
};


#endif