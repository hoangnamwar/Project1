#include <iostream>
#include <string>
#include "student.h"

using namespace std;

void Student::setId(int value)
{
    id = value;
}
int Student::getId()
{
    return id;
}
void Student::setRba(float value)
{
    rba = value;
}
float Student::getRba()
{
    return rba;
}
// void Student::readMajor()
// {
//     cout << "Nhap chuyen nganh: " << endl;
//     cin.ignore();
//     cin.getline(major, 100);
// }
// void Student::setMajor(string value)
// {
//     for (int i = 0; i < 50; i++)
//     {
//         major[i] = value[i];
//     }
// }
void Student::readMajor()
{
    cout << "Nhap chuyen nganh: " << endl;
    cin.ignore();
    getline(cin, major);
}
void Student::setMajor(string value)
{
    major = value;
}
string Student::getMajor()
{
    return major;
}
void Student::coutMajor()
{
    cout << major;
}
