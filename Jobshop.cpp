/*
 * JobShop.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: jelle
 */

#include "Jobshop.h"
#include <algorithm>

JobShop::JobShop(std::string input)
{

}

void JobShop::addJob()
{
	jobs.push_back(Job());
}

JobShop::~JobShop()
{

}

std::string JobShop::calc()
{
	unsigned short executionTime = 0;
	while(jobs.size() != 0)
	{
		for(Job j : jobs)
		{

		}
		executionTime++;
	}
	return ""; //return string in ABNF format
}
