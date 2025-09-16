#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include "Patient.h"
#include "Doctor.h"
#include "Staff.h"
#include "Appointment.h"
#include "LinkedList.h"
#include "FileHandler.h"
#include "OperationStack.h"


class HospitalSystem
{
    LinkedList<Patient> patients;
    LinkedList<Doctor> doctors;
    LinkedList<Staff> staff;
    LinkedList<Appointment> appointments;
    FileHandler *fileHandler;
    OperationStack opStack;

public:
    HospitalSystem();
    ~HospitalSystem();

    void addPatient();
    void updatePatient();
    void deletePatient();
    void searchPatient();
    void viewPatients();

    void addDoctor();
    void updateDoctor();
    void deleteDoctor();
    void searchDoctor();
    void viewDoctors();

    void addStaff();
    void updateStaff();
    void deleteStaff();
    void searchStaff();
    void viewStaff();

    void scheduleAppointment();
    void cancelAppointment();
    void viewAppointments();

    void saveData();
    void loadData();
};

#endif
