/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _STOPWATCH_CVTICKMETER_HPP_
#define _STOPWATCH_CVTICKMETER_HPP_ 2016062801

#include "stopwatch.hpp"
#include <opencv2/contrib/contrib.hpp>

class StopwatchCvTickMeter : public Stopwatch {
private:
	cv::TickMeter meter_;

public:
	StopwatchCvTickMeter() {}
	~StopwatchCvTickMeter() {}

	void start() {
		meter_.start();
	}

	double stop() {
		meter_.stop();
		return meter_.getTimeMilli();
	}
};


#endif