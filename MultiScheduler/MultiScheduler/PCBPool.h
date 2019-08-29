#pragma once
#include"stdafx.h"

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;
class PCBPool {
public:
	int r_sl_min;
	int r_sl_max;

	int st_min;
	int st_max;

	int pr_prob;
	int pr_nr_prob;
	int pr_r_prob;
	int pr_b_max;
	int pr_b_min;
	int pr_ex_min;
	int pr_ex_max;

	int sjf_prob;
	int sjf_nr_prob;
	int sjf_r_prob;
	int sjf_b_max;
	int sjf_b_min;
	int sjf_ex_min;
	int sjf_ex_max;

	int fcfs_prob;
	int fcfs_nr_prob;
	int fcfs_r_prob;
	int fcfs_b_max;
	int fcfs_b_min;
	int fcfs_ex_min;
	int fcfs_ex_max;

	void read_from_file(string filename)
	{
		
		ifstream input(filename.c_str());
		std::string line;

		int pcb_type, i = 0;
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
			else if (i == 1)
			{
				iss >> recursive_sleep_range >> vol1 >> vol2;
				r_sl_min = vol1;
				r_sl_max = vol2;
			}
			else if (i == 2)
			{
				iss >> starvation_threshold_range >> vol1 >> vol2;
				st_min = vol1;
				st_max = vol2;
			}
			else
			{
				iss >> type >> probablity_pcb >> recursive >> probablity_recursive >> non_recursive >> probablity_non_recursive >> burst_range >> vol1 >> vol2;
				if (type == "Pr")
				{
					pr_prob = probablity_pcb;
					pr_nr_prob = probablity_non_recursive;
					pr_r_prob = probablity_recursive;
					pr_b_max = vol2;
					pr_b_min = vol1;
					pr_ex_min = previous + 1;
					pr_ex_max = previous + probablity_pcb;
					previous = pr_ex_max;
				}
				else if (type == "SJF")
				{
					sjf_prob = probablity_pcb;
					sjf_nr_prob = probablity_non_recursive;
					sjf_r_prob = probablity_recursive;
					sjf_b_max = vol2;
					sjf_b_min = vol1;
					sjf_ex_min = previous + 1;
					sjf_ex_max = previous + probablity_pcb;
					previous = sjf_ex_max;
				}
				else if (type == "FCFS")
				{
					fcfs_prob = probablity_pcb;
					fcfs_nr_prob = probablity_non_recursive;
					fcfs_r_prob = probablity_recursive;
					fcfs_b_max = vol2;
					fcfs_b_min = vol1;
					fcfs_ex_min = previous + 1;
					fcfs_ex_max = previous + probablity_pcb;
					previous = fcfs_ex_max;
				}
			}
			i++;
		}
	}
};