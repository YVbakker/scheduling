/*
 * Job.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#include "Job.h"
#include <iostream>

Job::Job() :
		status(0) {
	// TODO Auto-generated constructor stub

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

unsigned short Job::calculateTotalTime(unsigned short aCurrentTime, unsigned short laatsteJobDuration) {
	unsigned short totalTime = aCurrentTime;
	for (unsigned long i = 0; i < taskList.size(); ++i) {
		if (taskList.at(i).getStatus() == 0){
			totalTime += taskList.at(i).getDuration();
		}
		else if(taskList.at(i).getStatus() == 1) {
			totalTime += (taskList.at(i).getEndTimeOfTask() - aCurrentTime);
		}
	}
	std::cout << "Total time = " << totalTime << std::endl;
	return totalTime;
}

void Job::addTask(unsigned short aMachine, unsigned short aDuration) {
	taskList.push_back(Task(aMachine, aDuration));
}

//void Job::addListOfTasks(std::vector<Task> aListOfTasks){
//	for(unsigned long i = 0; i < aListOfTasks.size(); i+=2){
//		addTask(aListOfTasks.at(i), aListOfTasks.at(i+1))
//	}
//}

unsigned short Job::getStatus() const {
	return status;
}

void Job::setStatus(unsigned short aStatus) {
	status = aStatus;
}

const std::vector<Task>& Job::getTaskList() const {
	return taskList;
}

void Job::genereerStartTimeForTask(unsigned short aCurrentTime, unsigned short laatsteJobDuration) {
	unsigned short start = aCurrentTime;
	std::cout << "GenereerStartTijd start = " << laatsteJobDuration << std::endl;
	for (long unsigned i = 0; i < taskList.size(); i++) {
		if(taskList.at(i).getStatus() == 1){
			start += (taskList.at(i).getEndTimeOfTask() - aCurrentTime);
		}
		if (taskList.at(i).getStatus() == 0) {
			taskList.at(i).setStartTime(start);
			start += taskList.at(i).getDuration();
			std::cout << "Taak " << i << " heeft de starttijd "
					<< taskList.at(i).getStartTime() << std::endl;
		}
	}
}

void Job::genereerEndTimeForTask(unsigned short aCriticalPath) {
	unsigned short eind = aCriticalPath;
	for (long unsigned i = taskList.size(); i > 0; --i) {
		unsigned short durationOfTask = taskList.at(i - 1).getDuration();
		if (taskList.at(i - 1).getStatus() == 0) {
			taskList.at(i - 1).setEndTime(eind - durationOfTask);
			eind -= durationOfTask;
			std::cout << "Taak " << i - 1 << " heeft de eindtijd "
					<< taskList.at(i - 1).getEndTime() << std::endl;
		}
	}
}

unsigned short Job::getFirstMachineToRun() {
	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 0) {
			std::cout << "Machine " << taskList.at(i).getMachine()
					<< " is the first who can start of this job" << std::endl;
			return taskList.at(i).getMachine();
		}
	}
	return -1;
}

unsigned short Job::getBusyMachine() {

	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 1) {
			std::cout << "Machine " << taskList.at(i).getMachine() << " is busy" << std::endl;
			return taskList.at(i).getMachine();
		}
	}
	return -1;
}

void Job::setFirstFreeTaskToBusy(unsigned short aCurrentTime) {
	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 0) {
			std::cout << "Taak " << i << " is begonnen met uitvoeren"
					<< std::endl;
			taskList.at(i).setStatus(1);
			taskList.at(i).setStartTime(aCurrentTime);
			taskList.at(i).setEndTimeOfTask(aCurrentTime + taskList.at(i).getDuration());
			std::cout << "Taak " << i << " zal klaar zijn op tijdstip " << taskList.at(i).getEndTimeOfTask() << std::endl;
			status = 1;
			break;
		}
	}
}

void Job::checkIfTaskIsFinished(unsigned short aCurrentTime) {
	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 1) {
			if (taskList.at(i).getStartTime() + taskList.at(i).getDuration()
					== aCurrentTime) {
				std::cout << "Taak " << i << " is afgerond met de volgende tijden : "
						<< taskList.at(i).getStartTime()
								+ taskList.at(i).getDuration()
						<< " en de huidige tijd nu is : " << aCurrentTime
						<< std::endl;
				taskList.at(i).setStatus(2);
				status = 0;
				break;
			}
		}
	}
}

unsigned short Job::getDurationOfBusyTask(unsigned short aCurrentTime) {
	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 1) {
			std::cout << "Taak " << i << " is bezig en heeft een duration van "
					<< taskList.at(i).getEndTimeOfTask() - aCurrentTime << std::endl;
			return (taskList.at(i).getEndTimeOfTask() - aCurrentTime);
		}
	}
	return -1;
}

bool Job::allTasksAreDone(){
for (unsigned long i = 0; i < taskList.size(); ++i){
	if(taskList.at(i).getStatus() != 2){
		return false;
	}
}
std::cout << "Alle Taken van deze job zijn klaar !!!!" << std::endl;
return true;
}

unsigned short Job::getSlackOfFirstJobToRun() {
	for (unsigned long i = 0; i < taskList.size(); ++i) {
		if (taskList.at(i).getStatus() == 0) {
//			std::cout << "De slack van taak " << i << " is "
//					<< taskList.at(i).calculateSlack(
//							taskList.at(i).getStartTime(),
//							taskList.at(i).getEndTime()) << std::endl;
			return taskList.at(i).calculateSlack(taskList.at(i).getStartTime(),
					taskList.at(i).getEndTime());
		}
	}
	return -1;
}

int Job::getStartTimeOfJob() {
return taskList.at(0).getStartTime();
}

int Job::getEndTimeOfJob() {
	return taskList.at(taskList.size() - 1).getEndTimeOfTask();
}
