/*
 * Job.cpp
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#include "Job.h"

Job::Job(unsigned char nTasks, unsigned char jobId)
{
	this->jobId = jobId;
	this->tasks = tasks[nTasks];
	this->duration = getTotalDuration();
}

unsigned char Job::getTotalDuration()
{
	unsigned char totalDuration = 0;
	for(Task t : tasks)
	{
		totalDuration += t.getDuration();
	}
	return totalDuration;
}

Job::~Job()
{
	for(Task t : tasks)
		delete t;
}



