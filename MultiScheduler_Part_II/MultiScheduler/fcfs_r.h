#pragma once
#include<iostream>
#include<string>
#include "fcfs.h"

class fcfs_r : public fcfs {
private:
	int sleeping_time;
	bool is_starving = false;
protected:

public:
	//int getSleepingTime();
	int probablity;

};
