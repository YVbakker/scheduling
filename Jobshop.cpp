/*
 * JobShop.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#include "JobShop.h"
#include <iostream>
#include <regex>
#include <string>

JobShop::JobShop(std::string aFile) {
	// TODO Auto-generated constructor stub
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	makeStringToArrayList(aFile);
	makeJobList(allNumbersToList); // Makes a list of jobs
//	addJob();
//	addJob();
//	addJob();
//	tasksListForJob = { 0, 30, 1, 30, 2, 10 };
//	tasksListForJob2 = { 0, 60, 1, 15, 2, 10 };
//	tasksListForJob3 = { 1, 50, 2, 16, 0, 5 };
//	giveJobTasks(tasksListForJob, 0);
//	giveJobTasks(tasksListForJob2, 1);
//	giveJobTasks(tasksListForJob3, 2);
}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

void JobShop::addJob() {
	joblist.push_back(Job());
}

void JobShop::giveJobTasks(std::vector<int> aTasksListForJob,
		unsigned short position) {

	for (long long unsigned i = 0; i <= aTasksListForJob.size(); ++i) {
		joblist.at(position).addTask(aTasksListForJob.at(0),
				aTasksListForJob.at(1));
		aTasksListForJob.erase(aTasksListForJob.begin());
		aTasksListForJob.erase(aTasksListForJob.begin());
	}
}

void JobShop::run() {
	unsigned short stap = 0;
	path = getCriticalPath();
	unsigned short kortsteTijd = 0;
	currentTime = 0;
	while (checkIfAllJobsAreDone() == false){
		if (stap == 0) {
			std::cout
					<< "------------------------- Stap 0 --------------------------------"
					<< std::endl;
			for (unsigned long i = 0; i < joblist.size(); ++i) { // Stap 1
				joblist.at(i).genereerStartTimeForTask(currentTime);
				joblist.at(i).genereerEndTimeForTask(path);
				joblist.at(i).calculateTotalTime(currentTime);
			}
			stap = 1;
		}

		if (stap == 1) {
			std::cout
					<< "------------------------- Stap 1 --------------------------------"
					<< std::endl;
			for (unsigned long i = 0; i < joblist.size(); ++i) {
				if (joblist.at(i).getStatus() == 0) {
					if (joblist.at(i).calculateTotalTime(currentTime,
							kortsteTijd) == path) {
						if (checkIfMachineIsReadyToRun(
								joblist.at(i).getFirstMachineToRun())) {
							joblist.at(i).setStatus(1);
							joblist.at(i).setFirstFreeTaskToBusy(currentTime);
						}
					}
					if (joblist.at(i).getStatus() == 0) {
						if (checkIfMachineIsReadyToRun(
								joblist.at(i).getFirstMachineToRun() && joblist.at(i).getFirstMachineToRun() >= 0)) {
							if (compareSlackWithOtherJobWithSameMachine(
									joblist.at(i).getFirstMachineToRun(),
									joblist.at(i).getSlackOfFirstJobToRun())) {
								joblist.at(i).setStatus(1);
								joblist.at(i).setFirstFreeTaskToBusy(
										currentTime);
							}
						}
					}
					else{
						joblist.at(i).setStatus(2);
					}
				}
			}
			stap = 2;
		}

		if (stap == 2) {
			std::cout
					<< "------------------------- Stap 2 --------------------------------"
					<< std::endl;
			kortsteTijd = path;
			for (unsigned long i = 0; i < joblist.size(); ++i) {
				unsigned short DurationOfBusyTask = joblist.at(i).getDurationOfBusyTask(currentTime);
				if (DurationOfBusyTask >= 0	&& DurationOfBusyTask < kortsteTijd) {
					std::cout << "Job " << i << " heeft een kleinere tijd dan " << kortsteTijd << " en heeft als durationBusyTask " << DurationOfBusyTask << std::endl;
					kortsteTijd = DurationOfBusyTask;
				}
			}
			stap = 3;
			currentTime += kortsteTijd;
			std::cout << "De nieuwe current time is : " << currentTime
					<< std::endl;
		}

		if (stap == 3) {
			std::cout
					<< "------------------------- Stap 3 --------------------------------"
					<< std::endl;
			for (unsigned short i = 0; i < joblist.size(); ++i) {
				joblist.at(i).checkIfTaskIsFinished(currentTime);
			}
			stap = 4;
		}

		if (stap == 4) {
			std::cout
					<< "------------------------- Stap 4 --------------------------------"
					<< std::endl;
			path = getCriticalPath(kortsteTijd);
			for (unsigned long i = 0; i < joblist.size(); ++i) { // Stap 1
				joblist.at(i).genereerStartTimeForTask(currentTime,
						kortsteTijd);
				joblist.at(i).genereerEndTimeForTask(path);
			}
			stap = 1;

		}

		else {
			path = 0;
		}
	}
	giveOutput();
}

bool JobShop::compareSlackWithOtherJobWithSameMachine(unsigned short aMachine,
		unsigned short aCurrentSlack) {
	std::cout << "De meegegeven slack = " << aCurrentSlack << std::endl;
	for (unsigned long i = 0; i < joblist.size(); ++i) {
		if (joblist.at(i).getStatus() == 0) {
			if (joblist.at(i).getSlackOfFirstJobToRun() < aCurrentSlack) {
				if (joblist.at(i).getFirstMachineToRun() == aMachine) {
					std::cout << "Het is false !" << std::endl;
					return false;
				}

			}

		}
	}
	std::cout << "Het is waar !" << std::endl;
	return true;
}

bool JobShop::checkIfMachineIsReadyToRun(unsigned short aMachine) {
	for (unsigned short i = 0; i < joblist.size(); ++i) {
		if (joblist.at(i).getBusyMachine() == aMachine) {
			std::cout << "Machine is niet vrij!" << std::endl;
			return false;
		}
	}
	std::cout << "Machine is vrij en kan dus beginnen !" << std::endl;
	return true;
}

int JobShop::getCriticalPath(unsigned short durationLastFinishedJob) {
	unsigned short criticalPath = 0;
	unsigned short totalTimeJob = 0;

	for (unsigned long i = 0; i < joblist.size(); ++i) {
		totalTimeJob = joblist.at(i).calculateTotalTime(currentTime,
				durationLastFinishedJob);
		if (totalTimeJob > criticalPath) {
			criticalPath = totalTimeJob;
		}
	}

	std::cout << "Het criticalpath is : " << criticalPath << std::endl;
	return criticalPath;
}

bool JobShop::checkIfAllJobsAreDone(){
	for (unsigned long i = 0; i < joblist.size(); ++i){
		if(joblist.at(i).allTasksAreDone() == false){
			return false;
		}
	}
	std::cout << "Alle jobs zijn klaar !" << std::endl;
	return true;
}

void JobShop::giveOutput (){
	for (unsigned long i = 0; i < joblist.size(); ++i){
		std::cout << "Job " << i << " started at " << joblist.at(i).getStartTimeOfJob() << " and finished at " << joblist.at(i).getEndTimeOfJob() << std::endl;
	}
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
	addJob();
	joblist.at(i).addTask(partList.at(0), partList.at(1));	// push the vector of part list to your new job
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
