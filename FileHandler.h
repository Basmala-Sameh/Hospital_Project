#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include "LinkedList.h"
#include "Patient.h"
#include "Doctor.h"
#include "Staff.h"
#include "Appointment.h"
using namespace std;

class FileHandler {
    string patientsFile;
    string doctorsFile;
    string staffFile;
    string appointmentsFile;

public:
    FileHandler(const string&, const string&, const string&, const string&);

    void savePatients(const LinkedList<Patient>&);
    void saveDoctors(const LinkedList<Doctor>&);
    void saveStaff(const LinkedList<Staff>&);
    void saveAppointments(const LinkedList<Appointment>&);

    void loadPatients(LinkedList<Patient>&);
    void loadDoctors(LinkedList<Doctor>&);
    void loadStaff(LinkedList<Staff>&);
    void loadAppointments(LinkedList<Appointment>&);

    void exportReport(const string&);
};

#endif
