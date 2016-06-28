/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _STOPWATCH_GETTICKCOUNT_HPP_
#define _STOPWATCH_GETTICKCOUNT_HPP_ 2016062801

#include "stopwatch.hpp"
#include <windows.h>

class StopwatchGetTickCount : public Stopwatch {
private:
	DWORD time_begin_;

public:
	StopwatchGetTickCount() {}
	~StopwatchGetTickCount() {}

	void start() {
		time_begin_ = GetTickCount();
	}

	double stop() {
		return static_cast<double>(GetTickCount() - time_begin_);
	}
};


#endif