/*
 * Task.h
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#ifndef TASK_H_
#define TASK_H_

class Task
{
public:
	Task(unsigned char order, unsigned char duration, unsigned char machine);
	virtual ~Task();
	unsigned char getDuration();
	unsigned char getOrder();
	unsigned char getMachine();
private:
	unsigned char duration;
	unsigned char order;
	unsigned char machine;
};



#endif /* TASK_H_ */
