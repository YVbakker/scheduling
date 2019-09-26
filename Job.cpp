/*
 * Job.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "Job.h"

Job::Job()
{
	remainingComputationTime = getDuration();
}

void Job::addTask(unsigned char thread, unsigned char duration)
{
	tasks.push_back(Task(thread,duration));
}

void Job::deleteCompletedTask()
{
	tasks.pop_front();
}

Task Job::getNextTask()
{
	return tasks.front();
}

Job::~Job()
{
}

unsigned char Job::getDuration()
{
	unsigned char duration = 0;
	for (Task t : tasks)
	{
		duration += t.getDuration();
	}
	return duration;
}

Job::Job(const Job &aJob)
{
	remainingComputationTime = aJob.remainingComputationTime;
	tasks = aJob.tasks;
}

Job Job::operator =(const Job &aJob)
{
	remainingComputationTime = aJob.remainingComputationTime;
	tasks = aJob.tasks;
	return *this;
}

bool Job::operator >(const Job &aJob)
{
	return remainingComputationTime > aJob.remainingComputationTime;
}
