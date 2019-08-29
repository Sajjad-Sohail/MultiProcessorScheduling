#include"stdafx.h"

#include<iostream>
#include"TimingWheel.h"
#include"Partition.h"
//#include<fstream>
//#include<string>
//#include<fstream>
//#include <sstream> 
//#include<stdlib.h>
//#include<time.h>
//
//
//
#include"priority_nr.h"
#include"priority_r.h"

#include"fcfs_nr.h"
#include"fcfs_r.h"

#include"sjf_nr.h"
#include"sjf_r.h"

#include"PCBPool.h"

using namespace std;

int main()
{

	TimingWheel tw;

	priority p; sjf s; fcfs f;
	priority_nr pnr; priority_r pr;
	sjf_nr snr; sjf_r sr;
	fcfs_nr fnr; fcfs_r fr;

	PCBPool pcbP;
	string outfilename;
	string inFile;

	cout << "Enter Input file: ";
	cin >> inFile;
	
	cout << "Output File name: ";
	cin >> outfilename;;
	

	pcbP.read_from_file(inFile);

	int pc;
	cout << "Enter probablity for now pcb creation: ";
	cin >> pc;
	tw.PCBpool(pc, pcbP);
	tw.schedule(pc, pcbP, outfilename);
}
