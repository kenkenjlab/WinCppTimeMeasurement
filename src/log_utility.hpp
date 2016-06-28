/*
Copyright (c) 2016 kenken
This software is released under the MIT License.
*/

#ifndef _LOG_UTILITY_
#define _LOG_UTILITY_ 2016062801

#include <map>
#include <string>
#include <vector>
#include <fstream>

class LogUtility {
public:
	typedef std::string Key;
	typedef double Value;
	typedef std::vector<Value> ValueVec;
	typedef std::map<Key, ValueVec> LogMap;
	static void save(const std::string &output_path, const LogMap &log_map) {
		std::ofstream ofs(output_path);
		for (LogMap::const_iterator cit_logmap = log_map.begin(); cit_logmap != log_map.end(); ++cit_logmap) {
			const Key &key = cit_logmap->first;
			const ValueVec &value_vec = cit_logmap->second;

			ofs << key;
			for (ValueVec::const_iterator cit_valvec = value_vec.begin(); cit_valvec != value_vec.end(); ++cit_valvec) {
				ofs << "," << *cit_valvec;
			}

			ofs << std::endl;
		}
		ofs.close();
	}
};

#endif