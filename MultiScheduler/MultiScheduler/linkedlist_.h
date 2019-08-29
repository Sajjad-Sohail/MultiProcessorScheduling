#pragma once
#include"Partition.h"
#include"TimingWheel.h"
class linked_list
{
private:
	Partition *head, *tail;
public:
	linked_list();
	linked_list(linked_list *ob);

	void add_node(pcb *p, int cpu_no, int work_done);
	int edit_node(pcb *p, int cpu_no, int work_done, linked_list *ll);
	int getCPU(pcb *p);
	void display(linked_list *ll, ostream &outfile);
	void add_dummy(int cpu);
	void check_node(linked_list *ll, deque<pcb> &stats_q, int clock);
	void clear_node(linked_list *ll);
	void insert_position(int pos, pcb *p, int cpu_no, int work_done);
	
	Partition* deleteMid(Partition *head);
};