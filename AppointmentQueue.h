#ifndef APPOINTMENTQUEUE_H
#define APPOINTMENTQUEUE_H

#include "Appointment.h"
#include <queue>
using namespace std;

class AppointmentQueue {
    int doctorId;
    queue<Appointment> q;
public:
    AppointmentQueue(int z = 0);
    void addAppointment(const Appointment&);
    bool hasNext() const;
    Appointment processNext();
    size_t getQueueSize() const;
};

#endif
