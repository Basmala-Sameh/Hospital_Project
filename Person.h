#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
public:
    Person(int id = 0, string name = "", int age = 0)
        : id(id), name(name), age(age) {
    }
    virtual void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Age: " << age;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }

    void setID(const int& i) { id = i; }
    void setName(const string& n) { name = n; }
    void setAge(int a) { age = a; }

}