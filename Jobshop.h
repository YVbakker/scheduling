/*
 * Jobshop.h
 *
 *  Created on: 24 Sep 2019
 *      Author: yvbakker
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <fstream>
#include <iostream>
#include "Job.h"

class Jobshop
{
public:
	Jobshop();
	bool import(std::ifstream configFile);
	void calculate();
	virtual ~Jobshop();
private:
	Job* jobs[];
};



#endif /* JOBSHOP_H_ */
