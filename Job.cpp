/*
 * Job.cpp
 *
 *  Created on: 30 sep. 2019
 *      Author: jelle
 */

#include "Job.h"
#include <iostream>

Job::Job() :
		status(0)
{
}

Job::Job(const Job &other)
:taskList(other.taskList), status(other.status)
{
}

Job::~Job()
{
}

// Getters
unsigned short Job::getStatus() const
{
	return status;
}

const std::vector<Task>& Job::getTaskList() const
{
	return taskList;
}

unsigned short Job::getStartTimeOfJob()
{
	return taskList.at(0).getStartTime();
}

unsigned short Job::getEndTimeOfJob()
{
	return taskList.at(taskList.size() - 1).getEndTimeOfTask();
}

// Setters
void Job::setStatus(unsigned short aStatus)
{
	status = aStatus;
}

// calculateTotalTime calculates the total time of this job with the current time
// Pre-condition = There is a argument given of the current time
// Post-condition = The function returns a unsigned short of the total time of this job
unsigned short Job::calculateTotalTimeOfJob(unsigned short aCurrentTime)
{
	unsigned short totalTime = aCurrentTime; // The start value of the total time
	for (Task t : taskList)
	{
		if (t.getStatus() == 0)
		{		// Check if the task is free
			totalTime += t.getDuration();// If task is free plus the total time with the duration of the current task
		}
		else if (t.getStatus() == 1)
		{	// Check if task is busy
			totalTime += (t.getEndTimeOfTask() - aCurrentTime); // If task is busy pluss the total time with the time when the task ends minus the current time
		}
	}
	return totalTime;
}

// addTask add a task to the task list
// Pre-condition = It required a unsigned short machine and a unsigned short duration
// Post-condition = The function added the task to the end of the task list
void Job::addTask(unsigned short aMachine, unsigned short aDuration)
{
	taskList.push_back(Task(aMachine, aDuration));
}

// setsTheMinimumStartTimeOfTasks gives the task the minimum(lowest) start time
// Pre-condition = It required a unsigned short current time
// Post-condition = The function has given every free task a minimum start time
void Job::setsTheMinimumStartTimeOfTasks(unsigned short aCurrentTime)
{
	unsigned short minimumStartTime = aCurrentTime;	// minimumStartTime = current time
	for (Task t : taskList)
	{
		if (t.getStatus() == 1)
		{				// If task is busy
			minimumStartTime += (t.getEndTimeOfTask() - aCurrentTime);// Plus the minimumStartTime with the time when the current task is finished minus the curent time
		}
		if (t.getStatus() == 0)
		{				// If task is free
			t.setStartTime(minimumStartTime);// Set the minimum start time of the task to minimumStartTime
			minimumStartTime += t.getDuration();// Plus the minimumStartTime with the duration of the current task
		}
	}
}

// setsTheMaximumStartTimeOfTasks gives the task the minimum(highest) start time
// Pre-condition = It required a unsigned short critical path
// Post-condition = The function has given every free task a maximum start time
void Job::setsTheMaximumStartTimeOfTasks(unsigned short aCriticalPath)
{
	unsigned short maximumStartTime = aCriticalPath;// maximumStartTime = current time
	for (long unsigned i = taskList.size(); i > 0; --i)
	{
		unsigned short durationOfTask = taskList.at(i - 1).getDuration();// Duration of a task is initialized so it only need to call the function once
		if (taskList.at(i - 1).getStatus() == 0)
		{		// If the task is free
			taskList.at(i - 1).setEndTime(maximumStartTime - durationOfTask);// Set the maximum end time of task with the MaximumStartTime minus durationOfTask
			maximumStartTime -= durationOfTask;	// Minus the maximumStartTime with the durationOfTask
		}
	}
}

// getFirstMachineToRun gives the first machine of this job who is free
// Pre-condition =
// Post-condition = The function returns the first machine which is free || The function returns a USHRT_MAX which means there are no free tasks
unsigned short Job::getFirstMachineToRun()
{
	for (unsigned long i = 0; i < taskList.size(); i++)
	{
		if (taskList.at(i).getStatus() == 0)
		{		// If task is free
			return taskList.at(i).getMachine();	// Returns the machine of the current task
		}
	}
	return USHRT_MAX;// Returns a USHRT_MAX when there are no free tasks of this job
}

// getBusyMachine gives the machine which is busy of this job
// Pre-condition =
// Post-condition = The function returns the first busy machine of this job
unsigned short Job::getBusyMachine()
{

	for (unsigned long i = 0; i < taskList.size(); i++)
	{
		if (taskList.at(i).getStatus() == 1)
		{			// If task is busy
			return taskList.at(i).getMachine();	// Returns the machine of the busy task
		}
	}
	return USHRT_MAX;// Returns USHRT_MAX when there are no busy machines of this job
}

// setFirstFreeTaskToBusy sets the first free machine to busy
// Pre-condition = It required a unsigned short current time
// Post-condition = The sets the first free task of this job to busy
void Job::setFirstFreeTaskToBusy(unsigned short aCurrentTime)
{
	for (unsigned long i = 0; i < taskList.size(); i++)
	{
		if (taskList.at(i).getStatus() == 0)
		{		// If status of task is free
			taskList.at(i).setStatus(1);			// Set current task to busy
			taskList.at(i).setStartTime(aCurrentTime);// Set the minimumStartTime of the current task to the current time
			taskList.at(i).setEndTimeOfTask(
					aCurrentTime + taskList.at(i).getDuration());// Set the time when the job will ends to the current time plus the duration of this job
			status = 1;									// Set this job to busy
			break;
		}
	}
}

// setTasksWhoFinishedToDone sets the tasks who are finished to done
// Pre-condition = It required a unsigned short current time
// Post-condition = Sets the tasks who are finished to done
void Job::setTasksWhoFinishedToDone(unsigned short aCurrentTime)
{
	for (unsigned long i = 0; i < taskList.size(); i++)
	{
		if (taskList.at(i).getStatus() == 1)
		{				// If task is busy
			if (taskList.at(i).getStartTime() + taskList.at(i).getDuration()
					== aCurrentTime)
			{// If the minimum start time plus the duration of this task is equal to the current time
				taskList.at(i).setStatus(2);// Set the status of this task to done
				status = 0;				// Set the status of this job to free
				break;
			}
		}
	}
}

// getDurationOfBusyTask gives the duration of the busy task
// Pre-condition = It required a unsigned short current time
// Post-condition = returns the duration of the busy task
unsigned short Job::getDurationOfBusyTask(unsigned short aCurrentTime)
{
	for (unsigned long i = 0; i < taskList.size(); i++)
	{
		if (taskList.at(i).getStatus() == 1)
		{				// If task is busy
			return (taskList.at(i).getEndTimeOfTask() - aCurrentTime);// Return the time when the task will ends minus the current time
		}
	}
	return USHRT_MAX;			// Return USHRT_MAX when there is no busy task
}

// allTasksAreDone says if all tasks are done or not
// Pre-condition =
// Post-condition = returns a false when not all tasks are finished || returns a true when all tasks are finished
bool Job::allTasksAreDone()
{
	for (unsigned long i = 0; i < taskList.size(); ++i)
	{
		if (taskList.at(i).getStatus() != 2)
		{	// If task is not done
			return false;	// Return a false because not all tasks are finished
		}
	}
	return true;				// Return a true because all tasks are finished
}

// getSlackOfFirstJobToRun give the slack of the first task which is free
// Pre-condition =
// Post-condition = return the slack of the first free task || return a USHRT_MAX when there are no free tasks
unsigned short Job::getSlackOfFirstTaskToRun()
{
	for (unsigned long i = 0; i < taskList.size(); ++i)
	{
		if (taskList.at(i).getStatus() == 0)
		{			// If tasks is free
			return taskList.at(i).calculateSlack();	// Return the slack of the first free task
		}
	}
	return USHRT_MAX;			// Return USHRT_MAX when there are no free tasks
}

// operators
Job& Job::operator =(const Job &other)
{
	taskList = other.taskList;
	status = other.status;
	return *this;
}
