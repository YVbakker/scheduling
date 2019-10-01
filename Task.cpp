/*
 * Task.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#include "Task.h"

Task::Task(unsigned short aMachine, unsigned short aDuration)
:machine(aMachine), duration(aDuration), startTime(0), endTime(0), status(0)
{
	// TODO Auto-generated constructor stub

}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

unsigned short Task::getDuration() const {
	return duration;
}

unsigned short Task::getEndTime() const {
	return endTime;
}

void Task::setEndTime(unsigned short endTime) {
	this->endTime = endTime;
}

unsigned short Task::getMachine() const {
	return machine;
}

unsigned short Task::getStartTime() const {
	return startTime;
}

void Task::setStartTime(unsigned short startTime) {
	this->startTime = startTime;
}

unsigned short Task::getStatus() const {
	return status;
}

void Task::setStatus(unsigned short status) {
	this->status = status;
}

int Task::calculateSlack(unsigned short aStartTime, unsigned short aEndTime) {
	return (aEndTime - aStartTime);
}

unsigned short Task::getEndTimeOfTask() const {
	return endTimeOfTask;
}

void Task::setEndTimeOfTask(unsigned short endTimeOfTask) {
	this->endTimeOfTask = endTimeOfTask;
}
