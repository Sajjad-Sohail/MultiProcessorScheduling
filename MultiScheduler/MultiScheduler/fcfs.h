#pragma once
#include<iostream>
#include<string>
#include "pcb.h"

class fcfs : public pcb {
private:
	bool isRecurring = false;
protected:
public:
	fcfs() { process_no = 0; burst_time = 0; arrival_time = 0; fprobablity = 0; isRecurring = false; process_id = ""; }
	fcfs(int pid, int bt, bool isRec, int at, int fp)
	{
		process_no = pid;
		if (isRec)
		{
			process_id = std::to_string(pid) + "/FCFS(R)";
		}
		else
		{
			process_id = std::to_string(pid) + "/FCFS";
		}
		fprobablity = fp;
		burst_time = bt;
		isRecurring = isRec;
		arrival_time = at;
	}
	int getPno()const { return process_no; }
	bool getIsRecurring() const { return isRecurring; }

	string getPid()const { return process_id; }
	int getburst_time()const { return burst_time; }
	//void show();
	int fprobablity;
	int getFprobablity()const { return fprobablity; }

	pcb getPCBClass()const {
		return *this;
	}
};
#pragma once
