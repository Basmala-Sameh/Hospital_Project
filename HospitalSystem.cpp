#include"HospitalSystem.h"
#include"Person.h"
#include"Doctor.h"
#include <iostream>
#include <string>
#include<vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

void HospitalSystem::addTimeSlot(vector<string>&t)
{
	string start, end, slot;
	cout << "Enter the start of the slot : " << endl;
	cin >> start;
	cout << "Enter the end of the slot   : " << endl;
	cin >> end;

	slot = start + " - " + end;
	t.push_back(slot);
}

void HospitalSystem::add_doctor()
{
	string n, s;
	int i ,a,slots;
	vector<string>t;

	cout << "Enter doctor name : " << endl;
	cin >> n;
	cout << "Enter doctor ID : " << endl;
	cin >> i;
	cout << "Enter doctor Specilization : " << endl;
	cin >> s;
	cout << "Enter doctor Age : " << endl;
	cin >> a;
	cout << "How many time slots doctor have? " << endl;
	cin >> slots;

	for (int j = 0; j < slots; ji++)
	{
		cout << "The " << j + 1 << "slot : " << endl;
		addTimeSlot(t);
	}

	Doctor* d=new Doctor(i, n, a, s, t);
	doctors[i] = d;

}

void HospitalSystem::delete_doctor(int i)
{
	if (doctors.empty())
	{
		cout << "No doctors available to delete " <<endl;
		return;
	}

	if (doctors.count(i))
	{
		delete doctors[i]; // from memory
		doctors.erase(i);
		cout << "Doctor deleted succssefully " << endl;
	}

	

}

void HospitalSystem::update_doctor(int i)
{
	if (doctors.empty())
	{
		cout << "No doctors available to delete " << endl;
		return;
	}
	if (doctors.count(i))
	{
		cout << "Which field you want to update? " << endl
			<< "1.Name " << endl
			<< "2.ID " << endl
			<< "3.Specilization " << endl
			<< "4.Age " << endl;
		int option; cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "Enter the updated name : " << endl;
			string n; cin >> n;
			doctors[i]->setName(n);
			break;
		}
			
		case 2:
		{
			cout << "Enter the new ID: ";
			int newId;
			cin >> newId;

			// move the Doctor to the new key
			doctors[newId] = doctors[i];
			doctors.erase(i);
			cout << "ID updated successfully!"<<endl;
			break;
		}
			
		case 3:
		{
			cout << "Enter the updated specialization: ";
			string s;
			cin >> s;
			doctors[i]->setSpecilization(s);
			break;
		}
			
		case 4:
		{
			cout << "Enter the updated age: ";
			int a;
			cin >> a;
			doctors[i]->setAge(a);
			break;
		}
		default:
			cout << "Invalid option!\n";
			break;
			
		}

	}
	else
	{
		cout << "Doctor not found!" << endl;
	}

}

void HospitalSystem::find_doctor_by_speciality(string s)
{
	// get all doctors of same specilization
	vector<Doctor*> filterd;
	for (auto d : doctors)
	{
		if (d.second->getSpecilization() == s)
		{
			filterd.push_back(d.second);
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

