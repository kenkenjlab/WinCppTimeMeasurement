/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _STOPWATCH_PCLTICTOC_HPP_
#define _STOPWATCH_PCLTICTOC_HPP_ 2016062801

#include "stopwatch.hpp"
#include <pcl/console/time.h>

class StopwatchPCLTicToc : public Stopwatch {
private:
	pcl::console::TicToc meter_;

public:
	StopwatchPCLTicToc() {}
	~StopwatchPCLTicToc() {}

	void start() {
		meter_.tic();
	}

	double stop() {
		return meter_.toc();
	}
};


#endif