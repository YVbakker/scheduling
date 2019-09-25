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

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	waardes.push_back(4); // duration
	waardes.push_back(10); // machine

	JobShop js1(waardes);

	std::cout << "--------------------------" << std::endl;
//	std::cout << js1.getJobs() << std::endl;
//	std::cout << js1.getMachines() << std::endl;

	std::vector<Job> x = js1.getJobList();

	std::cout << x.at(0).getTotalTime() << std::endl; 	// output totale tijd job 1
	std::cout << x.at(1).getTotalTime() << std::endl;	// output totale tijd job 2
	std::cout << x.at(2).getTotalTime() << std::endl;	// output totale tijd job 3



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


