#include"HospitalSystem.h"
#include"Person.h"
#include"Doctor.h"
#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
using namespace std;

void HospitalSystem::find_doctor_by_speciality(string s)
{
	// get all doctors of same specilization
	vector<Doctor*> filterd;
	for (auto d : doctors)
	{
		if (d->getSpecilization() == s)
		{
			filterd.push_back(d);
		}
	}

	
		if (filterd.empty())
		{
			cout<< "No doctors available for this specialization: "<<endl;
			return;
		}
	
	

	// printing them
	cout << left << setw(15) << "Doctor" << "Available slots" << endl;
	cout << string(40, '-') << "\n";

	for (auto d : filterd)
	{
		cout << left << setw(15) << d->getName();
		vector<string>t = d->get_Time_Slots();

		if (t.empty())
		{
			cout << "No available time slots ";
		}
		else
		{
			for (string& j : t)
			{
				cout << j << "  ";
			}
		}

		cout << endl;
	}
}
