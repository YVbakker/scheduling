
/*
 * Task.cpp
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#include "Task.h"

Task::Task(unsigned char order, unsigned char duration, unsigned char machine)
{
	this->order = order;
	this->duration = duration;
	this->machine = machine;
}

Task::~Task()
{

}

unsigned char Task::getDuration()
{
	return duration;
}

unsigned char Task::getOrder()
{
	return order;
}

unsigned char Task::getMachine()
{
	return machine;
}


