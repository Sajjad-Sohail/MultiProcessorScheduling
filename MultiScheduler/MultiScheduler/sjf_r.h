#pragma once
#include<iostream>
#include<string>
#include "sjf.h"

class sjf_r : public sjf {
private:
	int sleeping_time;
	bool is_starving = false;
public:
	//int getSleepingTime();
	int probablity;
	void setSleep(int s)
	{
		sleeping_time = s;
	}
	int getSleep()const
	{
		return sleeping_time;
	}
};
