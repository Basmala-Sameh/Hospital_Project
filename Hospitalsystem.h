#include"Person.h" 
#include"Doctor.h" 
#include <iostream>
#include <string> 
#include<vector> 
#include <iomanip> 
using namespace std;

class HospitalSystem
{
protected:
	vector<Doctor*> doctors;
public:
	void addTimeSlot(vector<string>t) {};
	void add_doctor() {};
	void find_doctor_by_speciality(string s) {}
};