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
	Job();
	virtual ~Job();
	unsigned short calculateTotalTime(unsigned short aCurrentTime);
	void addTask(unsigned short aMachine, unsigned short aDuration);
	unsigned short getStatus() const;
	void setStatus(unsigned short aStatus);
	const std::vector<Task>& getTaskList() const;
	void genereerStartTimeForTask(unsigned short aCurrentTime, unsigned short laatsteJobDuration = 0);
	void genereerEndTimeForTask(unsigned short aCriticalPath);
	unsigned short getFirstMachineToRun();
	unsigned short getBusyMachine();
	void setFirstFreeTaskToBusy(unsigned short aCurrentTime);
	void checkIfTaskIsFinished(unsigned short aCurrentTime);
	unsigned short getDurationOfBusyTask(unsigned short aCurrentTime);
//	unsigned short compareSlackWithOtherJobWithSameMachine(unsigned short aMachine, unsigned short aCurrentSlack);
	unsigned short getSlackOfFirstJobToRun();
	bool allTasksAreDone();
	int getStartTimeOfJob();
	int getEndTimeOfJob();
	void addListOfTasks(std::vector<Task> aListOfTasks);


private:
	std::vector<Task>taskList;
	unsigned short status;
};

#endif /* JOB_H_ */
