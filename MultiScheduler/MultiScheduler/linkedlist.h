#pragma once
#include"Partition.h"
#include"TimingWheel.h"

class linked_list
{
private:
	Partition *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
	linked_list(linked_list *ob)
	{
		head = ob->head;
		tail = ob->tail;
	}

	void add_node(pcb *p, int cpu_no, int work_done)
	{
		Partition *tmp = new Partition;
		//kaushik
		//tmp->pb= p;
		tmp->pb = new pcb(p);
		tmp->CPU_num = cpu_no;
		tmp->nextp = NULL;
		tmp->work_done = work_done;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->nextp = tmp;
			tail = tail->nextp;
		}
	}
	int edit_node(pcb *p, int cpu_no, int work_done, linked_list *ll)

	{
		Partition *tmp = new Partition;
		linked_list *t = new linked_list(ll);
		tmp = t->head;
		//kaushik
		//tmp->pb= p;
		int i = 1;
		int flag = 0;
		while (tmp != NULL)
		{
			if (!tmp->pb)
			{

				if (cpu_no == 0)
				{
					tmp->pb = new pcb(p);
					//tmp->CPU_num = cpu_no;
					tmp->work_done = work_done;
					flag = tmp->CPU_num;
					//tmp->pb->setCPU(tmp->CPU_num);
					break;
				}
				else
				{
					if (cpu_no == tmp->CPU_num)
					{
						tmp->pb = new pcb(p);
						//tmp->CPU_num = cpu_no;
						tmp->work_done = work_done;
						flag = tmp->CPU_num;
						tmp->pb->setCPU(tmp->CPU_num);
						break;
					}
				}
			}
			else
			{
				//tmp = tmp->nextp;
			}
			if (i == 4)
			{
				flag = 0;
				break;
			}
			i++;
			tmp = tmp->nextp;

		}
		return flag;
	}
	int getCPU(pcb *p)
	{
		pcb ptpcb = new pcb(p);
		return ptpcb.getCPU();
	}
	void display(linked_list *ll, ostream &outfile)
	{
		Partition *tmp;
		linked_list *t = new linked_list(ll);
		tmp = t->head;
		//tmp = head;
		int i = 1;
		bool flag = false;
		if (tmp != NULL)
		{
			cout << "\nCPU : 1\t\t\tCPU : 2\t\t\tCPU : 3\t\t\tCPU : 4\n";
			outfile << "\nCPU : 1\t\t\tCPU : 2\t\t\tCPU : 3\t\t\tCPU : 4\n";

			while (true)
			{
				if (tmp->pb != NULL)
				{
					string temp = tmp->pb->process_id;
					cout << "Type: " << temp << "\t\t";
					outfile << "Type: " << temp << "\t\t";
				}
				else
				{
					cout << "IDLE\t\t\t";
					outfile << "IDLE\t\t\t";

				}
				tmp = tmp->nextp;

				if (i == 4)
				{
					break;
				}
				i++;
			}
			tmp = head;
			i = 1;
			cout << "\n";
			outfile << "\n";


			while (true)
			{
				if (tmp->pb != NULL)
				{
					cout << "WD/BT: " << tmp->work_done << "/" << tmp->pb->getburst_time() << "\t\t";
					outfile << "WD/BT: " << tmp->work_done << "/" << tmp->pb->getburst_time() << "\t\t";

				}
				else
				{
					cout << "\t\t\t";
					outfile << "\t\t\t";

				}
				tmp = tmp->nextp;

				if (i == 4)
				{
					break;
				}
				i++;

			}
			cout << "\n\n";
			outfile << "\n\n";

			/*tmp = head;
			if (tmp->pb != NULL)
			{
			string temp = tmp->pb->process_id;
			cout << "\nCPU" << tmp->CPU_num << "\t";
			cout << "PID: " << tmp->pb->getPno() << "\t";
			cout << "Burst Time: " << tmp->pb->getburst_time() << "\t";
			cout << "Work Done: " << tmp->work_done << "\n";
			}
			else
			{
			cout << "\nRest All CPU are IDLE\t";
			}
			tmp = tmp->nextp;*/

		}
	}
	void add_dummy(int cpu)
	{
		Partition *tmp = new Partition;
		//kaushik
		//tmp->pb= p;
		tmp->pb = NULL;
		tmp->CPU_num = cpu;
		tmp->nextp = NULL;
		tmp->work_done = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->nextp = tmp;
			tail = tail->nextp;
		}
	}
	void check_node(linked_list *ll, deque<pcb> &stats_q, int clock)
	{
		Partition *tmp;
		linked_list *t = new linked_list(ll);
		tmp = t->head;

		int i = 1;
		while (true)
		{
			if (tmp->pb != NULL)
			{
				if (tmp->work_done == tmp->pb->getburst_time())
				{

					for (unsigned i = 0; i < stats_q.size(); i++)
					{
						if (stats_q[i].getPid() == tmp->pb->getPid() && stats_q[i].getPno() == tmp->pb->getPno())
						{
							stats_q[i].put_compleTime(clock);
						}
					}

					tmp->pb = NULL;
					//tmp->CPU_num = NULL;
					tmp->work_done = NULL;
				}
			}
			tmp = tmp->nextp;
			if (i == 4)
			{
				break;
			}
			i++;
		}
	}
	void clear_node(linked_list *ll)
	{

		Partition *tmp;
		linked_list *t = new linked_list(ll);
		tmp = t->head;
		int i = 1;
		while (true)
		{
			tmp->pb = NULL;
			tmp->CPU_num = i;
			tmp->work_done = NULL;
			tmp = tmp->nextp;
			if (i == 4)
			{
				break;
			}
			i++;
		}
	}
	void insert_position(int pos, pcb *p, int cpu_no, int work_done)
	{
		Partition *pre = new Partition;
		Partition *cur = new Partition;
		Partition *temp = new Partition;
		cur = head;
		for (int i = 1; i <= pos; i++)
		{
			pre = cur;
			cur = cur->nextp;
		}
		temp->pb = new pcb(p);
		temp->CPU_num = cpu_no;
		temp->work_done = work_done;
		pre->nextp = temp;
		temp->nextp = cur;
	}

	Partition* deleteMid(Partition *head)
	{
		// Base cases
		if (head == NULL)
			return NULL;
		if (head->nextp == NULL)
		{
			delete head;
			return NULL;
		}

		// Initialize slow and fast pointers to reach
		// middle of linked list
		Partition *slow_ptr = head;
		Partition *fast_ptr = head;

		// Find the middle and previous of middle.
		Partition *prev; // To store previous of slow_ptr
		while (fast_ptr != NULL && fast_ptr->nextp != NULL)
		{
			fast_ptr = fast_ptr->nextp->nextp;
			prev = slow_ptr;
			slow_ptr = slow_ptr->nextp;
		}

		//Delete the middle node
		prev->nextp = slow_ptr->nextp;
		delete slow_ptr;

		return head;
	}
};