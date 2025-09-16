#include"Person.h" 
#include"Doctor.h" 
#include <iostream>
#include <string> 
#include<vector> 
#include <iomanip> 
#include <unordered_map>
using namespace std;

class HospitalSystem
{
protected:
	unordered_map<int, Doctor*>doctors;
	//vector<Doctor*> doctors;
public:
	void addTimeSlot(vector<string>t) {};
	void add_doctor() {};
	void delete_doctor(int i) {};
	void update_doctor(int i) {};
	void find_doctor_by_speciality(string s) {}
};