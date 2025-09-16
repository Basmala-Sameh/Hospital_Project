#include "HospitalSystem.h"
#include <iostream>
using namespace std;

HospitalSystem::HospitalSystem() {
    fileHandler = new FileHandler("patients.txt", "doctors.txt", "staff.txt", "appointments.txt");
}

HospitalSystem::~HospitalSystem() {
    delete fileHandler;
}


void HospitalSystem::addPatient() {
    int id,medicalHistory; string name, email, phone, address , bloodType ,allergies;
    cout << "Enter Patient ID: "; cin >> id;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Email: "; cin >> email;
    cout << "Enter Phone: "; cin >> phone;
    cout << "Enter Address: "; cin >> address;


    Patient p(id, name, email, phone, address, "", "", "");
    patients.push_back(p);
    opStack.pushOperation("Add Patient: " + name);
}

void HospitalSystem::updatePatient() {
    int id; cout << "Enter Patient ID to update: "; cin >> id;
    Patient* existing = patients.findById(id);
    if (existing) {
        string name, email, phone, address;
        cout << "Enter New Name: "; cin >> name;
        cout << "Enter New Email: "; cin >> email;
        cout << "Enter New Phone: "; cin >> phone;
        cout << "Enter New Address: "; cin >> address;
        existing->updateDetails(name, email, phone, address);
        opStack.pushOperation("Update Patient: " + name);
    } else {
        cout << "Patient not found!\n";
    }
}

void HospitalSystem::deletePatient() {
    int id; cout << "Enter Patient ID to delete: "; cin >> id;
    if (patients.removeById(id)) {
        cout << "Patient deleted.\n";
        opStack.pushOperation("Delete Patient ID: " + to_string(id));
    } else {
        cout << "Patient not found!\n";
    }
}

void HospitalSystem::searchPatient() {
    int id; cout << "Enter Patient ID to search: "; cin >> id;
    Patient* existing = patients.findById(id);
    if (existing) cout << existing->getDetails() << endl;
    else cout << "Patient not found!\n";
}

void HospitalSystem::viewPatients() {
    Node<Patient>* cur = patients.getHead();
    if (!cur) { cout << "No patients found.\n"; return; }
    while (cur) {
        cout << cur->data.getDetails() << endl;
        cur = cur->next;
    }
}


void HospitalSystem::addDoctor() {
    int id; string name, email, phone, address, specialization;
    cout << "Enter Doctor ID: "; cin >> id;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Email: "; cin >> email;
    cout << "Enter Phone: "; cin >> phone;
    cout << "Enter Address: "; cin >> address;
    cout << "Enter Specialization: "; cin >> specialization;

    Doctor d(id, name, email, phone, address, specialization);
    doctors.push_back(d);
    opStack.pushOperation("Add Doctor: " + name);
}

void HospitalSystem::updateDoctor() {
    int id; cout << "Enter Doctor ID to update: "; cin >> id;
    Doctor* existing = doctors.findById(id);
    if (existing) {
        string name, email, phone, address, specialization;
        cout << "Enter New Name: "; cin >> name;
        cout << "Enter New Email: "; cin >> email;
        cout << "Enter New Phone: "; cin >> phone;
        cout << "Enter New Address: "; cin >> address;
        cout << "Enter Specialization: "; cin >> specialization;
        existing->updateDetails(name, email, phone, address);
        existing->setSpecialization(specialization);
        opStack.pushOperation("Update Doctor: " + name);
    } else {
        cout << "Doctor not found!\n";
    }
}

void HospitalSystem::deleteDoctor() {
    int id; cout << "Enter Doctor ID to delete: "; cin >> id;
    if (doctors.removeById(id)) {
        cout << "Doctor deleted.\n";
        opStack.pushOperation("Delete Doctor ID: " + to_string(id));
    } else {
        cout << "Doctor not found!\n";
    }
}

void HospitalSystem::searchDoctor() {
    int id; cout << "Enter Doctor ID to search: "; cin >> id;
    Doctor* existing = doctors.findById(id);
    if (existing) cout << existing->getDetails() << endl;
    else cout << "Doctor not found!\n";
}

void HospitalSystem::viewDoctors() {
    Node<Doctor>* cur = doctors.getHead();
    if (!cur) { cout << "No doctors found.\n"; return; }
    while (cur) {
        cout << cur->data.getDetails() << endl;
        cur = cur->next;
    }
}


void HospitalSystem::addStaff() {
    int id; string name, email, phone, address, role;
    cout << "Enter Staff ID: "; cin >> id;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Email: "; cin >> email;
    cout << "Enter Phone: "; cin >> phone;
    cout << "Enter Address: "; cin >> address;
    cout << "Enter Role: "; cin >> role;

    Staff s(id, name, email, phone, address, role, "", 0.0);
    staff.push_back(s);
    opStack.pushOperation("Add Staff: " + name);
}

void HospitalSystem::updateStaff() {
    int id; cout << "Enter Staff ID to update: "; cin >> id;
    Staff* existing = staff.findById(id);
    if (existing) {
        string name, email, phone, address, role;
        cout << "Enter New Name: "; cin >> name;
        cout << "Enter New Email: "; cin >> email;
        cout << "Enter New Phone: "; cin >> phone;
        cout << "Enter New Address: "; cin >> address;
        cout << "Enter New Role: "; cin >> role;
        existing->updateDetails(name, email, phone, address);
        existing->setRole(role);
        opStack.pushOperation("Update Staff: " + name);
    } else {
        cout << "Staff not found!\n";
    }
}

void HospitalSystem::deleteStaff() {
    int id; cout << "Enter Staff ID to delete: "; cin >> id;
    if (staff.removeById(id)) {
        cout << "Staff deleted.\n";
        opStack.pushOperation("Delete Staff ID: " + to_string(id));
    } else {
        cout << "Staff not found!\n";
    }
}

void HospitalSystem::searchStaff() {
    int id; cout << "Enter Staff ID to search: "; cin >> id;
    Staff* existing = staff.findById(id);
    if (existing) cout << existing->getDetails() << endl;
    else cout << "Staff not found!\n";
}

void HospitalSystem::viewStaff() {
    Node<Staff>* cur = staff.getHead();
    if (!cur) { cout << "No staff found.\n"; return; }
    while (cur) {
        cout << cur->data.getDetails() << endl;
        cur = cur->next;
    }
}


void HospitalSystem::scheduleAppointment() {
    int id, pid; string date;
    cout << "Enter Appointment ID: "; cin >> id;
    cout << "Enter Patient ID: "; cin >> pid;

    cout << "Choose Doctor by:\n";
    cout << "1. Doctor ID\n";
    cout << "2. Doctor Speciality\n";
    int choice; cin >> choice;

    int did = -1;
    if (choice == 1) {
        cout << "Enter Doctor ID: ";
        cin >> did;
    }
    else if (choice == 2) {
    string speciality;
    cout << "Enter Doctor Speciality: ";
    cin >> speciality;

    Doctor* d = findBySpeciality(speciality);
    if (d) did = d->getId();
    else {
        cout << "Doctor with this speciality not found!\n";
        return;
    }
}


    cout << "Enter Date/Time: ";
    cin >> date;

    Appointment a(id, pid, did, date);
    appointments.push_back(a);
    opStack.pushOperation("Schedule Appointment ID: " + to_string(id));
}


void HospitalSystem::cancelAppointment() {
    int id; cout << "Enter Appointment ID to cancel: "; cin >> id;
    if (appointments.removeById(id)) {
        cout << "Appointment cancelled.\n";
        opStack.pushOperation("Cancel Appointment ID: " + to_string(id));
    } else {
        cout << "Appointment not found!\n";
    }
}

void HospitalSystem::viewAppointments() {
    Node<Appointment>* cur = appointments.getHead();
    if (!cur) { cout << "No appointments found.\n"; return; }
    while (cur) {
        cout << cur->data.toString() << endl;
        cur = cur->next;
    }
}


void HospitalSystem::saveData() {
    fileHandler->savePatients(patients);
    fileHandler->saveDoctors(doctors);
    fileHandler->saveStaff(staff);
    fileHandler->saveAppointments(appointments);
    cout << "Data saved successfully.\n";
}

void HospitalSystem::loadData() {
    fileHandler->loadPatients(patients);
    fileHandler->loadDoctors(doctors);
    fileHandler->loadStaff(staff);
    fileHandler->loadAppointments(appointments);
    cout << "Data loaded successfully.\n";
}
Doctor* HospitalSystem::findBySpeciality(const string& speciality) {
    Node<Doctor>* cur = doctors.getHead();
    while (cur) {
        if (cur->data.getSpecialization() == speciality) {
            return &(cur->data);
        }
        cur = cur->next;
    }
    return nullptr;
}

