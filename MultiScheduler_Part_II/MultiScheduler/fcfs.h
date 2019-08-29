#pragma once
#include<iostream>
#include<string>
#include "pcb.h"

class fcfs : public pcb {
private:
	bool isRecurring = false;
protected:
public:
	fcfs() { process_id = 0; burst_time = 0 };
	fcfs(int pid, int bt)
	{
		process_id = pid;
		burst_time = bt;
	}
	int getPid()const { return process_id; }
	int getburst_time()const { return burst_time; }
	deque <fcfs> fcfs_q;
	//void show();
	int fprobablity;
	int existance_min;
	int existance_max;
	int b_min;
	int b_max;

};
#pragma once
