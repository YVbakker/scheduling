/*
 * Job.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "Job.h"

Job::Job()
{
	remainingTime = deadline = getDuration();
}

void Job::addTask(unsigned char thread, unsigned char duration)
{
	tasks.push_back(Task(thread, duration));
}

void Job::deleteCompletedTask()
{
	tasks.pop_front();
}

Task Job::getNextTask()
{
	return tasks.front();
}

unsigned char Job::slack(unsigned short cTime)
{
	return deadline - cTime - remainingTime;
}

Job::~Job()
{

}

int Job::size()
{
	return tasks.size();
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
	remainingTime = aJob.remainingTime;
	deadline = aJob.deadline;
	tasks = aJob.tasks;
}

Job Job::operator=(const Job &aJob)
{
	remainingTime = aJob.remainingTime;
	tasks = aJob.tasks;
	deadline = aJob.deadline;
	return *this;
}

bool Job::operator>(Job &aJob)
{
	return remainingTime > aJob.remainingTime;
}
