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
	// Constructors
	JobShop(std::string aFile);
	virtual ~JobShop();

	// Getters
	unsigned short getCriticalPath();

	// Setters

	// Add
	void addJob();
	void addTaskToJob(std::vector<int> aTasksListForJob,
			unsigned short position);

	// Make
	void makeJobList(std::vector<int> jobs);
	void makePartsJobList(unsigned short nMachines, std::vector<int> &parts);
	void makeStringToArrayList(std::string aFile);

	// Run
	void run();

	// Check
	bool checkIfMachineIsReadyToRun(unsigned short aMachine);
	bool checkIfAllJobsAreFinished();
	void setJobsWhoHaveNoFreeTaskToDone();

	// Compare
	bool compareSlackWithOtherJobWithSameMachines(unsigned short aMachine,
			unsigned short aCurrentSlack);

	// Output
	void giveOutput();

private:
	std::vector<Job> jobList;			// A vector of all jobs
	std::vector<int> allNumbersToList;// A vector of all numbers who later will be transferd to the list of parts
	std::vector<int> partList;// A vector of the parts (machine and duration) who will be later added to the job list
	std::vector<std::string> lineInputList;
	unsigned short nMachines;			// Number of machines
	unsigned short nJobs;				// Number of jobs
	unsigned short currentTime;			// Current time
	unsigned short criticalPath;				// The critical path
};

#endif /* JOBSHOP_H_ */
