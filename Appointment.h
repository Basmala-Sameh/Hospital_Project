#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
using namespace std;

class Appointment {
    int appointmentId;
    int patientId;
    int doctorId;
    string dateTime;
    string status;
public:
    Appointment();
    Appointment(int, int, int, const string&, const string& = "scheduled");

    int getId() const { return appointmentId; }   // ✅ ضروري للـ LinkedList
    int getAppointmentId() const;
    int getPatientId() const;
    int getDoctorId() const;
    string getDateTime() const;
    string getStatus() const;

    void cancel();
    void reschedule(const string&);
    string toString() const;
};

#endif
