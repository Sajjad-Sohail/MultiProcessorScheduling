#include"stdafx.h"

#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
#include <sstream> 
#include<stdlib.h>
#include<time.h>

#include"priority_nr.h"
#include"priority_r.h"

#include"fcfs_nr.h"
#include"fcfs_r.h"

#include"sjf_nr.h"
#include"sjf_r.h"

using namespace std;

int main()
{
	priority p; sjf s; fcfs f;
	priority_nr pnr; priority_r pr;
	sjf_nr snr; sjf_r sr;
	fcfs_nr fnr; fcfs_r fr;


	string inFile = "input.txt";
	ifstream input(inFile.c_str());
	std::string line;

	int pcb_type, i=0;
	string recursive_sleep_range, starvation_threshold_range; int vol1, vol2;
	string type, recursive, non_recursive, burst_range; int probablity_pcb, probablity_recursive, probablity_non_recursive;
	int previous = 0;

	while (getline(input, line))
	{
		std::istringstream iss(line);
		if (i == 0)
		{
			iss >> pcb_type;
		}
		else if(i == 1)
		{
			iss >> recursive_sleep_range >> vol1 >> vol2;
		}
		else if(i == 2)
		{
			iss >> starvation_threshold_range >> vol1 >> vol2;
		}
		else 
		{
			iss >> type >> probablity_pcb >> recursive >> probablity_recursive >> non_recursive >> probablity_non_recursive >> burst_range >> vol1 >> vol2;
			if (type == "Pr")
			{
				pnr.pprobablity = probablity_pcb;
				pnr.probablity = probablity_non_recursive;
				pr.probablity = probablity_recursive;
				pnr.b_max = vol2;
				pnr.b_min = vol1;
				pnr.existance_min = previous + 1;
				pnr.existance_max = previous + probablity_pcb;
				previous = pnr.existance_max;
			}
			else if(type == "SJF")
			{
				snr.sprobablity = probablity_pcb;
				snr.probablity = probablity_non_recursive;
				sr.probablity = probablity_recursive;
				snr.b_max = vol2;
				snr.b_min = vol1;
				snr.existance_min = previous + 1;
				snr.existance_max = previous + probablity_pcb;
				previous = snr.existance_max;

			}
			else if(type == "FCFS")
			{
				fnr.fprobablity = probablity_pcb;
				fnr.probablity = probablity_non_recursive;
				fr.probablity = probablity_recursive;
				fnr.b_max = vol2;
				fnr.b_min = vol1;
				fnr.existance_min = previous + 1;
				fnr.existance_max = previous + probablity_pcb;
				previous = fnr.existance_max;

			}
		}
		i++;
	}
	i = 0;
	int pc;
	cout << "Enter probablity for now pcb creation: ";
	cin >> pc;
	srand(time(NULL));

	do {
		cout << "\nClock at: " << i;

		int R = rand() % 100 + 1;
		//cout << "\n"<<R;
		if (R <= pc)
		{
			if (R >= pnr.existance_min && R <= pnr.existance_max)
			{
				R = rand() % 100 + 1;
				//R = 59;
				if (R <= pr.probablity)
				{
					R = rand() % (pnr.b_max - pnr.b_min + 1) + pnr.b_min;
					cout << "\n\tPriority recursive Burst Time: " << R;
					int pid_new = p.priority_q.back().getPid();
					p.priority_q.insert(p.priority_q.end(), priority(pid_new + 1, R));

				}
				else
				{
					R = rand() % (pnr.b_max - pnr.b_min + 1) + pnr.b_min;
					cout << "\n\tPriority non - recursive Burst Time: " << R;
					int pid_new = p.priority_q.back().getPid();
					p.priority_q.insert(p.priority_q.end(), priority(pid_new + 1, R));
				}
			}
			else if (R >= snr.existance_min && R <= snr.existance_max)
			{
				R = rand() % 100 + 1;
				if (R <= snr.probablity)
				{
					R = rand() % (snr.b_max - snr.b_min + 1) + snr.b_min;
					cout << "\n\tSJF recursive Burst Time: " << R;
					int pid_new = s.sjf_q.back().getPid();
					s.sjf_q.insert(s.sjf_q.end(), sjf(pid_new + 1, R));
				}
				else
				{
					R = rand() % (snr.b_max - snr.b_min + 1) + snr.b_min;
					cout << "\n\tSJF non - recursive Burst Time: " << R;
					int pid_new = s.sjf_q.back().getPid();
					s.sjf_q.insert(s.sjf_q.end(), sjf(pid_new + 1, R));
				}
			}
			else if(R >= fnr.existance_min && R <= fnr.existance_max)
			{
				R = rand() % 100 + 1;
				if (R <= fnr.probablity)
				{
					R = rand() % (fnr.b_max - fnr.b_min + 1) + fnr.b_min;
					cout << "\n\tFCFS recursive Burst Time: " << R;
					int pid_new = f.fcfs_q.back().getPid();
					f.fcfs_q.insert(f.fcfs_q.end(), fcfs(pid_new + 1, R));
				}
				else
				{
					R = rand() % (fnr.b_max - fnr.b_min + 1) + pnr.b_min;
					cout << "\n\tFCFS non - recursive Burst Time: " << R;
					int pid_new = f.fcfs_q.back().getPid();
					f.fcfs_q.insert(f.fcfs_q.end(), fcfs(pid_new + 1, R));
				}
			}
		}
		else
		{
			cout << "\n\t No PCB created";
		}
		i++;
		
		if (i == 10)
		{
			break;
		}
	} while (true);
}