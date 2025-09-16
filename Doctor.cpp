#include "Doctor.h"
#include <sstream>

Doctor::Doctor() : Person(), specialization("") {}

Doctor::Doctor(int id, const string& n, const string& e, const string& p, const string& a, const string& spec)
    : Person(id, n, e, p, a), specialization(spec) {}

string Doctor::getSpecialization() const {
    return specialization;
}

void Doctor::setSpecialization(const string& spec) {
    specialization = spec;
}

void Doctor::addAppointment(int apId) {
    appointmentQueue.push(apId);
}

bool Doctor::processNext(int& out) {
    if (appointmentQueue.empty()) return false;
    out = appointmentQueue.front();
    appointmentQueue.pop();
    return true;
}

int Doctor::getQueueSize() const {
    return (int)appointmentQueue.size();
}

string Doctor::getDetails() const {
    ostringstream oss;
    oss << Person::getDetails()
        << ", Specialization: " << specialization
        << ", Appointments in Queue: " << appointmentQueue.size();
    return oss.str();
}
