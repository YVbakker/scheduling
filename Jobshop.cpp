/*
 * JobShop.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#include "JobShop.h"
#include <iostream>

JobShop::JobShop() {
	// TODO Auto-generated constructor stub
	addJob();
	addJob();
	addJob();
	tasksListForJob = { 1, 30, 1, 30, 2, 10 };
	tasksListForJob2 = { 0, 60, 1, 15, 2, 10 };
	tasksListForJob3 = { 1, 50, 1, 16, 0, 5 };
	giveJobTasks(tasksListForJob, 0);
	giveJobTasks(tasksListForJob2, 1);
	giveJobTasks(tasksListForJob3, 2);
//
////joblist.at(0).geefAlleWaardes();
////joblist.at(1).geefAlleWaardes();
////joblist.at(2).geefAlleWaardes();
//
////std::cout << "Total : "<< joblist.at(0).calculateTotalTime() << std::endl;
////std::cout << "Total : "<< joblist.at(1).calculateTotalTime() << std::endl;
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

void JobShop::run(){
	unsigned short stap = 0;
	unsigned short path = getCriticalPath();
	currentTime = 0;
	while (path > 0){
				if(stap == 0){
					std::cout << "Stap 0" << std::endl;
					for(unsigned long i = 0; i < joblist.size(); ++i){ // Stap 1
						joblist.at(i).genereerStartTimeForTask(currentTime);
						joblist.at(i).genereerEndTimeForTask(path);
					}
					stap = 1;
				}

				if (stap == 1){
					std::cout << "Stap 1" << std::endl;
					for(unsigned long i = 0; i < joblist.size(); ++i){
						if(joblist.at(i).calculateTotalTime() == path){
							if(checkIfMachineIsReadyToRun(joblist.at(i).getFirstMachineToRun())){
								joblist.at(i).setStatus(1);
								joblist.at(i).setFirstFreeTaskToBusy(currentTime);
							}
						}
						else if(joblist.at(i).getStatus() == 0){
							if(checkIfMachineIsReadyToRun(joblist.at(i).getFirstMachineToRun())){
								if(compareSlackWithOtherJobWithSameMachine(joblist.at(i).getFirstMachineToRun(), joblist.at(i).getSlackOfFirstJobToRun())){
									joblist.at(i).setStatus(1);
									joblist.at(i).setFirstFreeTaskToBusy(currentTime);
								}
							}
						}
					}
					stap = 2;
				}
				else{
					path = 0;
				}
	}
}

bool JobShop::compareSlackWithOtherJobWithSameMachine(unsigned short aMachine, unsigned short aCurrentSlack) {
	std::cout << "De meegegeven slack = " << aCurrentSlack << std::endl;
	for (unsigned long i = 0; i < joblist.size(); ++i) {
		if (joblist.at(i).getStatus() == 0) {
			std::cout << "Job " << i << " is vrij" << std::endl;
			if(joblist.at(i).getSlackOfFirstJobToRun() < aCurrentSlack){
				std::cout << "Job " << i << " heeft een kleinere slack" << std::endl;
				if(joblist.at(i).getFirstMachineToRun() == aMachine){
					std::cout << "Job " << i << " heeft dezelfde machine" << std::endl;
					std::cout << "Het is false !" <<std::endl;
					return false;
				}

			}

		}
	}
	std::cout << "Het is waar !" <<std::endl;
	return true;
}

bool JobShop::checkIfMachineIsReadyToRun(unsigned short aMachine){
	for(unsigned short i = 0; i < joblist.size(); ++i){
		if(joblist.at(i).getBusyMachine() == aMachine){
			std::cout << "Machine is niet vrij!" << std::endl;
			return false;
		}
	}
	std::cout << "Machine is vrij en kan dus beginnen !" << std::endl;
	return true;
}

int JobShop::getCriticalPath() {
	unsigned short criticalPath = 0;
	unsigned short totalTimeJob = 0;

	for (unsigned long i = 0; i < joblist.size(); ++i){
		totalTimeJob = joblist.at(i).calculateTotalTime();
		if(criticalPath < totalTimeJob && joblist.at(i).getStatus() == 0){
		criticalPath = totalTimeJob;
		}
	}

	std::cout << "Het criticalpath is : " << criticalPath << std::endl;
	return criticalPath;
}


//
//void JobShop::run() {
//	unsigned short stap = 0;
//	unsigned short path = getCriticalPath();
//	currentTime = 0;
//	while (path > 0){
//		if(stap == 0){
//			std::cout << "Stap 0" << std::endl;
//			path = getCriticalPath();
//			for(unsigned long i = 0; i < joblist.size(); ++i){ // Stap 1
//				joblist.at(i).setCurrentTime(currentTime);
//				joblist.at(i).generateStartAndEndTime(path);
//			}
//			stap = 1;
//		}
//
//		if(stap == 1){
//			std::cout << "Stap 1" << std::endl;
//			for(unsigned long i = 0; i < joblist.size(); ++i){ // Stap 1
//				if(joblist.at(i).calculateTotalTime() == path){
//					joblist.at(i).setFirstFreeTaskToBusy(currentTime);
//					std::cout << "Job : " << i << " is begonnen met runnen" << std::endl;
//					stap = 2;
//					break;
//				}
//			}
//		}
//
//		else if (stap == 2){
//			std::cout << "Stap 2" << std::endl;
//			for(unsigned long i = 0; i < joblist.size(); ++i){ // Stap 1
//				if(joblist.at(i).getStatus() == 0){
//					std::cout << i << std::endl;
//					if(checkIfMachineIsReadyToRun(joblist.at(i).getFirstMachineToRun())){
//						std::cout << i << std::endl;
//						if(checkIfMachineWhoWantToRunHasToLowestSlack(joblist.at(i).getFirstMachineToRun(), i)){
////						std::cout << "Hij mag uitgevoerd worden!" << i << std::endl;
//						joblist.at(i).setFirstFreeTaskToBusy(currentTime);
//						std::cout << "Job : " << i << " is begonnen met runnen" << std::endl;
//						}
//					}
//				}
//			}
//			stap = 3;
//		}
//
//		else if(stap == 3){
//			std::cout << "Stap 3" << std::endl;
//			unsigned short kortsteTijd = path;
//			for(unsigned long i = 0; i < joblist.size(); ++i){
//				if(joblist.at(i).getBusyDuration() >= 0 && joblist.at(i).getBusyDuration() < kortsteTijd){
//					kortsteTijd = joblist.at(i).getBusyDuration();
//				}
//			}
//			stap = 4;
////			std::cout << "Kortste tijd is = " << kortsteTijd << std::endl;
//			currentTime += kortsteTijd;
//		}
//
//		else if(stap == 4){
//			std::cout << "Stap 4" << std::endl;
//			for(unsigned short i = 0; i < joblist.size(); ++i){
////				std::cout << "Huidige Status van job : " << i << std::endl;
//				joblist.at(i).setCurrentTime(currentTime);
//				joblist.at(i).checkIfTaskTimeIsDone(currentTime);
//			}
//			stap = 5;
//		}
//
//		else if (stap == 5){
//			std::cout << "Stap 5" << std::endl;
//			for(unsigned short i = 0; i < joblist.size(); ++i){
//				joblist.at(i).setCurrentTime(currentTime);
//				joblist.at(i).generateStartAndEndTime(path);
//			}
//			stap = 6;
//		}
//
//		if(stap == 6){
//			std::cout << "Stap 6" << std::endl;
//			path = getCriticalPath();
//			for(unsigned long i = 0; i < joblist.size(); ++i){ // Stap 1
//				joblist.at(i).setCurrentTime(currentTime);
//				joblist.at(i).generateStartAndEndTime(path);
////				std::cout << "Total time of job : " << i << " is " << joblist.at(i).calculateTotalTime() << std::endl;
//				if(joblist.at(i).calculateTotalTime() == path){
//					if(checkIfMachineIsReadyToRun(joblist.at(i).getFirstMachineToRun())){
////					std::cout << "Total time of job : " << i << " is " << joblist.at(i).calculateTotalTime() << std::endl;
//					joblist.at(i).setFirstFreeTaskToBusy(currentTime);
//					std::cout << "Job : " << i << " is begonnen met runnen" << std::endl;
////					break;
//					}
//				}
//			}
//			stap = 2;
//		}
//
//		else{
////		std::cout << currentTime << std::endl;
////		currentTime ++;
//		}
//	}
//for (unsigned long i = 0; i < joblist.size(); ++i){
//	std::cout << "Job : " << i << " has a startTime of = " << joblist.at(i).getTaskList().at(0).getStartTime() << " and a end time of " << joblist.at(i).getTaskList().at(2).getEndTime() << std::endl;
//}
//
//}
//
//
//
//bool JobShop::checkIfMachineWhoWantToRunHasToLowestSlack(unsigned short machine, unsigned short jobPosition){
//	unsigned short leastSlack = joblist.at(jobPosition).getSlackOfFirstJobToRun();
//	std::cout << "Slack of job " << jobPosition << " is : " << leastSlack << std::endl;
//	for (unsigned long i = 0; i < joblist.size(); ++i){
//		if(joblist.at(i).getStatus() == 0){
//			std::cout << "Job : " << i << " has a slack = " << joblist.at(i).getSlackOfFirstJobToRun() << std::endl;
//			std::cout << "Job : " << i << " has a status = " << joblist.at(i).getStatus() << std::endl;
//			std::cout << "Job : " << i << " has a machine = " << joblist.at(i).getFirstMachineToRun() << std::endl;
//			std::cout << "Job : " << i << " has a duration of = " << joblist.at(i).getTaskList().at(0).getDuration() << std::endl;
//			if(joblist.at(i).getFirstMachineToRun() == machine){
//			if(joblist.at(i).checkSlackOfFirstJobToRun(machine) >= 0 && joblist.at(i).checkSlackOfFirstJobToRun(machine) < leastSlack){
////				std::cout << "HET IS FALSE" << std::endl;
//				return false;
//			}
//			}
//		}
//	}
//	return true;
//}
