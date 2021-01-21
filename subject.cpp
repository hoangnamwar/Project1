#include <iostream>
#include "subject.h"

using namespace std;

void Subject::setId(int value)
{
    id = value;
}
int Subject::getId()
{
    return id;
}
void Subject::readName()
{
    cout << "Nhap ten mon hoc: " << endl;
    cin.getline(name, 100);
}
void Subject::coutName()
{
    cout << name;
}
void Subject::setCredit(int value)
{
    credit = value;
}
int Subject::getCredit()
{
    return credit;
}
void Subject::setLesson(int value)
{
    lesson = value;
}
int Subject::getLesson()
{
    return lesson;
}