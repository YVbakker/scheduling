/*
 * Job.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "Job.h"

Job::Job(std::vector<int> tasks)
:nTasks(tasks.size()/2), totalTime(0) // initialize number of tasks and total time
 {
	makeTaskList(nTasks, tasks); // makes a list of tasks
	totalTime = berekenTotaleTijd(nTasks); // calculate totalTime
}

void Job::makeTaskList(int nTasks, std::vector<int> tasks) {
for (int i = 0; i < 2*nTasks; i+=2){ // do it as many tasks you have. I goes 2 up because every task you have a duration and a machine.
taskList.push_back(Task(tasks.at(i), tasks.at(i+1)));
}
}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

int Job::berekenTotaleTijd(int nTasks) { // do it as my number of tasks you have.
	int total = 0;
		for(int i = 0; i<nTasks; ++i){
		total = total + taskList.at(i).getDuration(); // count the total of all the duration for this job
	}

	return total;
}

const std::vector<Task>& Job::getTaskList() const {
	return taskList;
}
