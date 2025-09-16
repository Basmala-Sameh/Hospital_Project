#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include <queue>
using namespace std;

class Doctor : public Person {
    string specialization;
    queue<int> appointmentQueue;

public:
    Doctor();
    Doctor(int, const string&, const string&, const string&, const string&, const string&);

    string getSpecialization() const;
    void setSpecialization(const string&);   

    void addAppointment(int);
    bool processNext(int&);
    int getQueueSize() const;
    string getDetails() const override;
};

#endif
