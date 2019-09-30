/*
 * JobShop.cpp
 *
 *  Created on: 24 sep. 2019
 *      Author: jelle & yael
 */

#include "Jobshop.h"
#include <algorithm>

JobShop::JobShop(std::string input)
{
	std::cout << input << std::endl;
	for (int i = 0; i < 6; ++i)
		addJob();
	jobs.at(0).addTask(2, 1);
	jobs.at(0).addTask(0, 3);
	jobs.at(0).addTask(1, 6);
	jobs.at(0).addTask(3, 7);
	jobs.at(0).addTask(5, 3);
	jobs.at(0).addTask(4, 6);
	jobs.at(1).addTask(1, 8);
	jobs.at(1).addTask(2, 5);
	jobs.at(1).addTask(4, 10);
	jobs.at(1).addTask(5, 10);
	jobs.at(1).addTask(0, 10);
	jobs.at(1).addTask(3, 4);
	jobs.at(2).addTask(2, 5);
	jobs.at(2).addTask(3, 4);
	jobs.at(2).addTask(5, 8);
	jobs.at(2).addTask(0, 9);
	jobs.at(2).addTask(1, 1);
	jobs.at(2).addTask(4, 7);
	jobs.at(3).addTask(1, 5);
	jobs.at(3).addTask(0, 5);
	jobs.at(3).addTask(2, 5);
	jobs.at(3).addTask(3, 3);
	jobs.at(3).addTask(4, 8);
	jobs.at(3).addTask(5, 9);
	jobs.at(4).addTask(2, 9);
	jobs.at(4).addTask(1, 3);
	jobs.at(4).addTask(4, 5);
	jobs.at(4).addTask(5, 4);
	jobs.at(4).addTask(0, 3);
	jobs.at(4).addTask(3, 1);
	jobs.at(5).addTask(1, 3);
	jobs.at(5).addTask(3, 3);
	jobs.at(5).addTask(5, 9);
	jobs.at(5).addTask(0, 10);
	jobs.at(5).addTask(4, 4);
	jobs.at(5).addTask(2, 1);
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
	while (jobs.size() > 0)
	{
		//sorteer jobs op least slack
		std::sort(jobs.begin(), jobs.end(), std::greater<Job>());
		//begin met uitvoeren van eerste taken, niet uitvoeren als een thread al in gebruik is
		for (Job j : jobs)
		{
			Task t = j.getNextTask(); //get eerstvolgende taak in de job, de eerste job in de lijst met jobs is diegene met de hoogste slack.
			unsigned char m = t.getMachine(); //get machine van de taak
			unsigned char d = t.getDuration(); //get duration van de taak
			unsigned char ret = threads.at(m).getRemainingExecutionTime(); //get remaining execution time van de thread behorende bij de machine van de taak
			if (ret != 0) //als op de thread behorende bij de machine (thread betekend hetzelfde als machine) de remaining time niet 0 is, haal er 1 vanaf. De thread is niet vrij!
			{
				threads.at(m).setRemainingExecutionTime(ret - 1);
			}
			else
			{
				if (executionTime != 0) //als het niet aan het begin van het uitvoeren is
				{
					j.deleteCompletedTask(); //taak is volledig uitgevoerd
					threads.at(m).setRemainingExecutionTime(0);
				}
				else
				{
					threads.at(m).setRemainingExecutionTime(d);
				}
			}
			std::cout << j.size() << std::endl;
		}
		//hoog de execution tijd met 1 op en begin opnieuw, tot er geen taken meer over zijn
		executionTime++;
	}
	return ""; //return string in ABNF format
}
