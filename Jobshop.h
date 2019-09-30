/*
 * JobShop.h
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#ifndef SCHEDULING_JOBSHOP_H_
#define SCHEDULING_JOBSHOP_H_

#include "job.h"

class JobShop {
public:
	JobShop(std::string aTestFile);
	void makeJobList(std::vector<int> jobs);
	void makePartsJobList(int nMachines, std::vector<int> & parts);
	int getCriticalPath();
	void run();
//	std::string makeFileToString(std::ifstream& aFile);
	void makeStringToArrayList(std::string aFile);
	virtual ~JobShop();

	const std::vector<Job>& getJobList() const {
		return jobList;
	}

	int getJobs() const;
	int getMachines() const;

private:
	int nJobs;
	int nMachines;
	std::vector<int> allNumbersToList;
	std::vector<Job> jobList;
	std::vector<int>partList;
//	std::vector<int> testList {1,2,45,54,3,2,4,3,5,3,4,23,21,2};
};

#endif /* SCHEDULING_JOBSHOP_H_ */
