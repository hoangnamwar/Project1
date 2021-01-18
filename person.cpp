#include <iostream>
#include "person.h"

using namespace std;

void Person::setId(int value)
{
    id = value;
}
int Person::getId()
{
    return id;
}
void Person::readName()
{
    cout << "Nhap ten nguoi " << id << ": " << endl;
    cin.ignore();
    cin.getline(name, 100);
}
void Person::setName(string value)
{
    for (int i = 0; i < 100; i++)
    {
        name[i] = value[i];
    }
}
void Person::coutName()
{
    cout << name;
}
string Person::getName()
{
    return name;
}
void Person::readDate()
{
    int day, month, year;
    bool check = false;
    int count = 0;
    do
    {
        count++;
        if (count > 1)
            cout << "Nhập lại ngày tháng năm (vd: 1 1 2001): " << endl;
        else
            cout << "Nhập lại ngày tháng năm (vd: 1 1 2001): " << endl;
        cin >> day >> month >> year;
        if ((year > 2020) || (year < 1900))
        {
            cout << "Ngày tháng năm không hợp lệ." << endl;
        }
        else
        {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:

                if (day > 0 && day <= 31)
                {
                    check = true;
                    break;
                }
                else
                {
                    cout << "Ngày tháng năm không hợp lệ." << endl;
                    break;
                }

            case 4:
            case 6:
            case 9:
            case 11:

                if (day <= 30 && day > 0)
                {
                    check = true;
                    break;
                }
                else
                {
                    cout << "Ngày tháng năm không hợp lệ." << endl;
                    break;
                }

            case 2:

                if (day <= 28 && day > 0)
                {
                    check = true;
                    break;
                }
                else
                {
                    cout << "Ngày tháng năm không hợp lệ." << endl;
                    break;
                }

            default:
                cout << "Ngày tháng năm không hợp lệ." << endl;
                break;
            }
        }
    } while (check == false);

    if (check == true)
    {
        date.day = day;
        date.month = month;
        date.year = year;
    }
}
Time Person::getDate()
{
    return date;
}
void Person::setDate(Time value)
{
    date = value;
}
void Person::readEmail()
{
    cout << "Nhap email: " << endl;
    cin.ignore();
    cin.getline(email, 50);
}
void Person::setEmail(string value)
{
    for (int i = 0; i < 100; i++)
    {
        email[i] = value[i];
    }
}
string Person::getEmail()
{
    return email;
}
void Person::coutEmail()
{
    cout << "Nhap email nguoi " << id << ": " << endl;
    cin.ignore();
    cin.getline(email, 100);
}
bool Person::findName(string value)
{
    int n = 0;
    int m = 0;
    bool check = false;
    int leng = value.length();

    while (name[n] != '\0')
    {

        if (name[n] == value[m])
        {
            while (name[n] == value[m] && name[n] != '\0')
            {
                n++;
                m++;
            }
            if (m == leng && (name[n] == ' ' || name[n] == '\0'))
            {
                check = true;
            }
        }
        else
        {
            while (name[n] != ' ')
            {
                n++;
                if (name[n] == '\0')
                    break;
            }
        }
        n++;
        m = 0;
    }
    return check;
}
