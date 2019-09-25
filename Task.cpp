
/*
 * Task.cpp
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#include "Task.h"
#include <iostream>

Task::Task(int aDuration, int aMachine)
:duration(aDuration), machine(aMachine)
{

	std::cout << duration << " " << machine << std::endl;

}

Task::~Task()
{

}

unsigned int Task::getDuration()
{
	return duration;
}

unsigned int Task::getMachine()
{
	return machine;
}


