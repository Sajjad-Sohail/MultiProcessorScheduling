#pragma once
#include<iostream>
#include<string>
#include "pcb.h"

class sjf : public pcb {
private:
	bool isRecurring = false;
public:
	sjf() { process_no = 0; burst_time = 0; arrival_time = 0; sprobablity = 0; isRecurring = false; process_id = ""; }
	sjf(int pid, int bt, bool isRec, int at, int sp, bool isStarv = false)
	{
		process_no = pid;
		if (isRec)
		{
			process_id = std::to_string(pid) + "/SJF(R)";
		}
		else
		{
			process_id = std::to_string(pid) + "/SJF";
		}
		if (isStarv)
		{
			process_id = process_id + "(S)";
		}
		sprobablity = sp;
		burst_time = bt;
		isRecurring = isRec;
		arrival_time = at;
	}
	int getburst_time()const { return burst_time; }
	 pcb getPCBClass()const { 
		return *this;
	}
	 int getPno()const { return process_no; }
	 string getPid()const { return process_id; }
	 bool getIsRecurring() const { return isRecurring; }
	 int getSprobablity()const { return sprobablity; }
	//void show();
	int sprobablity;
	

};
