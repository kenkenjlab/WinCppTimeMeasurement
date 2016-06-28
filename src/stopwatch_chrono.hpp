/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _STOPWATCH_CHRONO_HPP_
#define _STOPWATCH_CHRONO_HPP_ 2016062801

#include "stopwatch.hpp"
#include <chrono>

class StopwatchChrono : public Stopwatch {
private:
	std::chrono::system_clock::time_point time_begin_;

public:
	StopwatchChrono() {}
	~StopwatchChrono() {}

	virtual void start() {
		time_begin_ = std::chrono::system_clock::now();
	}

	virtual double stop() {
		std::chrono::system_clock::time_point time_end = std::chrono::system_clock::now();
		return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin_).count());
	}
};


#endif