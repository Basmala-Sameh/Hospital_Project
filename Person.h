#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string email;
    string phone;
    string address;

public:
    Person();
    Person(int, const string&, const string&, const string&, const string&);
    virtual ~Person() {}

    int getId() const;
    string getName() const;
    string getEmail() const;
    string getPhone() const;
    string getAddress() const;

    void setId(int);
    void setName(const string&);
    void setEmail(const string&);
    void setPhone(const string&);
    void setAddress(const string&);

    void updateDetails(const string&, const string&, const string&, const string&);
    virtual string getDetails() const;
};

#endif
