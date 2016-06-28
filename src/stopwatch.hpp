/*
 Copyright (c) 2016 kenken
 This software is released under the MIT License.
*/

#ifndef _STOPWATCH_HPP_
#define _STOPWATCH_HPP_ 2016062801

class Stopwatch {
public:
	Stopwatch() {}
	virtual ~Stopwatch() {};
	virtual void start() {};
	virtual double stop() { return -1.0; }		// Returns in [ms]
};

#endif