/*
 * main.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */
#include <iostream>
#include "JobShop.h"
#include "Job.h"

int main(int argc, char **argv) {

//Job j1;
//j1.addTask(0, 10);
//j1.addTask(1, 5);
//j1.addTask(2, 5);
//
//Job j2;
//j2.addTask(0, 9);
//j2.addTask(1, 5);
//j2.addTask(2, 5);
//
//j1.calculateTotalTime();
//j2.calculateTotalTime();
//j1.genereerStartTimeForTask(0);
//j2.genereerStartTimeForTask(0);
//j1.genereerEndTimeForTask(20);
//j2.genereerEndTimeForTask(20);
//
//j1.getSlackOfFirstJobToRun();
//j2.getSlackOfFirstJobToRun();
//j2.compareSlackWithOtherJobWithSameMachine(0, j1.getSlackOfFirstJobToRun());
////j1.getFirstMachineToRun();
////j1.setFirstFreeTaskToBusy(10);
////j1.getBusyMachine();
////j1.getDurationOfBusyTask();
////j1.checkIfTaskIsFinished(20);

JobShop js1;
js1.run();
}





