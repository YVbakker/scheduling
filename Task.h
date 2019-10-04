/*
 * Task.h
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#ifndef TASK_H_
#define TASK_H_

class Task {
public:
//	Constructors
	Task(unsigned short aMachine, unsigned short aDuration);
	Task(const Task& other);
	virtual ~Task();

//	getters
	unsigned short getDuration() const;
	unsigned short getEndTime() const;
	unsigned short getMachine() const;
	unsigned short getStartTime() const;
	unsigned short getStatus() const;
	unsigned short getEndTimeOfTask() const;

//	setters
	void setEndTime(unsigned short endTime);
	void setStartTime(unsigned short startTime);
	void setStatus(unsigned short status);
	void setEndTimeOfTask(unsigned short endTimeOfTask);

//	calculate
	unsigned short calculateSlack();

//	operators
	Task& operator=(const Task& other);

private:
	unsigned short machine;			// Machine for this task
	unsigned short duration;		// Duration for this task
	unsigned short startTime;		// Minimum of start time
	unsigned short maxStartTime;	// Maximum of start time
	unsigned short endTime;			// Real time of ending this task
	unsigned short status;			// Status of this job (0 = free, 1 = busy, 2 = done)
};

#endif /* TASK_H_ */
