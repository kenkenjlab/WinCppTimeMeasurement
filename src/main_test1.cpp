/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#include "stopwatch_chrono.hpp"
#include "stopwatch_clock.hpp"
#include "stopwatch_gettickcount.hpp"
#include "stopwatch_cvtickmeter.hpp"
#include "stopwatch_pcltictoc.hpp"
#include "stopwatch_queryperformance.hpp"
#include "stopwatch_timegettime.hpp"
#include "log_utility.hpp"

void wait(double millisec) {
#ifdef WAIT_PRECISELY
	StopwatchQueryPerformance stw_q;
	stw_q.start();
	while (stw_q.stop() <= millisec);
#else
	Sleep(millisec);
#endif
}

int main(int argc, char** argv) {
	typedef std::vector<std::pair<std::string, std::shared_ptr<Stopwatch> > > NamedStopwatchVec;
	LogUtility::LogMap log_map;
	NamedStopwatchVec stw_vec;
	stw_vec.push_back(std::make_pair("1_Chrono", std::shared_ptr<Stopwatch>(new StopwatchChrono)));
	stw_vec.push_back(std::make_pair("2_Clock", std::shared_ptr<Stopwatch>(new StopwatchClock)));
	stw_vec.push_back(std::make_pair("3_GetTickCount", std::shared_ptr<Stopwatch>(new StopwatchGetTickCount)));
	stw_vec.push_back(std::make_pair("4_TimeGetTime", std::shared_ptr<Stopwatch>(new StopwatchTimeGetTime)));
	stw_vec.push_back(std::make_pair("5_CvTickMeter", std::shared_ptr<Stopwatch>(new StopwatchCvTickMeter)));
	stw_vec.push_back(std::make_pair("6_PCLTicToc", std::shared_ptr<Stopwatch>(new StopwatchPCLTicToc)));
	stw_vec.push_back(std::make_pair("7_QueryPerformance", std::shared_ptr<Stopwatch>(new StopwatchQueryPerformance)));

	std::vector<double> ms_vec;
	ms_vec.push_back(1.0);
	ms_vec.push_back(5);
	ms_vec.push_back(10);
	ms_vec.push_back(11);
	ms_vec.push_back(12);
	ms_vec.push_back(1000);

	for (std::vector<double>::const_iterator cit_ms = ms_vec.begin(); cit_ms != ms_vec.end(); ++cit_ms) {
		const double ms = *cit_ms;
		log_map["0_TimerValue"].push_back(*cit_ms);

		for (NamedStopwatchVec::iterator it_stw = stw_vec.begin(); it_stw != stw_vec.end(); ++it_stw) {
			const std::string &name = it_stw->first;
			std::shared_ptr<Stopwatch> stw = it_stw->second;
		
			stw->start();
			wait(ms);
			double erapsed_ms = stw->stop();
			log_map[name].push_back(erapsed_ms);
			std::printf("%s:\t%f[ms]\tWaited: %f[ms]\tDiff: %f[ms]\n", name.c_str(), erapsed_ms, ms, (erapsed_ms - ms));
		}
		std::cout << std::endl;
	}
	
	LogUtility::save("./results.csv", log_map);

	return 0;
}