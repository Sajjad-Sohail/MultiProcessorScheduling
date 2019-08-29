#pragma once
#include"Partition.h"
#include"pcb.h"
#include"fcfs.h"
#include"priority.h"
#include"sjf.h"

#include"priority_nr.h"
#include"priority_r.h"

#include"fcfs_nr.h"
#include"fcfs_r.h"

#include"sjf_nr.h"
#include"sjf_r.h"

#include"linkedlist.h"
#include"statistics.h"
#include"PCBPool.h"

#define max_delay 11
#define max_cpu 4
#define initial_clock 20

class TimingWheel {

	linked_list * slot[max_delay + 1];
	//max_delay (max burst time of a job/PCB)
	int current_slot;

public:
	TimingWheel();
	deque <priority> priority_q;
	deque <sjf> sjf_q;
	deque <fcfs> fcfs_q;
	bool cpu_master[max_cpu];
	int insert(int burst_time, int CPU_num, pcb* p1);
	void schedule(int pc, PCBPool pcbP, string filename);
	void clear_curr_slot();
	void PCBpool(int pc, PCBPool pcbP);

	deque<pcb> stats_q;

	struct brstcmp {
		bool operator()(const sjf&s1, const sjf&s2)const {
			return s1.getburst_time()<s2.getburst_time();
		}
	};


};
