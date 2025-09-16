#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

class Staff : public Person {
    string role;    
    string shift;
    double salary;

public:
    Staff();
    Staff(int, const string&, const string&, const string&, const string&,
          const string&, const string&, double);

    void assignShift(const string&);
    void setRole(const string&);
    string getRole() const;        

    string getDetails() const override;
};

#endif
