#pragma once
#include<iostream>
#include<string>
#include "pcb.h"

class sjf : public pcb {
private:
	bool isRecurring = false;
public:
	sjf() { process_id = 0; burst_time = 0 };
	sjf(int pid, int bt)
	{
		process_id = pid;
		burst_time = bt;
	}
	int getPid()const { return process_id; }
	int getburst_time()const { return burst_time; }
	deque <sjf> sjf_q;

	//void show();
	int sprobablity;
	int existance_min;
	int existance_max;
	int b_min;
	int b_max;
};
