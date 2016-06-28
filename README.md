# WinCppTimeMeasurement

Time measurement method comparison using C++11, PCL and OpenCV on Windows.  
The following methods can be examined:

* clock()
* GetTickCount()
* timeGetTime()
* QueryPerformanceCounter()
* std::chrono::system_clock::now()
* cv::TickMeter::start(), cv::TickMeter::stop()
* pcl::console::TicToc::tic(), pcl::console::TicToc::toc()

##Requirements

* Windows
* [OpenCV](http://opencv.org/)
* [PointCloudLibrary (PCL)](http://pointclouds.org/)
* [CMake](http://www.cmake.org/)

## Usage

1. Create the project by `cmake`
2. Build and Run

## Results

![Results](https://raw.githubusercontent.com/kenkenjlab/WinCppTimeMeasurement/master/results.png)

## References (Japanese)

* [C言語/C++ 処理時間計測 入門 - ViVi](http://vivi.dyndns.org/tech/cpp/timeMeasurement.html#GetTickCount)
* [各種ライブラリにおける処理時間計測方法（C++） - Time waits for no Man](http://yuzatakujp1013.hatenablog.com/entry/2015/12/28/172536)

## Copyright and Lisence 

&copy; 2016 kenken.  
This software is released under the MIT License.
