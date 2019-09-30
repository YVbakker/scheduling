/*
 * Thread.cpp
 *
 *  Created on: 26 Sep 2019
 *      Author: yvbakker
 */

#include "Thread.h"

Thread::Thread()
{
	remainingExecutionTime = 0;
}

Thread::~Thread()
{

}

unsigned char Thread::getRemainingExecutionTime()
{
	return remainingExecutionTime;
}

void Thread::setRemainingExecutionTime() :
		remainingExecutionTime(remainingExecutionTime)
{
}
