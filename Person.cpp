#include "Person.h"

Person::Person() {
    id = 0;
    name = "";
    email = "";
    phone = "";
    address = "";
}

Person::Person(int id, const string& name, const string& email, const string& phone, const string& address) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->phone = phone;
    this->address = address;
}

int Person::getId() const { return id; }
string Person::getName() const { return name; }
string Person::getEmail() const { return email; }
string Person::getPhone() const { return phone; }
string Person::getAddress() const { return address; }

void Person::setId(int id) { this->id = id; }
void Person::setName(const string& name) { this->name = name; }
void Person::setEmail(const string& email) { this->email = email; }
void Person::setPhone(const string& phone) { this->phone = phone; }
void Person::setAddress(const string& address) { this->address = address; }

void Person::updateDetails(const string& name, const string& email, const string& phone, const string& address) {
    this->name = name;
    this->email = email;
    this->phone = phone;
    this->address = address;
}

string Person::getDetails() const {
    return "ID: " + to_string(id) + "\nName: " + name +
           "\nEmail: " + email + "\nPhone: " + phone +
           "\nAddress: " + address + "\n";
}
