/*
 * Job.h
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#ifndef JOB_H_
#define JOB_H_

#include "Task.h"

class Job
{
public:
	Job(unsigned char nTasks, unsigned char jobId);
	unsigned char getTotalDuration();
	virtual ~Job();
private:
	Task* tasks[];
	unsigned char jobId;
	unsigned char duration = 0;
};



#endif /* JOB_H_ */
