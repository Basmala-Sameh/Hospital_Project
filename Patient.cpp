#include "Patient.h"
#include <sstream>

Patient::Patient() {}

Patient::Patient(int id, const string& n, const string& e, const string& p, const string& a,
                 const string& bt, const string& al, const string& mh)
    : Person(id, n, e, p, a), bloodType(bt), allergies(al), medicalHistory(mh) {}

string Patient::getMedicalRec() const {
    ostringstream oss;
    oss << "Blood Type: " << bloodType
        << ", Allergies: " << allergies
        << ", History: " << medicalHistory;
    return oss.str();
}

void Patient::updateMedRec(const string& bt, const string& al, const string& mh) {
    bloodType = bt;
    allergies = al;
    medicalHistory = mh;
}

string Patient::getDetails() const {
    ostringstream oss;
    oss << Person::getDetails() << ", " << getMedicalRec();
    return oss.str();
}
