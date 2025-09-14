#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    
public:
    Person(int id = 0, string name = "")
        : id(id), name(name) {
    }
    virtual void display() const {
        cout << "ID: " << id << " | Name: " << name;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    

    void setID(const int& i) { id = i; }
    void setName(const string& n) { name = n; }
    

}