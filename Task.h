/*
 * Task.h
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <vector>

class Task
{
public:
	Task(int aDuration, int aMachine);
	virtual ~Task();
	unsigned int getDuration();
	unsigned int getMachine();
private:
	unsigned int duration;
	unsigned int machine;
};



#endif /* TASK_H_ */
