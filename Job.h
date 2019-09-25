/*
 * Job.h
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#ifndef SCHEDULING_JOB_H_
#define SCHEDULING_JOB_H_

#include "Task.h"
#include <list>

class Job {
public:
	Job(std::vector<int> tasks);
	void makeTaskList(int nTasks, std::vector<int> tasks);

	virtual ~Job();
	const std::vector<Task>& getTaskList() const;

private:
	int nTasks;
	int totalTime;
	std::vector<Task> taskList;
};

#endif /* SCHEDULING_JOB_H_ */
