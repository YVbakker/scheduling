/*
 * Main.cpp
 *
 *  Created on: 23 Sep 2019
 *      Author: yvbakker
 */

#include <iostream>
#include "Task.h"
#include "Job.h"
#include "JobShop.h"
#include "vector"

int main(int argc, char **argv) {

	std::vector<int>   waardes;
	waardes.push_back(3); // jobs
	waardes.push_back(3); // machines

	waardes.push_back(2); // duration
	waardes.push_back(1); // machine

	waardes.push_back(3); // duration
	waardes.push_back(4); // machine

	waardes.push_back(2); // duration
	waardes.push_back(5); // machine

	waardes.push_back(2); // duration
	waardes.push_back(1); // machine

	waardes.push_back(5); // duration
	waardes.push_back(1); // machine

	waardes.push_back(2); // duration
	waardes.push_back(4); // machine

	waardes.push_back(7); // duration
	waardes.push_back(6); // machine

	waardes.push_back(4); // duration
	waardes.push_back(7); // machine

	waardes.push_back(5); // duration
	waardes.push_back(3); // machine

	JobShop js1(waardes);

	std::cout << "--------------------------" << std::endl;

	js1.run();

	std::cout << "--------------------------" << std::endl;

	js1.getCriticalPath();

	std::cout << "--------------------------" << std::endl;



//	int nJobs = 6;
//		int nThreads = 6; //machines
//
//		unsigned char threads[6];
//
//		unsigned char jobs[6][6][2] = // first dim #jobs, second dim #tasks, third dim: [thread,time]
//		{
//				{{2,1},{0,3},{1,6},{3,7},{5,3},{4,6}},
//				{{1,8},{2,5},{4,10},{5,10},{0,10},{3,4}},
//				{{2,5},{3,4},{5,8},{0,9},{1,1},{4,7}},
//				{{1,5},{0,5},{2,5},{3,3},{4,8},{5,9}},
//				{{2,9},{1,3},{4,5},{5,4},{0,3},{3,1}},
//				{{1,3},{3,3},{5,9},{0,10},{4,4},{2,1}}
//		};
//
//
//
//
//		unsigned char critical = 0;
//
//		for(int i = 0; i < nJobs; ++i)
//		{
//			int totalJobTime = 0;
//			for(int j = 0; j < sizeof(jobs[i])/sizeof(jobs[i][j]); ++j) // divide by 2 because total sizeof jobs[i] needs to be divided by the third dim
//			{
//				totalJobTime += jobs[i][j][1]; // element 1 of pair = task time
//				if(totalJobTime > critical)
//				{
//					critical = totalJobTime;
//				}
//			}
//		}
//		std::cout<<"Critical time = "<<static_cast<unsigned short>(critical)<<std::endl;
//
//
//
//		for(int t = 0; t < critical; ++t)
//		{
//			for(int j = 0; j < nThreads; ++j)
//			{
//				unsigned char threadTimeLeft = threads[j];
//				if(threadTimeLeft > 0) //removed != value shouldn't be below 0
//				{
//					threads[j] = threadTimeLeft - 1; //run task for 1 time unit
//				}
//				else
//				{
//					//assign new task to thread TODO determine which task to assign
//				}
//			}
//		}
}


