/*
 * JobShop.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "JobShop.h"

JobShop::JobShop(std::vector<int> jobs)
:nJobs(0), nMachines(0)
{
	// TODO Auto-generated constructor stub

	makeJobList(jobs);
}

void JobShop::makeJobList(std::vector<int> jobs) {
	nJobs = jobs.at(0);
	jobs.erase(jobs.begin());
	nMachines = jobs.at(0);
	jobs.erase(jobs.begin());

	for (int i = 0; i < nJobs; i+=2){
	jobList.push_back(Job(testList));
	}

}

void JobShop::makePartsJobList(std::vector<int> parts) {
	for (int i = 0; i < nJobs; i+=2){

	}
}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

