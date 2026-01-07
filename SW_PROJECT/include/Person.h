#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string phone;

public:
    Person(string name, string phone);
    virtual void displayInfo() = 0;   // Pure virtual function
    virtual ~Person() {}              // Virtual destructor
};


#endif // PERSON_H
