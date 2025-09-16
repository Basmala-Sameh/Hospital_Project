#include "AppointmentQueue.h"

AppointmentQueue::AppointmentQueue(int z) : doctorId(z) {}

void AppointmentQueue::addAppointment(const Appointment& a) { q.push(a); }

bool AppointmentQueue::hasNext() const { return !q.empty(); }

Appointment AppointmentQueue::processNext() {
    if (q.empty()) return Appointment();
    Appointment a = q.front();
    q.pop();
    return a;
}

size_t AppointmentQueue::getQueueSize() const { return q.size(); }
