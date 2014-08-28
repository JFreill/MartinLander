#include <iostream>
#include <fstream>
#include <istream>
#include <cassert>
#include <ctime>
#include <istream>
#include <conio.h>
using namespace std;

bool checkCrash(double, double);
void printFinalTime(int, int, int);
int getMinute(double);
int getSecond(double);
int getMilliSecond(int, int, double);
Records& displayRecords(Records&);
void addRecord();
double getBurnResrv(double, double);

class Records
{
	int r_size;
	char* r_name;
	char* r_time;
	float r_impact;

public:

	Records(): r_size(0), r_name(0), r_time(0), r_impact(0){};
	Records(char*, char*, float);
	Records(Records&);
	~Records();

	int GetSize(){return r_size;}
	char* GetTime(){return r_time;}
	char* GetName(){return r_name;}
	float GetImpact(){return r_impact;}

	Records& operator=(Records&);
	Records& operator[](int);

	bool operator<(Records&);
	bool operator>(Records&);
	bool operator==(Records&);

	void Report();
};
