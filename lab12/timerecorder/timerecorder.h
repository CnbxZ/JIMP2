//
// Created by KKK on 04.06.2017.
//

// timerecorder.h

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H


#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <utility>


namespace profiling
{
	template<typename T>
	auto TimeRecorder(T variable) 
	{
		static std::chrono::high_resolution_clock::time_point difference = std::chrono::high_resolution_clock::now();
		auto result = (variable)();
		std::chrono::duration<double,std::milli> roznica = std::chrono::high_resolution_clock::now() - difference;
		std::chrono::time_point<std::chrono::system_clock> start, end;
		std::chrono::duration<double> elapsed_seconds = end - start;
		return std::pair<decltype(result),double>(result,roznica.count());
	};
}
#endif //JIMP_EXERCISES_TIMERECORDER_H