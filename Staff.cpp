#include "Staff.h"
#include <sstream>

Staff::Staff() {}

Staff::Staff(int id, const string& n, const string& e, const string& p, const string& a,
             const string& r, const string& sh, double sal)
    : Person(id, n, e, p, a), role(r), shift(sh), salary(sal) {}

void Staff::assignShift(const string& sh) {
    shift = sh;
}

void Staff::setRole(const string& r) { 
    role = r;
}

string Staff::getRole() const {       
    return role;
}

string Staff::getDetails() const {
    ostringstream oss;
    oss << Person::getDetails()
        << ", Role: " << role
        << ", Shift: " << shift
        << ", Salary: " << salary;
    return oss.str();
}
