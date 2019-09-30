/*
 * JobShop.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "JobShop.h"
#include <regex>
#include <algorithm>

JobShop::JobShop(std::string aFile)
:nJobs(0), nMachines(0) // initialize number of jobs and number of machines
{
makeStringToArrayList(aFile);
makeJobList(allNumbersToList); // Makes a list of jobs
}

void JobShop::makeStringToArrayList(std::string aFile){
    std::smatch m;
    std::regex r("[0-9]+");
	  while (std::regex_search(aFile, m, r)){
		  allNumbersToList.push_back(stoi(m.str(0)));
		        aFile = m.suffix().str();

	  }
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

void JobShop::run() {

	getCriticalPath();
	std::vector<Job> x = jobList;

	for(long long unsigned i = 0; i < jobList.size(); ++i){
		std::cout << "Job " << i << " has a total time of: " << x.at(i).getTotalTime() << std::endl; 	// output totale tijd job i
	}
}

int JobShop::getCriticalPath() {
	int criticalTime = 0;
	std::vector<Job> x = jobList;
	for (long long unsigned i = 0; i < jobList.size(); ++i){
	if(x.at(i).getTotalTime() > criticalTime){
		criticalTime = x.at(i).getTotalTime();
	}
	}
	std::cout << "The critical path has a total time of : " << criticalTime << std::endl; 	// output totale tijd van critical path

return criticalTime;
}

int JobShop::getMachines() const {
	return nMachines;
}
