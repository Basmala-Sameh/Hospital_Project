#include "Appointment.h"
#include <sstream>

Appointment::Appointment() : appointmentId(0), patientId(0), doctorId(0), dateTime(""), status("scheduled") {}

Appointment::Appointment(int x, int y, int z, const string& dt, const string& status_)
    : appointmentId(x), patientId(y), doctorId(z), dateTime(dt), status(status_) {}

int Appointment::getAppointmentId() const { return appointmentId; }
int Appointment::getPatientId() const { return patientId; }
int Appointment::getDoctorId() const { return doctorId; }
string Appointment::getDateTime() const { return dateTime; }
string Appointment::getStatus() const { return status; }

void Appointment::cancel() { status = "cancelled"; }

void Appointment::reschedule(const string& newDateTime) {
    dateTime = newDateTime;
    status = "rescheduled";
}

string Appointment::toString() const {
    ostringstream oss;
    oss << "AppointmentID: " << appointmentId
        << ", PatientID: " << patientId
        << ", DoctorID: " << doctorId
        << ", DateTime: " << dateTime
        << ", Status: " << status;
    return oss.str();
}
