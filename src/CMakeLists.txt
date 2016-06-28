# Copyright (c) 2016 kenken
# This software is released under the MIT License.

#### CMake Settings ####

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
cmake_policy(SET CMP0015 OLD)	#// Do not add relative path if the designated path is not exist
add_definitions(-DUNICODE -D_UNICODE)	#// Set Unicode, not MultiBytes


#### Solution Settings ####

project(TimeMeasurement)


#### Includes and Libraries ####

find_package(PCL 1.7 REQUIRED)
find_package(OpenCV 2.4 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

#### Required files ####

set(LOG_UTILITY log_utility.hpp)

set(STOPWATCH stopwatch.hpp)
set(STOPWATCH_CLOCK stopwatch_clock.hpp ${STOPWATCH})
set(STOPWATCH_CHRONO stopwatch_chrono.hpp ${STOPWATCH})
set(STOPWATCH_TIMEGETTIME stopwatch_timegettime.hpp ${STOPWATCH})
set(STOPWATCH_PCLTICTOC stopwatch_pcltictoc.hpp ${STOPWATCH})
set(STOPWATCH_CVTICKMETER stopwatch_cvtickmeter.hpp ${STOPWATCH})
set(STOPWATCH_QUERYPERFORMANCE stopwatch_queryperformance.hpp ${STOPWATCH})
set(STOPWATCH_GETTICKCOUNT stopwatch_gettickcount.hpp ${STOPWATCH})

set(ALL_STOPWATCHES ${STOPWATCH_CLOCK} ${STOPWATCH_CHRONO} ${STOPWATCH_TIMEGETTIME} ${STOPWATCH_PCLTICTOC} ${STOPWATCH_CVTICKMETER} ${STOPWATCH_QUERYPERFORMANCE} ${STOPWATCH_GETTICKCOUNT})

#### Projects Settings ####

add_executable(Test1 main_test1.cpp ${ALL_STOPWATCHES} ${LOG_UTILITY})
target_link_libraries(Test1 ${PCL_LIBRARIES} ${OpenCV_LIBS})