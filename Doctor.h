#include"Person.h"
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Doctor:public Person
{
public:
	
	string specialization;
	vector<string>timeSlots;

	Doctor(string n, int i, string s, vector<string>t) :Person(n, i)
	{
		specialization = s;
		timeSlots = t;
	};

	void setSpecilization(string s) { specialization = s; }
	void set_Time_Slots(vector<string>t) { timeSlots = t; }

	string getSpecilization() const{ return specialization; }
	vector<string>get_Time_Slots()const { return timeSlots; }
};