#include"Person.h" 
#include <iostream> 
#include <string> 
#include<vector> 
using namespace std;
class Doctor :public Person
{
protected:
	string specialization;
	vector<string>timeSlots;

public:
	
	void setSpecilization(string s) { specialization = s; }
	void set_Time_Slots(vector<string>t) { timeSlots = t; }

	string getSpecilization() const { return specialization; }
	vector<string>get_Time_Slots()const { return timeSlots; }

	void addTimeSlot() {};

	Doctor(int i,string n ,int a, string s, vector<string>t) :Person(i,n,a)
	{ 
		specialization = s; 
		timeSlots = t; 
	};
};