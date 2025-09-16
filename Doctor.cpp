#include"Person.h" 
#include"Doctor.h" 
#include <iostream> 
#include <string> 
#include<vector> 
using namespace std;

void Doctor::addTimeSlot()
{
	string start, end, slot;
	cout << "Enter the start of the slot : " << endl;
	cin >> start;
	cout << "Enter the end of the slot   : " << endl;
	cin >> end;

	slot = start + " - " + end;
	timeSlots.push_back(slot);
}