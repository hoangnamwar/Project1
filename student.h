#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "person.h"
using namespace std;

class Student : public Person
{
private:
    int id;
    float rba;
    // char major[50];
    string major;

public:
    void setId(int value);
    int getId();
    void setRba(float value);
    float getRba();
    void readMajor();
    void setMajor(string value);
    string getMajor();
    void coutMajor();
};

#endif
