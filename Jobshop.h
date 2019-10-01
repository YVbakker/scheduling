/*
 * JobShop.h
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include "Job.h"

class JobShop {
public:
	JobShop();
	virtual ~JobShop();
	void addJob();
	void giveJobTasks(std::vector<int> aTasksListForJob,
			unsigned short position);
	void run();
	int getCriticalPath(unsigned short durationLastFinishedJob = 0);
	bool checkIfMachineIsReadyToRun(unsigned short aMachine);
	bool compareSlackWithOtherJobWithSameMachine(unsigned short aMachine, unsigned short aCurrentSlack);
//	bool checkIfMachineWhoWantToRunHasToLowestSlack(unsigned short machine, unsigned short jobPosition);

private:
	std::vector<Job> joblist;
	std::vector<int> tasksListForJob;
	std::vector<int> tasksListForJob2;
	std::vector<int> tasksListForJob3;
	unsigned short nMachines;
	unsigned short nJobs;
	unsigned short currentTime;
	unsigned short path;
};

#endif /* JOBSHOP_H_ */
