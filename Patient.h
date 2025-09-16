#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {
    string bloodType;
    string allergies;
    string medicalHistory;

public:
    Patient();
    Patient(int, const string&, const string&, const string&, const string&,
            const string&, const string&, const string&);

    string getMedicalRec() const;
    void updateMedRec(const string&, const string&, const string&);
    string getDetails() const override;
};

#endif
