/*
 * JobShop.h
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#ifndef SCHEDULING_JOBSHOP_H_
#define SCHEDULING_JOBSHOP_H_

#include "Job.h"
#include "Thread.h"
#include <vector>
#include <map>
#include <string>

class JobShop {
public:
	JobShop(std::string input); //input string in ABNF format
	void addJob();
	void deleteJob(unsigned char index);
	std::string calc();
	virtual ~JobShop();

private:
	std::vector<Job> jobs;
	std::vector<Thread> threads;
};

#endif /* SCHEDULING_JOBSHOP_H_ */
