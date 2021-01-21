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
    // char *a = setlocale(LC_ALL, "vietnamese");

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
        fstream fileStu;
        cout << "open file Stu" << endl;
        fileStu.open(FILE_STUDENT, ios::in);
        fileStu.read((char *)&number_student, sizeof(number_student));
        for (int i = 0; i < number_student; i++)
        {
            fileStu.read((char *)&Stu[i], sizeof(Stu));
        }
        fileStu.close();
        //*******************  PERSON  *******************
        fstream filePer;
        cout << "open file Per" << endl;
        filePer.open(FILE_PERSON, ios::out);
        // file.read((char *)&number_student, sizeof(number_student));
        for (int i = 0; i < number_student; i++)
        {
            filePer.read((char *)&Per[i], sizeof(Per));
        }
        filePer.close();
        //*******************  SUBJECT  *******************
        fstream fileSj;
        cout << "open file Sub" << endl;
        fileSj.open(FILE_SUBJECT, ios::out);
        fileSj.read((char *)&number_subject, sizeof(number_subject));
        for (int i = 0; i < number_subject; i++)
        {
            fileSj.read((char *)&Sub[i], sizeof(Sub));
        }
        fileSj.close();
        //*******************  REGISTER  *******************
        fstream fileReg;
        cout << "open file Reg" << endl;
        fileReg.open(FILE_REGISTER, ios::out);
        fileReg.read((char *)&number_register, sizeof(number_register));
        for (int i = 0; i < number_register; i++)
        {
            fileReg.read((char *)&Reg[i], sizeof(Reg));
        }
        fileReg.close();
    }
    //------------------END DOC FILE------------------------

    {
        system("cls"); // system("clear") đối với máy mac, linux, ubuntu,..
        //------------------CHUC NANG CHINH---------------------
        cout << "\t\t\t\t\tPhan mem quan ly sinh vien\n";
        cout << "\t\t\t\t\t\tHoang Nam\n\n";
        cout << "---------------------------------------------------\n";

        cout << "1. Them moi sinh vien." << endl;
        cout << "2. Sua thong tin sinh vien (theo ma)." << endl;
        cout << "3. Xoa sinh vien." << endl;
        cout << "4. Tim sinh vien theo ten gan dung." << endl;
        cout << "5. Them moi mon hoc." << endl;
        cout << "6. Dang ky mon hoc." << endl;
        cout << "7. Hien thi danh sach sinh vien." << endl;
        cout << "8. Hien thi danh sach mon hoc." << endl;
        cout << "9. Hien thi ban dang ky." << endl;
        cout << "10. Sap xep ban dang ky." << endl;
        cout << "0. Thoat khoi he thong." << endl;

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
                float package_f;
                cout << "Nhap so Chung minh/Can cuoc/Ho chieu: " << endl;
                cin >> package;
                Per[number_student].setId(package);
                Per[number_student].readName();
                Per[number_student].readDate();
                Per[number_student].readEmail();

                cout << "Nhap ma sinh vien: " << endl;
                cin >> package;
                Stu[number_student].setId(package);
                cout << "Nhap diem trung binh: " << endl;
                cin >> package_f;
                Stu[number_student].setRba(package_f);
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
                        cout << "Nhap lai ma sinh vien can sua: ";
                    else
                        cout << "Nhap ma sinh vien can sua: ";
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
                cout << "Sua thong tin sinh vien: " << endl;
                int chuc_nang_sua;
                check = false;
                first = 0;
                cout << "1. Sua ma sinh vien." << endl;
                cout << "2. Sua ten." << endl;
                cout << "3. Sua ngay thang nam sinh." << endl;
                cout << "4. Sua email." << endl;
                cout << "5. Sua so Chung minh/Can cuoc/Ho chieu." << endl;
                cout << "6. Sua diem trung binh." << endl;
                cout << "7. Sua chuyen nganh" << endl;
                do
                {
                    first++;
                    if (first > 1)
                        cout << "Moi nhap lai: " << endl;
                    cin >> chuc_nang_sua;
                    if ((chuc_nang_sua < 7) && (chuc_nang_sua > 1))
                        check = true;
                } while (check == false);
                package = 0;
                switch (chuc_nang_sua)
                {
                case 1:
                {
                    cout << "Nhap lai ma sinh vien: " << endl;
                    cin >> package;
                    Stu[position].setId(package);
                    break;
                }
                case 2:
                {
                    cout << "Nhap lai ten sinh vien: " << endl;
                    Per[position].readName();
                    break;
                }
                case 3:
                {
                    cout << "Nhap lai ngay thang nam sinh: " << endl;
                    Per[position].readDate();
                    break;
                }
                case 4:
                {
                    cout << "Nhap lai email: " << endl;
                    Per[position].readEmail();
                    break;
                }
                case 5:
                {
                    cout << "Nhap lai so Chung minh/Can cuoc/Ho chieu: " << endl;
                    cin >> package;
                    Per[position].setId(package);
                    break;
                }
                case 6:
                {
                    cout << "Nhap lai diem trung binh: " << endl;
                    cin >> package;
                    Stu[position].setRba(package);
                    break;
                }
                default:
                {
                    cout << "Nhap lai chuyen nganh." << endl;
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
                        cout << "Nhap lai ma sinh vien can xoa: ";
                    else
                        cout << "Nhap ma sinh vien can xoa: ";
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
                cout << "Nhap ten can tim: " << endl;
                cin.getline(find, 100);
                for (int i = 0; i < number_student; i++)
                {
                    if (Per[i].findName(find) == true)
                    {
                        cout << "-------------------------------";
                        cout << "Ho ten: ";
                        Per[i].coutName();
                        cout << endl;
                        cout << "Ma sinh vien: "
                             << Stu[i].getId() << endl;
                        cout << "-------------------------------";
                    }
                }
            };
            case 5:
            {
                //5. Thêm mới môn học.

                int package;
                cout << "Nhap id mon hoc: " << endl;
                cin >> package;
                Sub[number_subject].setId(package);
                Sub[number_subject].readName();
                cout << "Nhap he so tin chi: " << endl;
                cin >> package;
                Sub[number_subject].setCredit(package);
                cout << "Nhap so tiet cua mon hoc: " << endl;
                cin >> package;
                Sub[number_subject].setLesson(package);
                number_subject++;
                break;
            };
            case 6:
            {
                //6. Đăng ký môn học.

                int package;
                cout << "Dang ky mon hoc: " << endl;
                cout << "Nhap ma sinh vien dang ky: " << endl;
                cin >> package;
                Reg[number_register].setIdStudent(package);
                cout << "Nhap ma mon dang ky: " << endl;
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
                cout << "Danh sach sinh vien: " << endl
                     << endl;
                for (int i = 0; i < number_student; i++)
                {
                    cout << "Sinh vien " << Stu[i].getId() << ": " << endl;
                    cout << "Ho ten: ";
                    Per[i].coutName();
                    cout << endl;
                    cout << "Ngay sinh: " << Per[i].getDate().day << "/"
                         << Per[i].getDate().month << "/"
                         << Per[i].getDate().year << endl;
                    cout << "Diem trung binh: " << Stu[i].getRba() << endl;
                    cout << "Chuyen nganh: ";
                    Stu[i].coutMajor();
                    cout << endl;
                    cout << "Email: ";
                    Per[i].coutEmail();
                    cout << endl;
                    cout << "So chung minh/Can cuoc/Ho chieu: ";
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
                cout << "Danh sach mon hoc: " << endl
                     << endl;
                for (int i = 0; i < number_subject; i++)
                {
                    cout << "Ma mon hoc: " << Sub[i].getId() << endl;
                    cout << "Ten lop: ";
                    Sub[i].coutName();
                    cout << endl;
                    cout << "He so tin chi: " << Sub[i].getCredit() << endl;
                    cout << "So tiet: " << Sub[i].getLesson() << endl;
                    cout << "--------------------------" << endl
                         << endl;
                };
                break;
            }
            case 9:
            {
                // 9. Hiển thị bản đăng ký.

                cout << "*********************************" << endl;
                cout << "Danh sach ban dang ky: " << endl
                     << endl;
                for (int i = 0; i < number_subject; i++)
                {
                    cout << "Ma sinh vien: " << Reg[i].getIdStudent() << endl;
                    cout << "Ma lop: " << Reg[i].getIdSubject() << endl;
                    cout << "--------------------------" << endl
                         << endl;
                };
                break;
            };
            case 10:
            {
                // 10. Sắp xếp bản đăng ký.

                int package = 0;
                cout << "Sap xep ban dang ky theo thoi gian: " << endl;
                cout << "1. Cu -> moi" << endl;
                cout << "2. Moi -> cu" << endl;
                int first = 0;
                bool check = false;
                do
                {
                    first++;
                    if (first > 1)
                        cout << "Nhap lai: " << endl;
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
                cout << "Sap xep hoan thanh! " << endl;
                break;
            };
            case 0:
            {
                // 0. Thoát khỏi hệ thống.
                //------------------LUU FILE----------------------------

                //*******************  STUDENT  *******************
                fstream fileStu;
                cout << "close file Stu" << endl;
                fileStu.open(FILE_STUDENT, ios::out);
                fileStu.write((char *)&number_student, sizeof(number_student));
                for (int i = 0; i < number_student; i++)
                {
                    fileStu.write((char *)&Stu[i], sizeof(Stu));
                }
                fileStu.close();
                //*******************  PERSON  *******************
                fstream filePer;
                cout << "close file Per" << endl;
                filePer.open(FILE_PERSON, ios::out);
                // file.write((char *)&number_student, sizeof(number_student));
                for (int i = 0; i < number_student; i++)
                {
                    filePer.write((char *)&Per[i], sizeof(Per));
                }
                filePer.close();
                //*******************  SUBJECT  *******************
                fstream fileSj;
                cout << "close file Sub" << endl;
                fileSj.open(FILE_SUBJECT, ios::out);
                fileSj.write((char *)&number_subject, sizeof(number_subject));
                for (int i = 0; i < number_subject; i++)
                {
                    fileSj.write((char *)&Sub[i], sizeof(Sub));
                }
                fileSj.close();
                //*******************  REGISTER  *******************
                fstream fileReg;
                cout << "close file Reg" << endl;
                fileReg.open(FILE_REGISTER, ios::out);
                fileReg.write((char *)&number_register, sizeof(number_register));
                for (int i = 0; i < number_register; i++)
                {
                    fileReg.write((char *)&Reg[i], sizeof(Reg));
                }
                fileReg.close();

                //------------------END LUU FILE------------------------

                cout << endl;
                cout << "================================" << endl;
                system("cls");
                break;
            };
            default:
            {
                cout << "Xin moi nhap lai " << endl;
                cin >> chuc_nang;
                break;
            };
            }
        } while (chuc_nang != 0);
    }
}
