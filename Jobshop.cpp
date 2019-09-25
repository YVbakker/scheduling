/*
 * JobShop.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "JobShop.h"

JobShop::JobShop(std::vector<int> jobs)
:nJobs(0), nMachines(0) // initialize number of jobs and number of machines
{
	// TODO Auto-generated constructor stub

	makeJobList(jobs); // Makes a list of jobs
}

void JobShop::makeJobList(std::vector<int> jobs) {
	nJobs = jobs.at(0); 		// first number is number of jobs
	jobs.erase(jobs.begin()); 	// delete first value
	nMachines = jobs.at(0); 	// our new first number is number of jobs
	jobs.erase(jobs.begin());	// delete first value

	for (int i = 0; i < nJobs; ++i){
	makePartsJobList(nMachines, jobs);	// Make parts list (duration, machine) for every job
	jobList.push_back(Job(partList));	// push the vector of part list to your new job
	partList.clear();					// clear the part list because you want to put a new list of parts in it
	}

}

void JobShop::makePartsJobList(int nMachines, std::vector<int>&parts) {
	for (int i = 0; i < 2*nMachines; i+=2){
		std::cout << " -------------------- " << std::endl;
partList.push_back(parts.at(0));	// part one (duration) is pushed in the part list
partList.push_back(parts.at(1));	// part two (machine) is pushed in the part list
parts.erase(parts.begin());			// now part one is added to the part list, can we delete it
parts.erase(parts.begin());			// now part two is added to the part list, can we delete it
	}

}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

int JobShop::getJobs() const {
	return nJobs;
}

int JobShop::getMachines() const {
	return nMachines;
}
