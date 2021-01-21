#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <fstream>

using namespace std;

class Subject
{
private:
    int id;
    char name[50];
    // string name;
    int credit;
    int lesson;

public:
    void setId(int value);
    int getId();
    void readName();
    void coutName();
    void setCredit(int value);
    int getCredit();
    void setLesson(int value);
    int getLesson();
};

#endif