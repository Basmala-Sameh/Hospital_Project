#include "FileHandler.h"
#include <fstream>
#include <iostream>
using namespace std;

FileHandler::FileHandler(const string& pf, const string& df, const string& sf, const string& af)
    : patientsFile(pf), doctorsFile(df), staffFile(sf), appointmentsFile(af) {}

void FileHandler::savePatients(const LinkedList<Patient>& list) {
    ofstream out(patientsFile);
    Node<Patient>* cur = list.getHead();
    while (cur) {
        out << cur->data.getId() << ","
            << cur->data.getDetails() << endl;
        cur = cur->next;
    }
}

void FileHandler::saveDoctors(const LinkedList<Doctor>& list) {
    ofstream out(doctorsFile);
    Node<Doctor>* cur = list.getHead();
    while (cur) {
        out << cur->data.getId() << ","
            << cur->data.getDetails() << endl;
        cur = cur->next;
    }
}

void FileHandler::saveStaff(const LinkedList<Staff>& list) {
    ofstream out(staffFile);
    Node<Staff>* cur = list.getHead();
    while (cur) {
        out << cur->data.getId() << ","
            << cur->data.getDetails() << endl;
        cur = cur->next;
    }
}

void FileHandler::saveAppointments(const LinkedList<Appointment>& list) {
    ofstream out(appointmentsFile);
    Node<Appointment>* cur = list.getHead();
    while (cur) {
        out << cur->data.getId() << ","
            << cur->data.toString() << endl;
        cur = cur->next;
    }
}


void FileHandler::loadPatients(LinkedList<Patient>& list) {
    ifstream in(patientsFile);
    if (!in) return;
    
}

void FileHandler::loadDoctors(LinkedList<Doctor>& list) {
    ifstream in(doctorsFile);
    if (!in) return;
}

void FileHandler::loadStaff(LinkedList<Staff>& list) {
    ifstream in(staffFile);
    if (!in) return;
}

void FileHandler::loadAppointments(LinkedList<Appointment>& list) {
    ifstream in(appointmentsFile);
    if (!in) return;
}


void FileHandler::exportReport(const string& filename) {
    ofstream out(filename);
    out << "Hospital Report (patients, doctors, staff, appointments...)\n";
}
