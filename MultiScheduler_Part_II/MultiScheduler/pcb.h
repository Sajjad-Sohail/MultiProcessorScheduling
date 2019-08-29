#pragma once
#include<iostream>
#include <string>
#include "pcb.h"
using namespace std;

class pcb {
protected:
	int process_id;
	int arrival_time;
	int burst_time;
	int completion_time;
	int actual_arrival_time;
	int turnaround_time;
	int waiting_time;
public:
	pcb() { process_id = 0; arrival_time = burst_time = 0; completion_time = actual_arrival_time = turnaround_time = waiting_time = 0; }
	pcb(int pid, int at, int bt)
	{
		process_id = pid;
		arrival_time = at;
		burst_time = bt;
	}
	/*virtual void show()
	{
		cout << "Inside Multiprocessor Schedular";
	}
*/
	/*int getPid()const { return process_id; }
	int getarrival_time()const { return arrival_time; }
	int getburst_time()const { return burst_time; }
	int getactual_arrival_time()const { return actual_arrival_time; }
	int getcompletion_time()const { return completion_time; }
	int getturnaround_time()const { return turnaround_time; }
	int getwaiting_time()const { return waiting_time; } */

	//void comple_time(int a);
	//void put_arrival_time();
	//void calculate_time();

};




