#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class Register
{
private:
    int id_student;
    int id_subject;
    int time_now;

public:
    void setIdStudent(int value);
    int getIdStudent();
    void setIdSubject(int value);
    int getIdSubject();
    void activeTime();
    void setTime(int value);
    int getTime();
};

#endif
