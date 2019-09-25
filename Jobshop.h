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
	JobShop(std::vector<int> jobs);
	void makeJobList(std::vector<int> jobs);
	void makePartsJobList(int nMachines, std::vector<int> & parts);
	virtual ~JobShop();

	const std::vector<Job>& getJobList() const {
		return jobList;
	}

	int getJobs() const;
	int getMachines() const;

private:
	int nJobs;
	int nMachines;
	std::vector<Job> jobList;
	std::vector<int>partList;
//	std::vector<int> testList {1,2,45,54,3,2,4,3,5,3,4,23,21,2};
};

#endif /* SCHEDULING_JOBSHOP_H_ */
