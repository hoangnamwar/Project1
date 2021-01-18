#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "person.h"
#include "student.h"
#include "subject.h"
#include "register.h"

#define FILE_STUDENT "student.dat"
#define FILE_PERSON "person.dat"
#define FILE_SUBJECT "subject.dat"
#define FILE_REGISTER "register.dat"

using namespace std;

// Hàm hoán đổi 2 bảng Register
void swapRegister(int first, int second)
{
    int id_student_package;
}

int main()
{
    // _setmode(_fileno(stdout), _O_U16TEXT);
    char *a = setlocale(LC_ALL, "vietnamese");

    Student Stu[100];
    Person Per[100];
    Subject Sub[10];
    Register Reg[100];

    fstream file;

    int number_student = 0;
    int number_subject = 0;
    int number_register = 0;

    //------------------DOC FILE----------------------------

    {
        //*******************  STUDENT  *******************
        file.open(FILE_STUDENT, ios::in | ios::binary);
        file.read((char *)&number_student, sizeof(number_student));
        for (int i = 0; i < number_student; i++)
        {
            file.read((char *)&Stu[i], sizeof(Stu));
        }
        file.close();
        //*******************  PERSON  *******************
        file.open(FILE_PERSON, ios::out | ios::binary);
        file.read((char *)&number_student, sizeof(number_student));
        for (int i = 0; i < number_student; i++)
        {
            file.read((char *)&Per[i], sizeof(Per));
        }
        file.close();
        //*******************  SUBJECT  *******************
        file.open(FILE_SUBJECT, ios::out | ios::binary);
        file.read((char *)&number_subject, sizeof(number_subject));
        for (int i = 0; i < number_subject; i++)
        {
            file.read((char *)&Sub[i], sizeof(Sub));
        }
        file.close();
        //*******************  REGISTER  *******************
        file.open(FILE_REGISTER, ios::out | ios::binary);
        file.read((char *)&number_register, sizeof(number_register));
        for (int i = 0; i < number_register; i++)
        {
            file.read((char *)&Reg[i], sizeof(Reg));
        }
        file.close();
    }
    //------------------END DOC FILE------------------------

    {
        system("cls");
        //------------------CHUC NANG CHINH---------------------
        cout << "\t\t\t\t\tPhan mem quan ly sinh vien\n";
        cout << "\t\t\t\t\t\tHoang Nam\n\n";
        cout << "---------------------------------------------------\n";

        wcout << L"1. Nhập thêm mới sinh viên." << endl;
        cout << "2. Sửa thông tin sinh viên (theo mã)." << endl;
        cout << "3. Xóa sinh viên." << endl;
        cout << "4. Tìm sinh viên theo tên gần đúng." << endl;
        cout << "5. Thêm mới môn học." << endl;
        cout << "6. Đăng ký môn học." << endl;
        cout << "7. Hiển thị danh sách sinh viên." << endl;
        cout << "8. Hiển thị danh sách môn học." << endl;
        cout << "9. Hiển thị bản đăng ký." << endl;
        cout << "10. Sắp xếp  bản đăng ký." << endl;
        cout << "0. Thoát khỏi hệ thống." << endl;

        cout << "---------------------------------------------------\n";

        int chuc_nang = 0;
        do
        {
            cout << "\tMoi chon chuc nang: ";
            cin >> chuc_nang;
            switch (chuc_nang)
            {
            case 1:
            {
                // 1.Nhap them mot sinh vien

                int package;
                cout << "Nhập số chứng minh/Căn cước/Hộ chiếu: " << endl;
                cin >> package;
                Per[number_student].setId(package);
                Per[number_student].readName();
                Per[number_student].readDate();
                Per[number_student].readEmail();

                cout << "Nhập mã sinh viên: " << endl;
                cin >> package;
                Stu[number_student].setId(package);
                cout << "Nhap điểm trung bình: " << endl;
                cin >> package;
                Stu[number_student].setRba(package);
                Stu[number_student].readMajor();
                number_student++;
                break;
            };
            case 2:
            {
                // 2. Sửa thông tin sinh viên (theo mã).

                int package;

                bool check = false;
                int first = 0;
                int position;
                do
                {
                    first++;
                    if (first > 1)
                        cout << "Nhập lại mã sinh viên cần sửa: ";
                    else
                        cout << "Nhập mã sinh viên cần sửa: ";
                    cin >> package;
                    for (int i = 0; i < number_student; i++)
                    {
                        if (Stu[i].getId() == package)
                        {
                            check = true;
                            position = i;
                        }
                    }
                } while (check == false);
                cout << "Sửa thông tin sinh viên: " << endl;
                int chuc_nang_sua;
                check = false;
                first = 0;
                cout << "1. Sửa mã sv." << endl;
                cout << "2. Sửa tên." << endl;
                cout << "3. Sửa ngày tháng năm sinh." << endl;
                cout << "4. Sửa email." << endl;
                cout << "5. Sửa số chứng minh/Căn cước/Hộ chiếu." << endl;
                cout << "6. Sửa điểm trung bình." << endl;
                cout << "7. Sửa chuyên ngành." << endl;
                do
                {
                    first++;
                    if (first > 1)
                        cout << "Mời nhập lại: " << endl;
                    cin >> chuc_nang_sua;
                    if ((chuc_nang_sua < 7) && (chuc_nang_sua > 1))
                        check = true;
                } while (check == false);
                package;
                switch (chuc_nang_sua)
                {
                case 1:
                {
                    cout << "Nhập lại mã sinh viên: " << endl;
                    cin >> package;
                    Stu[position].setId(package);
                    break;
                }
                case 2:
                {
                    cout << "Nhập lại tên sinh viên: " << endl;
                    Per[position].readName();
                    break;
                }
                case 3:
                {
                    cout << "Nhập lại ngày tháng năm sinh: " << endl;
                    Per[position].readDate();
                    break;
                }
                case 4:
                {
                    cout << "Nhập lại email: " << endl;
                    Per[position].readEmail();
                    break;
                }
                case 5:
                {
                    cout << "Nhập lại số chứng minh/Căn cước/Hộ chiếu: " << endl;
                    cin >> package;
                    Per[position].setId(package);
                    break;
                }
                case 6:
                {
                    cout << "Nhập lại điểm trung bình: " << endl;
                    cin >> package;
                    Stu[position].setRba(package);
                    break;
                }
                default:
                {
                    cout << "7Nhập lại chuyên ngành." << endl;
                    Stu[position].readMajor();
                    break;
                }
                }
                break;
            };
            case 3:
            {
                //3. Xóa sinh viên
                int package;

                bool check = false;
                int first = 0;
                int position;
                do
                {
                    first++;
                    if (first > 1)
                        cout << "Nhập lại mã sinh viên cần xóa: ";
                    else
                        cout << "Nhập mã sinh viên cần xóa: ";
                    cin >> package;
                    for (int i = 0; i < number_student; i++)
                    {
                        if (Stu[i].getId() == package)
                        {
                            check = true;
                            position = i;
                        }
                    }
                } while (check == false);
                // Thay sinh viên cần xóa bằng sinh viên cuối
                {
                    Stu[position].setId(Stu[number_student - 1].getId());
                    Stu[position].setRba(Stu[number_student - 1].getRba());
                    Per[position].setId(Per[number_student - 1].getId());
                    Per[position].setDate(Per[number_student - 1].getDate());
                    Per[position].setName(Per[number_student - 1].getName());
                    Per[position].setEmail(Per[number_student - 1].getEmail());
                    Stu[position].setMajor(Stu[number_student - 1].getMajor());
                    number_student--;
                }
            };
            case 4:
            {
                //4. Tìm sinh viên theo tên gần đúng.

                char find[100];
                cout << "Nhập tên cần tìm : " << endl;
                cin.getline(find, 100);
                for (int i = 0; i < number_student; i++)
                {
                    if (Per[i].findName(find) == true)
                    {
                        cout << "-------------------------------";
                        cout << "Họ tên: ";
                        Per[i].coutName();
                        cout << endl;
                        cout << "Mã sinh viên: "
                             << Stu[i].getId() << endl;
                        cout << "-------------------------------";
                    }
                }
            };
            case 5:
            {
                //5. Thêm mới môn học.

                int package;
                cout << "Nhập id môn học: " << endl;
                cin >> package;
                Sub[number_subject].setId(package);
                Sub[number_subject].readName();
                cout << "Nhập hệ số tín chỉ: " << endl;
                cin >> package;
                Sub[number_subject].setCredit(package);
                cout << "Nhập số tiết học của môn: " << endl;
                Sub[number_subject].setLesson(package);
                number_subject++;
                break;
            };
            case 6:
            {
                //6. Đăng ký môn học.

                int package;
                cout << "Đăng ký môn học: " << endl;
                cout << "Nhập mã sinh viên đăng ký: " << endl;
                cin >> package;
                Reg[number_register].setIdStudent(package);
                cout << "Nhập mã môn đăng ký: " << endl;
                cin >> package;
                Reg[number_register].setIdSubject(package);
                Reg[number_register].activeTime();
                number_register++;
                break;
            };
            case 7:
            {
                //7. Hiển thị danh sách sinh viên.

                cout << "*********************************" << endl;
                cout << "Danh sách sinh viên: " << endl
                     << endl;
                for (int i = 0; i < number_student; i++)
                {
                    cout << "Sinh viên " << Stu[i].getId() << ": " << endl;
                    cout << "Họ tên: ";
                    Per[i].readName();
                    cout << endl;
                    cout << "Ngày sinh: " << Per[i].getDate().day << "/"
                         << Per[i].getDate().month << "/"
                         << Per[i].getDate().year << endl;
                    cout << "Điểm trung bình: " << Stu[i].getRba() << endl;
                    cout << "Chuyên ngành: ";
                    Stu[i].coutMajor();
                    cout << endl;
                    Per[i].coutEmail();
                    cout << endl;
                    cout << "Số chứng minh/Căn cước/Hộ chiếu: ";
                    cout << Per[i].getId() << endl;
                    cout << "--------------------------" << endl
                         << endl;
                }
                break;
            };
            case 8:
            {
                // 8. Hiển thị danh sách môn học.

                cout << "*********************************" << endl;
                cout << "Danh sách môn học: " << endl
                     << endl;
                for (int i = 0; i < number_subject; i++)
                {
                    cout << "Mã môn học: " << Sub[i].getId() << endl;
                    cout << "Tên lớp: ";
                    Sub[i].coutName();
                    cout << endl;
                    cout << "Hệ số tín chỉ: " << Sub[i].getCredit() << endl;
                    cout << "Số tiết: " << Sub[i].getLesson() << endl;
                    cout << "--------------------------" << endl
                         << endl;
                };
                break;
            }
            case 9:
            {
                // 9. Hiển thị bản đăng ký.

                cout << "*********************************" << endl;
                cout << "Danh sách bản đăng ký: " << endl
                     << endl;
                for (int i = 0; i < number_subject; i++)
                {
                    cout << "Mã sinh viên: " << Reg[i].getIdStudent() << endl;
                    cout << "Mã lớp: " << Reg[i].getIdSubject() << endl;
                    cout << "--------------------------" << endl
                         << endl;
                };
                break;
            };
            case 10:
            {
                // 10. Sắp xếp bản đăng ký.

                int package = 0;
                cout << "Sắp xếp bảng đăng ký theo thời gian: " << endl;
                cout << "1. Cũ -> mới" << endl;
                cout << "2. Mới -> cũ" << endl;
                int first = 0;
                bool check = false;
                do
                {
                    first++;
                    if (first > 1)
                        cout << "Nhập lại: " << endl;
                    cin >> package;
                    if ((package == 1) || (package == 2))
                        check = true;
                } while (check == false);

                if (package == 1) // Cũ -> mới (xếp theo chiều tăng dần)
                {
                    int max;
                    int package_id_student;
                    int package_id_subject;
                    for (int i = 0; i < number_register; i++)
                    {
                        for (int j = i + 1; j < number_register; j++)
                        {
                            if (Reg[i].getTime() > Reg[j].getTime())
                            {
                                // max = Reg[i]
                                max = Reg[i].getTime();
                                package_id_student = Reg[i].getIdStudent();
                                package_id_subject = Reg[i].getIdSubject();
                                //Reg[i] = Reg[j]
                                Reg[i].setIdStudent(Reg[j].getIdStudent());
                                Reg[i].setIdSubject(Reg[j].getIdSubject());
                                Reg[i].setTime(Reg[j].getTime());
                                //Reg[j] = max;
                                Reg[j].setIdStudent(package_id_student);
                                Reg[j].setIdSubject(package_id_subject);
                                Reg[j].setTime(max);
                            }
                        }
                    }
                }
                else // Mới -> cũ (xếp theo chiều giảm dần)
                {
                    int max;
                    int package_id_student;
                    int package_id_subject;
                    for (int i = 0; i < number_register; i++)
                    {
                        for (int j = i + 1; j < number_register; j++)
                        {
                            if (Reg[i].getTime() < Reg[j].getTime())
                            {
                                // max = Reg[i]
                                max = Reg[i].getTime();
                                package_id_student = Reg[i].getIdStudent();
                                package_id_subject = Reg[i].getIdSubject();
                                //Reg[i] = Reg[j]
                                Reg[i].setIdStudent(Reg[j].getIdStudent());
                                Reg[i].setIdSubject(Reg[j].getIdSubject());
                                Reg[i].setTime(Reg[j].getTime());
                                //Reg[j] = max;
                                Reg[j].setIdStudent(package_id_student);
                                Reg[j].setIdSubject(package_id_subject);
                                Reg[j].setTime(max);
                            }
                        }
                    }
                }
                cout << "Sắp xếp hoàn thành! " << endl;
                break;
            };
            case 0:
            {
                // 0. Thoát khỏi hệ thống.
                //------------------LUU FILE----------------------------

                //*******************  STUDENT  *******************
                file.open(FILE_STUDENT, ios::out | ios::binary);
                file.write((char *)&number_student, sizeof(number_student));
                for (int i = 0; i < number_student; i++)
                {
                    file.write((char *)&Stu[i], sizeof(Stu));
                }
                file.close();
                //*******************  PERSON  *******************
                file.open(FILE_PERSON, ios::out | ios::binary);
                file.write((char *)&number_student, sizeof(number_student));
                for (int i = 0; i < number_student; i++)
                {
                    file.write((char *)&Per[i], sizeof(Per));
                }
                file.close();
                //*******************  SUBJECT  *******************
                file.open(FILE_SUBJECT, ios::out | ios::binary);
                file.write((char *)&number_subject, sizeof(number_subject));
                for (int i = 0; i < number_subject; i++)
                {
                    file.write((char *)&Sub[i], sizeof(Sub));
                }
                file.close();
                //*******************  REGISTER  *******************
                file.open(FILE_REGISTER, ios::out | ios::binary);
                file.write((char *)&number_register, sizeof(number_register));
                for (int i = 0; i < number_register; i++)
                {
                    file.write((char *)&Reg[i], sizeof(Reg));
                }
                file.close();

                //------------------END LUU FILE------------------------

                cout << endl;
                cout << "================================" << endl;
                system("cls");
            };
            default:
            {
                cout << "Xin mời nhập lại: " << endl;
                cin >> chuc_nang;
                break;
            };
            }
        } while (chuc_nang != 0);
    }
}
