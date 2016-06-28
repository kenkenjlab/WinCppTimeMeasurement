/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _STOPWATCH_TIMEGETTIME_HPP_
#define _STOPWATCH_TIMEGETTIME_HPP_ 2016062801

#include "stopwatch.hpp"
#include <windows.h>
#pragma comment(lib, "winmm.lib")

class StopwatchTimeGetTime : public Stopwatch {
private:
	DWORD time_begin_;

public:
	StopwatchTimeGetTime() {}
	~StopwatchTimeGetTime() {}

	void start() {
		time_begin_ = timeGetTime();
	}

	double stop() {
		return static_cast<double>(timeGetTime() - time_begin_);
	}
};


#endif