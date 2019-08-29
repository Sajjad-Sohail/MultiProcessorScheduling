#include"stdafx.h"

#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
#include <sstream> 
#include<stdlib.h>
#include<time.h>
#include<deque>
#include<iomanip>
#include<algorithm>
#include <fstream>
//-------------------------------

#include"priority_nr.h"
#include"priority_r.h"

#include"fcfs_nr.h"
#include"fcfs_r.h"

#include"sjf_nr.h"
#include"sjf_r.h"

#include"TimingWheel.h"
#include"Partition.h"
#include"statistics.h"


void TimingWheel::PCBpool(int pc, PCBPool pcbP)
{
	int i = 0;
	srand(time(NULL));
	int pid_new = -1;
	do {
		int R = rand() % 100 + 1;
		if (R <= pc)
		{
			if (R >= pcbP.pr_ex_min && R <= pcbP.pr_ex_max)
			{
				R = rand() % 100 + 1;
				//R = 59;
				if (R <= pcbP.pr_r_prob)
				{
					R = rand() % (pcbP.pr_b_max - pcbP.pr_b_min + 1) + pcbP.pr_b_min;
					//cout << "\n\tPriority recursive Burst Time: " << R;
					if (!priority_q.empty())
					{
						pid_new = priority_q.back().getPno();
					}
					priority_q.insert(priority_q.end(), priority(pid_new + 1, R, true, i));
				}
				else
				{
					R = rand() % (pcbP.pr_b_max - pcbP.pr_b_min + 1) + pcbP.pr_b_min;
					//cout << "\n\tPriority non - recursive Burst Time: " << R;
					if (!priority_q.empty())
					{
						pid_new = priority_q.back().getPno();
					}
					priority_q.insert(priority_q.end(), priority(pid_new + 1, R, false, i));
				}
			}
			else if (R >= pcbP.sjf_ex_min && R <= pcbP.sjf_ex_max)
			{
				R = rand() % 100 + 1;
				int ST = rand() % (pcbP.st_max - pcbP.st_min + 1) + pcbP.st_min;
				if (R <= pcbP.sjf_r_prob)
				{
					R = rand() % (pcbP.sjf_b_max - pcbP.sjf_b_min + 1) + pcbP.sjf_b_min;
					//cout << "\n\tSJF recursive Burst Time: " << R;
					if (!sjf_q.empty())
					{
						pid_new = sjf_q.back().getPno();
					}
					sjf_q.insert(sjf_q.end(), sjf(pid_new + 1, R, true, i, ST));
				}
				else
				{
					R = rand() % (pcbP.sjf_b_max - pcbP.sjf_b_min + 1) + pcbP.sjf_b_min;

					//cout << "\n\tSJF non - recursive Burst Time: " << R;
					if (!sjf_q.empty())
					{
						pid_new = sjf_q.back().getPno();
					}
					sjf_q.insert(sjf_q.end(), sjf(pid_new + 1, R, false, i, ST));
				}
			}
			else if (R >= pcbP.fcfs_ex_min && R <= pcbP.fcfs_ex_max)
			{
				R = rand() % 100 + 1;
				int ST = rand() % (pcbP.st_max - pcbP.st_min + 1) + pcbP.st_min;

				if (R <= pcbP.fcfs_r_prob)
				{
					R = rand() % (pcbP.fcfs_b_max - pcbP.fcfs_b_min + 1) + pcbP.fcfs_b_min;
					//cout << "\n\tFCFS recursive Burst Time: " << R;
					if (!fcfs_q.empty())
					{
						pid_new = fcfs_q.back().getPno();
					}
					fcfs_q.insert(fcfs_q.end(), fcfs(pid_new + 1, R, true, i, ST));
				}
				else
				{
					R = rand() % (pcbP.fcfs_b_max - pcbP.fcfs_b_min + 1) + pcbP.fcfs_b_min;
					//cout << "\n\tFCFS non - recursive Burst Time: " << R;
					if (!fcfs_q.empty())
					{
						pid_new = fcfs_q.back().getPno();
					}
					fcfs_q.insert(fcfs_q.end(), fcfs(pid_new + 1, R, false, i, ST));
				}
			}
			else
			{
			//	cout << "\n\t No PCB created";
			}
		}
		i++;

		if (i == initial_clock)
		{
			break;
		}
	} while (true);
	

}
void TimingWheel::schedule(int pc, PCBPool pcbP, string filename)
{

	ofstream outfile(filename);
	cout << "-----Initial Pool of PCB's Created-----\n";
	outfile << "-----Initial Pool of PCB's Created-----\n";
	deque<int>::size_type sz_p = priority_q.size();
	deque<int>::size_type sz_s = sjf_q.size();
	deque<int>::size_type sz_f = fcfs_q.size();
	cout << "Priority: " << sz_p << endl;
	cout << "SJF: " << sz_s << endl;
	cout << "FCFS: " << sz_f << endl;
	outfile << "Priority: " << sz_p << endl;
	outfile << "SJF: " << sz_s << endl;
	outfile << "FCFS: " << sz_f << endl;

	int sim;
	cout << "\nInput Simulation Time: ";
	outfile << "\nInput Simulation Time: ";

	cin >> sim;
	int clock = 0;

	while (true)
	{
		int i = 0;
		srand(time(NULL));
		int pid_new = -1;

		//cout << "\nClock at: " << i;
		int R = rand() % 100 + 1;
		//cout << "\n"<<R;
		if (R <= pc)
		{
			if (R >= pcbP.pr_ex_min && R <= pcbP.pr_ex_max)
			{
				R = rand() % 100 + 1;
				//R = 59;
				if (R <= pcbP.pr_r_prob)
				{
					R = rand() % (pcbP.pr_b_max - pcbP.pr_b_min + 1) + pcbP.pr_b_min;
					//cout << "\n\tPriority recursive Burst Time: " << R;
					if (!priority_q.empty())
					{
						pid_new = priority_q.back().getPno();
					}
					priority_q.insert(priority_q.end(), priority(pid_new + 1, R, true, initial_clock+priority_q.front().getburst_time()+clock));
				}
				else
				{
					R = rand() % (pcbP.pr_b_max - pcbP.pr_b_min + 1) + pcbP.pr_b_min;
					//cout << "\n\tPriority non - recursive Burst Time: " << R;
					if (!priority_q.empty())
					{
						pid_new = priority_q.back().getPno();
					}
					priority_q.insert(priority_q.end(), priority(pid_new + 1, R, false, initial_clock + clock));
				}
			}
			else if (R >= pcbP.sjf_ex_min && R <= pcbP.sjf_ex_max)
			{
				R = rand() % 100 + 1;
				int ST = rand() % (pcbP.st_max - pcbP.st_min + 1) + pcbP.st_min;

				if (R <= pcbP.sjf_r_prob)
				{
					R = rand() % (pcbP.sjf_b_max - pcbP.sjf_b_min + 1) + pcbP.sjf_b_min;
					//cout << "\n\tSJF recursive Burst Time: " << R;
					if (!sjf_q.empty())
					{
						pid_new = sjf_q.back().getPno();
					}
					//sjf_q.insert(sjf_q.end(), sjf(pid_new + 1, R, true, i, ST));
					sjf_q.insert(sjf_q.end(), sjf(pid_new + 1, R, true, initial_clock+ sjf_q.front().getburst_time() + clock,ST));
				}
				else
				{
					R = rand() % (pcbP.sjf_b_max - pcbP.sjf_b_min + 1) + pcbP.sjf_b_min;

					//cout << "\n\tSJF non - recursive Burst Time: " << R;
					if (!sjf_q.empty())
					{
						pid_new = sjf_q.back().getPno();
					}
					sjf_q.insert(sjf_q.end(), sjf(pid_new + 1, R, false, initial_clock + clock,ST));
				}
			}
			else if (R >= pcbP.fcfs_ex_min && R <= pcbP.fcfs_ex_max)
			{
				R = rand() % 100 + 1;
				int ST = rand() % (pcbP.st_max - pcbP.st_min + 1) + pcbP.st_min;

				if (R <= pcbP.fcfs_r_prob)
				{
					R = rand() % (pcbP.fcfs_b_max - pcbP.fcfs_b_min + 1) + pcbP.fcfs_b_min;
					//cout << "\n\tFCFS recursive Burst Time: " << R;
					if (!fcfs_q.empty())
					{
						pid_new = fcfs_q.back().getPno();
					}
					fcfs_q.insert(fcfs_q.end(), fcfs(pid_new + 1, R, true, initial_clock + fcfs_q.front().getburst_time() + clock, ST));
				}
				else
				{
					R = rand() % (pcbP.fcfs_b_max - pcbP.fcfs_b_min + 1) + pcbP.fcfs_b_min;
					//cout << "\n\tFCFS non - recursive Burst Time: " << R;
					if (!fcfs_q.empty())
					{
						pid_new = fcfs_q.back().getPno();
					}
					fcfs_q.insert(fcfs_q.end(), fcfs(pid_new + 1, R, false, initial_clock + clock, ST));
				}
			}
			else
			{
				//	cout << "\n\t No PCB created";
			}
		}

		//------------------------------------------------------------
		cout << "At Clock " << clock + initial_clock;
		outfile << "At Clock " << clock + initial_clock;
		Partition* prtn;
		//Section for PCB Generation Ends
		//Section for inserting partition if cpu free
		current_slot = (clock + max_delay) % max_delay;
		sjf_r sjfr;
		//slot[current_slot] = new linked_list();
		for (i = 1; i <= max_cpu; i++)
		{
			if (!priority_q.empty())
			{
				int flag = 0;
				if (priority_q.front().getarrival_time() <= clock + initial_clock)
				{
					flag = insert(priority_q.front().getburst_time(), 1, &priority_q.front().getPCBClass());
					if (!priority_q.empty())
					{
						pid_new = priority_q.back().getPno();
					}
					if (flag != 0)
					{
						if (priority_q.front().getIsRecurring())
						{
							R = rand() % (pcbP.r_sl_max - pcbP.r_sl_min + 1) + pcbP.r_sl_min;
							priority_q.insert(priority_q.end(), priority(pid_new + 1,priority_q.front().getburst_time(), true, priority_q.front().getburst_time() + R));
							stats_q.insert(stats_q.end(), pcb(priority_q.front().getPno(), priority_q.front().getPid(), priority_q.front().getarrival_time(), priority_q.front().getburst_time(), clock + initial_clock, priority_q.front().getcompletion_time()));

							//pror.setSleepTime(clock + R);
							priority_q.pop_front();
						}
						else
						{
							stats_q.insert(stats_q.end(), pcb(priority_q.front().getPno(), priority_q.front().getPid(), priority_q.front().getarrival_time(), priority_q.front().getburst_time(), clock + initial_clock, priority_q.front().getcompletion_time()));

							priority_q.pop_front();
						}
					}
				}
			}
		}
		for (i = 1; i <= max_cpu; i++)
		{
			if (!sjf_q.empty())
			{
				sort(sjf_q.begin(), sjf_q.end(), brstcmp());

				int flag = 0;
				if (sjf_q.front().getarrival_time() <= clock + initial_clock)
				{
					flag = insert(sjf_q.front().getburst_time(), 1, &sjf_q.front().getPCBClass());
					if (!sjf_q.empty())
					{
						pid_new = sjf_q.back().getPno();
					}
					if (flag != 0)
					{
						if (sjf_q.front().getIsRecurring())
						{
							R = rand() % (pcbP.r_sl_max - pcbP.r_sl_min + 1) + pcbP.r_sl_min;
							sjf_q.insert(sjf_q.end(), sjf(pid_new + 1, sjf_q.front().getburst_time(), true, clock + sjf_q.front().getburst_time() + R,sjf_q.front().getSprobablity()));
							stats_q.insert(stats_q.end(), pcb(sjf_q.front().getPno(), sjf_q.front().getPid(), sjf_q.front().getarrival_time(), sjf_q.front().getburst_time(), clock + initial_clock, sjf_q.front().getcompletion_time()));

							
							sjf_q.pop_front();

						}
						else
						{
							stats_q.insert(stats_q.end(), pcb(sjf_q.front().getPno(), sjf_q.front().getPid(), sjf_q.front().getarrival_time(), sjf_q.front().getburst_time(), clock + initial_clock, sjf_q.front().getcompletion_time()));

							sjf_q.pop_front();
						}
					}
				}
			}
		}
		for (i = 1; i <= max_cpu; i++)
		{
			if (!fcfs_q.empty())
			{
				int flag = 0;
				if (fcfs_q.front().getarrival_time() <= clock + initial_clock)
				{
					flag = insert(fcfs_q.front().getburst_time(), 1, &fcfs_q.front().getPCBClass());
					if (!fcfs_q.empty())
					{
						pid_new = fcfs_q.back().getPno();
					}
					if (flag != 0)
					{
						if (fcfs_q.front().getIsRecurring())
						{
							R = rand() % (pcbP.r_sl_max - pcbP.r_sl_min + 1) + pcbP.r_sl_min;

							fcfs_q.insert(fcfs_q.end(), fcfs(pid_new + 1, fcfs_q.front().getburst_time(), true, clock + fcfs_q.front().getburst_time() + R, fcfs_q.front().getFprobablity()));
							stats_q.insert(stats_q.end(), pcb(fcfs_q.front().getPno(), fcfs_q.front().getPid(), fcfs_q.front().getarrival_time(), fcfs_q.front().getburst_time(), clock + initial_clock, fcfs_q.front().getcompletion_time()));

							fcfs_q.pop_front();
						}
						else
						{
							stats_q.insert(stats_q.end(), pcb(fcfs_q.front().getPno(), fcfs_q.front().getPid(), fcfs_q.front().getarrival_time(), fcfs_q.front().getburst_time(), clock + initial_clock, fcfs_q.front().getcompletion_time()));

							fcfs_q.pop_front();
						}
					}
				}
			}
		}


		slot[current_slot]->display(slot[current_slot], outfile);
		slot[current_slot]->check_node(slot[current_slot], stats_q, clock + initial_clock);
		if (clock != 0)
		{
			if (current_slot != 0)
			{
				slot[current_slot - 1]->clear_node(slot[current_slot - 1]);
			}
			else
			{
				slot[max_delay]->clear_node(slot[max_delay]);
			}
		}
		for (unsigned i = 0; i < sjf_q.size(); i++)
		{
			if (((clock + initial_clock) - sjf_q[i].getarrival_time()) == sjf_q[i].getSprobablity())
			{
				int pno = sjf_q[i].getPno() + 50;
				int bt = sjf_q[i].getburst_time();
				bool isrec = sjf_q[i].getIsRecurring();
				int at = sjf_q[i].getarrival_time();
				//priority_q.insert(priority_q.end(), priority(pno, bt, isrec, at));
				priority_q.push_front(priority(pno, bt, isrec, at, 1));
				//stats_q.insert(stats_q.end(), pcb(priority_q.front().getPno(), priority_q.front().getPid(), priority_q.front().getarrival_time(), priority_q.front().getburst_time(), priority_q.front().getactual_arrival_time(), priority_q.front().getcompletion_time()));
				if (sjf_q[i].getIsRecurring())
				{
					R = rand() % (pcbP.r_sl_max - pcbP.r_sl_min + 1) + pcbP.r_sl_min;
					sjf_q.insert(sjf_q.end(), sjf(pno, bt, true, clock + sjf_q[i].getburst_time() + R, sjf_q.front().getSprobablity()));
					sjf_q.erase(sjf_q.begin() + i);
				}
				else
				{
					sjf_q.erase(sjf_q.begin() + i);
				}
			}
		}
		for (unsigned i = 0; i < fcfs_q.size(); i++)
		{
			if (((clock + initial_clock) - fcfs_q[i].getarrival_time()) == fcfs_q[i].getFprobablity())
			{
				int pno = fcfs_q[i].getPno()+100;
				int bt = fcfs_q[i].getburst_time();
				bool isrec = fcfs_q[i].getIsRecurring();
				int at = fcfs_q[i].getarrival_time();
				//priority_q.insert(priority_q.end(), priority(pno, bt, isrec, at));
				sjf_q.push_front(sjf(pno, bt, isrec, at, fcfs_q[i].getFprobablity(), 1));
				//stats_q.insert(stats_q.end(), pcb(sjf_q.front().getPno(), sjf_q.front().getPid(), sjf_q.front().getarrival_time(), sjf_q.front().getburst_time(), sjf_q.front().getactual_arrival_time(), sjf_q.front().getcompletion_time()));

				if (fcfs_q[i].getIsRecurring())
				{
					R = rand() % (pcbP.r_sl_max - pcbP.r_sl_min + 1) + pcbP.r_sl_min;
					fcfs_q.insert(fcfs_q.end(), fcfs(pno, bt, true, clock + fcfs_q[i].getburst_time() + R, fcfs_q.front().getFprobablity()));
					fcfs_q.erase(fcfs_q.begin() + i);
				}
				else
				{
					fcfs_q.erase(fcfs_q.begin() + i);
				}
			}

		}
		cout << "-----Queue Status-----\n";
		outfile << "-----Queue Status-----\n";
		deque<int>::size_type sz_p = priority_q.size();
		deque<int>::size_type sz_s = sjf_q.size();
		deque<int>::size_type sz_f = fcfs_q.size();
		cout << "Priority: " << sz_p << "\t\t" << "SJF: " << sz_s << "\t\t" << "FCFS: " << sz_f << "\n" << endl;
		outfile << "Priority: " << sz_p << "\t\t" << "SJF: " << sz_s << "\t\t" << "FCFS: " << sz_f << "\n" << endl;

		//code for break
		clock++;
		if (clock == sim)
		{
			cout << "\n\n\nSummary\n\nID\t\t\tArrival\tBurst\tCompletion\tTurnaround\tWaiting \n";
			outfile << "\n\n\nSummary\n\nID\t\t\tArrival\tBurst\tCompletion\tTurnaround\tWaiting \n";

			for (unsigned i = 0; i < stats_q.size(); i++)
			{
				string num;
				if(stats_q[i].getPid().length() >7)
				{
					num = "\t\t";
				}
				else
				{
					num = "\t\t\t";
				}
				if (stats_q[i].getcompletion_time() != 0)
				{
					cout << stats_q[i].getPid() << num << stats_q[i].getarrival_time() << "\t" << stats_q[i].getburst_time() << "\t" << stats_q[i].getcompletion_time() << "\t\t" << stats_q[i].getactual_arrival_time() - stats_q[i].getarrival_time() << "\t\t" << (stats_q[i].getactual_arrival_time() - stats_q[i].getarrival_time()) + stats_q[i].getburst_time() << endl;
					outfile << stats_q[i].getPid() << num << stats_q[i].getarrival_time() << "\t" << stats_q[i].getburst_time() << "\t" << stats_q[i].getcompletion_time() << "\t\t" << stats_q[i].getactual_arrival_time() - stats_q[i].getarrival_time() << "\t\t" << (stats_q[i].getactual_arrival_time() - stats_q[i].getarrival_time()) + stats_q[i].getburst_time() << endl;

				}
			}
			break;

		}
	}
}


	int TimingWheel::insert(int burst_time, int CPU_num, pcb* p1)
	{
		int flag = 0;
		int mxdly = max_delay;
		CPU_num = 0;
		for (int i = 0; i < burst_time; i++)
		{
			int slot_no = current_slot;
			slot_no = (slot_no + i + mxdly) % mxdly;
			flag = slot[slot_no]->edit_node(&*p1, CPU_num, i + 1, slot[slot_no]);
			if (i == 0)
			{
				if (flag == 0)
				{
					break;
				}
				else
				{
					CPU_num = flag;
				}
			}
		}
		return flag;


	}

void clear_curr_slot()
{
	
}
TimingWheel::TimingWheel()
{
	
	
	for (int i = 0; i <= max_delay; i++)
	{
		slot[i] = new linked_list();
		slot[i]->add_dummy(1);
		slot[i]->add_dummy(2);
		slot[i]->add_dummy(3);
		slot[i]->add_dummy(4);
	}
}
