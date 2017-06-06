//
// Created by KKK on 04.06.2017.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <utility>
#include <stdio.h>

template <class T, class Tc>
class SequentialIdGenerator 
{
public:
	SequentialIdGenerator() :counterT(0)
	{
		//counterT = C();
	};
	SequentialIdGenerator(Tc counter)
	{
		counterT = counter;
	};

	T NextValue();

private:
	Tc counterT;
};
template <class T, class Tc>
T SequentialIdGenerator<T, Tc>::NextValue()
{
	Tc variable = counterT;
	//counterT++;
	++counterT;
	return T(variable);
};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H