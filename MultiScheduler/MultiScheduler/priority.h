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
	priority() { process_no = 0; arrival_time = 0; burst_time = 0; isRecurring = false; process_id = ""; }
	priority(int pid, int bt, bool isRec, int at, bool isStarv = false)
	{
		process_no = pid;
		if (isRec)
		{
			process_id = std::to_string(pid) + "/Pr(R)";
		}
		else
		{
			process_id = std::to_string(pid) + "/Pr";
		}
		if (isStarv)
		{
			process_id = process_id + "(S)";
		}
		burst_time = bt;
		isRecurring = isRec;
		arrival_time = 0;
	}
	int getPno()const { return process_no; }
	string getPid()const { return process_id; }
	int getburst_time()const { return burst_time; }
	bool getIsRecurring() const { return isRecurring; }
	
	//int getPriority();
	int pprobablity;
	int existance_min;
	int existance_max;
	int b_min;
	int b_max;
	//void show();
	pcb getPCBClass()const {
		return *this;
	}

};
