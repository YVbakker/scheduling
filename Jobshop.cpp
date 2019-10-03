/*
 * JobShop.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#include "Jobshop.h"
#include <iostream>
#include <regex>
#include <string>

JobShop::JobShop(std::string aFile) :
		currentTime(0) {
	// TODO Auto-generated constructor stub
	makeStringToArrayList(aFile);	// Make string to a vectorList
	makeJobList(allNumbersToList); // Makes a list of jobs
}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

//addJob add a job to the jobList
//Pre-condition =
//Post-condition = There is a job added to the last position of the vector joblist
void JobShop::addJob() {
	jobList.push_back(Job());
}

//addTaskToJob add a task to the job
//Pre-condition =	There is a vector<int> of tasks for the job and the position of the joblist is given
//Post-condition = The tasks are added to the tasklist in the specified job
void JobShop::addTaskToJob(std::vector<int> aTasksListForJob,
		unsigned short position) {

	for (long long unsigned i = 0; i < aTasksListForJob.size(); i += 2) {
		jobList.at(position).addTask(aTasksListForJob.at(i),
				aTasksListForJob.at(i + 1));
	}
}

void JobShop::run() {
	unsigned short stap = 0;
	while (checkIfAllJobsAreFinished() == false) {

		if (stap == 0) {
			criticalPath = getCriticalPath(); // The criticalPath will be calculated
			for (unsigned long i = 0; i < jobList.size(); ++i) {
				if (jobList.at(i).getStatus() != 2) { // If job is not finished
					jobList.at(i).setsTheMinimumStartTimeOfTasks(currentTime); // Update the minimum start time of a task
					jobList.at(i).setsTheMaximumStartTimeOfTasks(criticalPath); // Update the maximum start time of a task
				}
			}
			stap = 1;
		}

		if (stap == 1) {
			for (unsigned long i = 0; i < jobList.size(); ++i) {
				if (jobList.at(i).getStatus() == 0) {		// If job is free
					if (jobList.at(i).calculateTotalTimeOfJob(currentTime)// If job has the critical path
					== criticalPath) {
						if (checkIfMachineIsReadyToRun(	// If first machine who can start of this job is ready to run
								jobList.at(i).getFirstMachineToRun())
								&& jobList.at(i).getFirstMachineToRun() != -1) {
							jobList.at(i).setStatus(1);	// Set status of this job to busy
							jobList.at(i).setFirstFreeTaskToBusy(currentTime);// Set the status of this first free task to busy
						}
					} else if (checkIfMachineIsReadyToRun(// Else if the first machine who can start of this job is ready to run
							jobList.at(i).getFirstMachineToRun())
							&& jobList.at(i).getFirstMachineToRun() != -1) {
						if (compareSlackWithOtherJobWithSameMachines(
								// If the first job who can start of this job has the lowest slack of this machine
								jobList.at(i).getFirstMachineToRun(),
								jobList.at(i).getSlackOfFirstTaskToRun())
								&& jobList.at(i).getSlackOfFirstTaskToRun()
										!= -1) {
							jobList.at(i).setStatus(1);	// Set the status of this job to busy
							jobList.at(i).setFirstFreeTaskToBusy(currentTime);// Set the status of this first free task to busy
						}
					}
				}
			}
			stap = 2;
		}

		if (stap == 2) {
			unsigned short shortestValue = criticalPath;// ShortestTime is the criticalPath as a start value
			for (unsigned long i = 0; i < jobList.size(); ++i) {
				unsigned short DurationOfBusyTask =
						jobList.at(i).getDurationOfBusyTask(currentTime); // DurationOfBusyTask is the return value of the getDurationOfBusyTask function
				if (DurationOfBusyTask != -1
						&& DurationOfBusyTask < shortestValue) { // If Duration of the busy task is fewer than the shortest value
					shortestValue = DurationOfBusyTask;	// Shortest value is now the duration of the busy task
				}
			}
			currentTime += shortestValue;// The new current time is the current time plus the shortest time
			stap = 3;
		}

		if (stap == 3) {
			for (unsigned short i = 0; i < jobList.size(); ++i) {
				jobList.at(i).setTasksWhoFinishedToDone(currentTime); // Set the status of the tasks who are finished to done
			}
			setJobsWhoHaveNoFreeTaskToDone(); // Sets the jobs who have no free tasks to done
			stap = 0;
		}
	}
	giveOutput(); // When the while loop is done, this function will give the output in the console
}

// compareSlackWithOtherJobWithSameMachines says if the slack of that machine is the lowest
// Pre-condition = arguments must be a unsigned short machine and a unsigned short of the slack
// Post-condition = Return false when the given slack for that machine is not the lowest || Return true when the given slack for that machine is the lowest
bool JobShop::compareSlackWithOtherJobWithSameMachines(unsigned short aMachine,
		unsigned short aCurrentSlack) {
	for (unsigned long i = 0; i < jobList.size(); ++i) {
		if (jobList.at(i).getStatus() == 0) {  // If job is free
			if (jobList.at(i).getSlackOfFirstTaskToRun() < aCurrentSlack
					&& jobList.at(i).getSlackOfFirstTaskToRun() != -1) // If slack of first task to run lower then the slack of the argument
							{
				if (jobList.at(i).getFirstMachineToRun() == aMachine
						&& jobList.at(i).getFirstMachineToRun() != -1) // If the machine with the lower slack is the same as the machine of the argument
								{
					return false;
				}

			}

		}
	}
	return true;
}

// checkIfMachineIsReadyToRun says if a machine can run or not
// Pre-condition = There is a unsigned short machine required
// Post-condition = Return false when the machine is not ready to run || Return true when machine is ready to run
bool JobShop::checkIfMachineIsReadyToRun(unsigned short aMachine) {
	for (unsigned short i = 0; i < jobList.size(); ++i) {
		if (jobList.at(i).getBusyMachine() == aMachine
				&& jobList.at(i).getBusyMachine() != -1) { // If busy machine is equal to machine of the argument
			return false;
		}
	}
	return true;
}

// getCriticalPath gives the critical path
// Pre-condition =
// Post-condition = return the critical path
unsigned short JobShop::getCriticalPath() {
	unsigned short aStorageForCriticalPath = 0;
	unsigned short totalTimeJob = 0;

	for (unsigned long i = 0; i < jobList.size(); ++i) {
		if (jobList.at(i).getStatus() != 2) {
			totalTimeJob = jobList.at(i).calculateTotalTimeOfJob(currentTime); // TotalTimeOfJob is the return value of the calculateTotalTime function of the job. The function is now called only once
			if (totalTimeJob > aStorageForCriticalPath) { // If total time of job greater then the storage of critical path
				aStorageForCriticalPath = totalTimeJob; // new storage of critical path = totalTimeOfJob
			}
		}
	}
	return aStorageForCriticalPath;
}

// setJobsWhoHaveNoFreeTaskToDone sets the job who has no free tasks to done
// Pre-condition =
// Post-condition = set the status of a job who has no free tasks to done
void JobShop::setJobsWhoHaveNoFreeTaskToDone() {
	for (unsigned long i = 0; i < jobList.size(); ++i) {
		if (jobList.at(i).allTasksAreDone() == true) { // If this job has all tasks done
			jobList.at(i).setStatus(2);	// Set the status of this job to done
		}
	}
}

// checkIfAllJobsAreDone checks if all jobs are finished
// Pre-condition =
// Post-condition = return false when not all jobs are finished || return true when all jobs are finished
bool JobShop::checkIfAllJobsAreFinished() {
	for (unsigned long i = 0; i < jobList.size(); ++i) {
		if (jobList.at(i).allTasksAreDone() == false) {
			return false;
		}
	}
	return true;
}

// giveOutput gives the output in the console
// Pre-condition =
// Post-condition = In the console the output is printed
void JobShop::giveOutput() {
	for (unsigned long i = 0; i < jobList.size(); ++i) {
		std::cout << "Job " << i << " " << jobList.at(i).getStartTimeOfJob()
				<< " " << jobList.at(i).getEndTimeOfJob() << std::endl;
	}
}

void JobShop::makeStringToArrayList(std::string aFile) {
	std::smatch m;
	std::regex r("[0-9]+");
	while (std::regex_search(aFile, m, r)) {
		allNumbersToList.push_back(stoi(m.str(0)));
		aFile = m.suffix().str();

	}
}

void JobShop::makeJobList(std::vector<int> jobs) {
	nJobs = jobs.at(0); 		// first number is number of jobs
	std::cout << "Number of jobs is " << nJobs << std::endl;
	jobs.erase(jobs.begin()); 	// delete first value
	nMachines = jobs.at(0); 	// our new first number is number of jobs
	std::cout << "Number of machines is " << nMachines << std::endl;
	jobs.erase(jobs.begin());	// delete first value

	for (int i = 0; i < nJobs; ++i) {
		makePartsJobList(nMachines, jobs);// Make parts list (duration, machine) for every job
		addJob();
		addTaskToJob(partList, i);
		partList.clear();// clear the part list because you want to put a new list of parts in it
	}

}

void JobShop::makePartsJobList(unsigned short nMachines,
		std::vector<int> &parts) {
	for (unsigned long i = 0; i < (nMachines * 2); ++i) {
		partList.push_back(parts.at(0));// part one (duration) is pushed in the part list
		parts.erase(parts.begin());	// now part one is added to the part list, can we delete it
	}

}
