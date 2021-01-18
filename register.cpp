#include <iostream>
#include "register.h"
#include <ctime>

using namespace std;

void Register::setIdStudent(int value)
{
    id_student = value;
}
int Register::getIdStudent()
{
    return id_student;
}
void Register::setIdSubject(int value)
{
    id_subject = value;
}
int Register::getIdSubject()
{
    return id_subject;
}
void Register::activeTime()
{
    time_t now = time(0);
    time_now = now;
}
void Register::setTime(int value)
{
    time_now = value;
}
int Register::getTime()
{
    return time_now;
}
