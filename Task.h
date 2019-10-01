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
	Task(unsigned short aMachine, unsigned short aDuration);
	virtual ~Task();
	unsigned short getDuration() const;
	unsigned short getEndTime() const;
	void setEndTime(unsigned short endTime);
	unsigned short getMachine() const;
	unsigned short getStartTime() const;
	void setStartTime(unsigned short startTime);
	unsigned short getStatus() const;
	void setStatus(unsigned short status);
	int calculateSlack(unsigned short aStartTime, unsigned short aEndTime);

private:
	unsigned short machine;
	unsigned short duration;
	unsigned short startTime;
	unsigned short endTime;
	unsigned short status;
};

#endif /* TASK_H_ */
