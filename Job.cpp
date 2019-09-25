/*
 * Job.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "Job.h"

Job::Job(std::vector<int> tasks)
:nTasks(tasks.size()), totalTime(0)
 {
	makeTaskList(nTasks, tasks);
}

void Job::makeTaskList(int nTasks, std::vector<int> tasks) {
for (int i = 0; i < nTasks; i+=2){
taskList.push_back(Task(tasks.at(i), tasks.at(i+1)));
}
}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

const std::vector<Task>& Job::getTaskList() const {
	return taskList;
}
