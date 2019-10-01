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

unsigned short Job::calculateTotalTime() {
	unsigned short totalTime = 0;
	for (unsigned long i = 0; i < taskList.size(); ++i) {
		if (taskList.at(i).getStatus() == 0) {
			totalTime += taskList.at(i).getDuration();
		}
	}
	std::cout << "Total time = " << totalTime << std::endl;
	return totalTime;
}

void Job::addTask(unsigned short aMachine, unsigned short aDuration) {
	taskList.push_back(Task(aMachine, aDuration));
}

unsigned short Job::getStatus() const {
	return status;
}

void Job::setStatus(unsigned short aStatus) {
	status = aStatus;
}

const std::vector<Task>& Job::getTaskList() const {
	return taskList;
}

void Job::genereerStartTimeForTask(unsigned short aCurrentTime) {
	unsigned short start = aCurrentTime;
	for (long unsigned i = 0; i < taskList.size(); i++) {
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
		if (taskList.at(i - 1).getStatus() == 0) {
			taskList.at(i - 1).setEndTime(
					eind - taskList.at(i - 1).getDuration());
			eind -= taskList.at(i - 1).getDuration();
			std::cout << "Taak " << i - 1 << " heeft de starttijd "
					<< taskList.at(i - 1).getEndTime() << std::endl;
		}
	}
}

unsigned short Job::getFirstMachineToRun() {
	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 0) {
			std::cout << "Machine " << i
					<< " is the first who can start of this job" << std::endl;
			return taskList.at(i).getMachine();
		}
	}
	return -1;
}

unsigned short Job::getBusyMachine() {

	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 1) {
			std::cout << "Machine " << i << " is busy" << std::endl;
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
				std::cout << "Taak is afgerond met de volgende tijden : "
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

unsigned short Job::getDurationOfBusyTask() {
	for (unsigned long i = 0; i < taskList.size(); i++) {
		if (taskList.at(i).getStatus() == 1) {
			std::cout << "Taak " << i << " is bezig en heeft een duration van "
					<< taskList.at(i).getDuration() << std::endl;
			return taskList.at(i).getDuration();
		}
	}
	return -1;
}

//unsigned short Job::compareSlackWithOtherJobWithSameMachine(
//		unsigned short aMachine, unsigned short aCurrentSlack) {
//	for (unsigned long i = 0; i < taskList.size(); i += 2) {
//		if (taskList.at(i).getStatus() == 0) {
//			std::cout<< "Taak "
//			if(taskList.at(i).calculateSlack(taskList.at(i).getStartTime(),
//					taskList.at(i).getEndTime()) < aCurrentSlack){
//				if(taskList.at(i).getMachine() == aMachine){
//					std::cout << "Het is false !" <<std::endl;
//					return false;
//				}
//
//			}
//
//		}
//	}
//	std::cout << "Het is waar !" <<std::endl;
//	return true;
//}

unsigned short Job::getSlackOfFirstJobToRun() {
	for (unsigned long i = 0; i < taskList.size(); i += 2) {
		if (taskList.at(i).getStatus() == 0) {
			std::cout << "De slack van taak " << i << " is "
					<< taskList.at(i).calculateSlack(
							taskList.at(i).getStartTime(),
							taskList.at(i).getEndTime()) << std::endl;
			return taskList.at(i).calculateSlack(taskList.at(i).getStartTime(),
					taskList.at(i).getEndTime());
		}
	}
	return -1;
}
