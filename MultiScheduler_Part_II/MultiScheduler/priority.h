#pragma once

#include<iostream>
#include<string>
#include "pcb.h"
#include<deque>


class priority : public pcb {
private:
	int pri = 0;
	bool isRecurring = false;
public:
	priority() { process_id = 0; burst_time = 0 };
	priority(int pid, int bt)
	{
		process_id = pid;
		burst_time = bt;
	}
	int getPid()const { return process_id; }
	int getburst_time()const { return burst_time; }

	//int getPriority();
	int pprobablity;
	int existance_min;
	int existance_max;
	int b_min;
	int b_max;
	deque <priority> priority_q;
	//void show();
};
