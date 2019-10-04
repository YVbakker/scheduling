/*
 * Job.h
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>
#include "Task.h"

class Job {
public:
//	constructors
	Job();
	Job(const Job& other);
	virtual ~Job();

//	Getters
	unsigned short getStatus() const;
	const std::vector<Task>& getTaskList() const;
	unsigned short getFirstMachineToRun();
	unsigned short getBusyMachine();
	unsigned short getDurationOfBusyTask(unsigned short aCurrentTime);
	unsigned short getSlackOfFirstTaskToRun();
	unsigned short getStartTimeOfJob();
	unsigned short getEndTimeOfJob();

//	Setters
	void setStatus(unsigned short aStatus);
	void setFirstFreeTaskToBusy(unsigned short aCurrentTime);

//	Add
	void addTask(unsigned short aMachine, unsigned short aDuration);

//	calculate
	unsigned short calculateTotalTimeOfJob(unsigned short aCurrentTime);

//	Generate
	void setsTheMinimumStartTimeOfTasks(unsigned short aCurrentTime);
	void setsTheMaximumStartTimeOfTasks(unsigned short aCriticalPath);

// 	checking
	void setTasksWhoFinishedToDone(unsigned short aCurrentTime);
	bool allTasksAreDone();

//	operators
	Job& operator=(const Job& other);

private:
	std::vector<Task> taskList;	// a vector of tasks
	unsigned short status;// the current status of this job (0 = free, 1 = busy, 2 = done)
};

#endif /* JOB_H_ */
