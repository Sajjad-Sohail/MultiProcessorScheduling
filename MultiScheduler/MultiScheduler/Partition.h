#pragma once
#include"pcb.h"
struct Partition {
	pcb* pb;
	int CPU_num;
	int work_done;
	Partition *nextp;
};
