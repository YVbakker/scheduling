/*
 * Job.h
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#ifndef SCHEDULING_JOB_H_
#define SCHEDULING_JOB_H_

#include "Task.h"
#include <deque>

class Job {
public:
	Job();
	Job(const Job& aJob); //copy constructor (required for use with Vector)
	Job operator=(const Job& aJob); //operator= (required for use with Vector)
	bool operator>(Job& aJob); //operator> (for easy sorting)
	void addTask(unsigned char thread, unsigned char duration);
	void deleteCompletedTask();
	void setDeadline();
	int size();
	unsigned char getDuration();
	Task getNextTask();
	unsigned char slack(unsigned short cTime);
	virtual ~Job();
private:
	unsigned char deadline;
	unsigned short remainingTime;
	std::deque<Task> tasks; //use deque for better performance delete from front
};

#endif /* SCHEDULING_JOB_H_ */
