/*
 * JobShop.h
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include "Job.h"
#include <iostream>

class JobShop {
public:
	JobShop(std::string aFile);
	virtual ~JobShop();
	void addJob();
	void giveJobTasks(std::vector<int> aTasksListForJob,
			unsigned short position);
	void run();
	int getCriticalPath();
	bool checkIfMachineIsReadyToRun(unsigned short aMachine);
	bool compareSlackWithOtherJobWithSameMachine(unsigned short aMachine, unsigned short aCurrentSlack);
	bool checkIfAllJobsAreDone();
	void giveOutput();
//	bool checkIfMachineWhoWantToRunHasToLowestSlack(unsigned short machine, unsigned short jobPosition);
	void makeJobList(std::vector<int> jobs);
	void makePartsJobList(unsigned short nMachines, std::vector<int> & parts);
	void makeStringToArrayList(std::string aFile);
	void controleerOfJobIsFinished();


private:
	std::vector<Job> joblist;
	std::vector<int> allNumbersToList;
	std::vector<int>partList;
	std::vector<int> tasksListForJob;
	std::vector<int> tasksListForJob2;
	std::vector<int> tasksListForJob3;
	unsigned short nMachines;
	unsigned short nJobs;
	unsigned short currentTime;
	unsigned short path;
};

#endif /* JOBSHOP_H_ */
