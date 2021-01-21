#include <iostream>
#include <string>

using namespace std;

void in(string value)
{
    // char chuoithu[50];
    // for (int i = 0; i < 50; i++)
    // {
    //     chuoithu[i] = value[i];
    // }
    // cout << chuoithu;
    string chuoithu;
    chuoithu = value;
    cout << chuoithu;
}

int main()
{
    // Ket luan: Khong can ignore
    // char chuoi[50];
    string chuoi;
    cout << "Nhap chuoi: " << endl;
    // cin.ignore();
    // cin.getline(chuoi,50);
    getline(cin, chuoi);
    cout << "";
    cout << chuoi << endl;
    cout << "0000000000" << endl;
    in(chuoi);
}