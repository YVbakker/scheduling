/*
 * Task.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#include "Task.h"

Task::Task(unsigned short aMachine, unsigned short aDuration) :
		machine(aMachine), duration(aDuration), startTime(0), endTime(0), endTimeOfTask(
				0), status(0) {
	// TODO Auto-generated constructor stub

}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

// Getters
unsigned short Task::getDuration() const {
	return duration;
}

unsigned short Task::getEndTime() const {
	return endTime;
}

unsigned short Task::getMachine() const {
	return machine;
}

unsigned short Task::getStartTime() const {
	return startTime;
}

unsigned short Task::getStatus() const {
	return status;
}

unsigned short Task::getEndTimeOfTask() const {
	return endTimeOfTask;
}

// Setters
void Task::setEndTime(unsigned short endTime) {
	this->endTime = endTime;
}

void Task::setStartTime(unsigned short startTime) {
	this->startTime = startTime;
}

void Task::setStatus(unsigned short status) {
	this->status = status;
}

void Task::setEndTimeOfTask(unsigned short endTimeOfTask) {
	this->endTimeOfTask = endTimeOfTask;
}

// calculateSlack calculate the slack of this task
// Pre-condition = there is a start and end time initialized
// Post-condition = it returns the slack of this
unsigned short Task::calculateSlack() {
	return (endTime - startTime);
}
