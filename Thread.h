/*
 * Thread.h
 *
 *  Created on: 26 Sep 2019
 *      Author: yvbakker
 */

#ifndef THREAD_H_
#define THREAD_H_

class Thread
{
public:
	Thread();
	virtual ~Thread();
	unsigned char getRemainingExecutionTime();
	void setRemainingExecutionTime(unsigned char t);
private:
	unsigned char remainingExecutionTime;
};

#endif /* THREAD_H_ */
