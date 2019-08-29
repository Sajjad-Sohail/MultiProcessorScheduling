#pragma once
#include<iostream>
#include <string>
#include "pcb.h"
using namespace std;

class pcb {
protected:
	int process_no;
	int arrival_time;
	int burst_time;
	int completion_time;
	int actual_arrival_time;
	int turnaround_time;
	int waiting_time;
	int cpu;
public:
	string process_id;

	//int work_done;

	pcb() { process_id = ""; process_no = 0; arrival_time = burst_time = 0; completion_time = actual_arrival_time = turnaround_time = waiting_time = 0; cpu = NULL; }
	pcb(int pid, string typ, int at, int bt, int aat, int ct )
	{
		process_no = pid;
		arrival_time = at;
		burst_time = bt;
		process_id = typ;
		actual_arrival_time = aat;
		completion_time = ct;
		
	}
	//kaushik
	pcb(pcb *ob) {
		process_no = ob->process_no;
		arrival_time = ob->arrival_time;
		burst_time = ob->burst_time;
		process_id = ob->process_id;
		cpu = ob->cpu;
	}
	//int getWorkDone()const { return work_done; }
	//void incrementProcess() { work_done++; }
	/*virtual void show()
	{
		cout << "Inside Multiprocessor Schedular";
	}
*/
	int getPno()const { return process_no; }
	string getPid()const { return process_id; }
	int getarrival_time()const { return arrival_time; }
	int getburst_time()const { return burst_time; }
	int getactual_arrival_time()const { return actual_arrival_time; }
	int getcompletion_time()const { return completion_time; }
	int getturnaround_time()const { return turnaround_time; }
	int getwaiting_time()const { return waiting_time; } 

	int getCPU()const { return cpu; }
	void setCPU(int cpu_no) { cpu = cpu_no; }

	void put_compleTime(int c) { completion_time = c; }
	//void comple_time(int a);
	//void put_arrival_time();
	//void calculate_time();

};




