#ifndef MAN_H
#define MAN_H

#include <iostream>
#include <fstream>

using namespace std;

struct Time
{
    int day;
    int month;
    int year;
};

class Person
{
private:
    int id;
    Time date;
    // char name[100];
    // char email[50];
    string name;
    string email;

public:
    void setId(int value);
    int getId();
    void readName();
    void setName(string value);
    void coutName();
    string getName();
    void readDate();
    void setDate(Time value);
    Time getDate();
    void readEmail();
    void setEmail(string value);
    void coutEmail();
    string getEmail();
    bool findName(string value);
};

#endif