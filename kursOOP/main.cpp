#include <iostream>
#include <stdexcept>
#include <string>
#include "student.h"
#include <stdlib.h>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char command;
    Manager myman;
    int isgrad;
    std::string name;
    int stunum;
    std::string labname;
    int freshmenclass;
    //int index;
    bool isLast = true;
    system("clear");
    while (isLast)
    {
        cout << "\n\n\n*---------------------Welcome to student control system-- -------------------*" << endl;
        cout
            << "What do you want to do? \n1. Add student: a \n2. Find student: f \n3. Remove student: d \n4. Output all students: p \n5. Output: q" << endl;

        cout << "Enter the command: ";

        cin >> command;
        if (command != 'a' && command != 'c' &&
            command != 'f' && command != 'd' && command != 'p' && command != 'q')
        {
            cerr << "invalid argument" << endl;
            continue;
        }
        switch (command)
        {
        case 'a':
        {
            system("clear");
            cout << "Select which student you want to add \n \n Choice \n school student: 0       university student: 1" << endl;
            cout << "Enter the command: ";
            cin >> isgrad;
            if (isgrad != 1 && isgrad != 0)
            {
                cerr << "invalid argument"
                     << endl;
                break;
            }
            if (isgrad == 1)
            {
                system("clear");
                cout << "\nFormat: [name, number, group]" << endl;

                cout << "Enter the command: ";
                cin >> name >> stunum >> labname;
                if (stunum <= 0)
                {
                    cerr << "number  must be positive !" << endl;
                    break;
                }
                myman.add_student(name, stunum,
                                  labname);
            }
            else if (isgrad == 0)
            {
                system("clear");
                cout << "\nFormat: [name, number , class] " << endl;
                cout << "Enter the command: ";
                cin >> name >> stunum >>
                    freshmenclass;
                if (stunum <= 0 || freshmenclass <=
                                       0)
                {
                    system("clear");
                    cerr << "сlass and number must be positive " << endl;
                    break;
                }
                myman.add_student(name, stunum,
                                  freshmenclass);
            }
        }
        break;
        case 'f':
        {

            cout << "Find Student \n \nSelection \nschool student: 0       university student: 1 " << endl;
            cout
                << "Enter the command: ";
            cin >> isgrad;
            if (isgrad != 1 && isgrad != 0)
            {
                cerr << "invalid argument"
                     << endl;
                break;
            }
            if (isgrad == 1)
            {

                cout << "\n Format: [name, number, group]" << endl;
                cout << "Enter the command: ";
                cin >> name >> stunum >> labname;
                if (stunum <= 0)
                {
                    cerr << "Stunum must be positive !" << endl;
                    break;
                }
                myman.find_student(name, stunum,
                                   labname);
            }
            else if (isgrad == 0)
            {

                cout << "\nFormat: [name number class]" << endl;
                cout << "Enter the command: ";
                cin >> name >> stunum >>
                    freshmenclass;

                if (stunum <= 0 || freshmenclass <= 0)
                {
                    cerr << "number class  must be positive !" << endl;
                    break;
                }
                myman.find_student(name, stunum,
                                   freshmenclass);
            }
        }
        break;
        case 'd':
        {

            cout << "Enter the student you want to unavailable \n \nOption:\n school student: 0       university student: 1" << endl;
            cout
                << "Enter the command: ";
            cin >> isgrad;
            if (isgrad != 1 && isgrad != 0)
            {
                cerr << "Invalid argument" << endl;
                break;
            }
            if (isgrad == 1)
            {
                system("clear");
                cout << "\nFormat: [name, number, group]" << endl;
                cout << "Enter the command: ";
                cin >> name >> stunum >> labname;
                if (stunum <= 0)
                {
                    cerr << "Stunum must be positive !" << endl;
                    break;
                }
                myman.delete_student(name, stunum,
                                     labname);
            }
            else if (isgrad == 0)
            {
                system("clear");
                cout << "\nFormat: [name number class]" << endl;
                cout << "Enter the command: ";
                cin >> name >> stunum >>
                    freshmenclass;
                if (stunum <= 0 || freshmenclass <=
                                       0)
                {
                    cerr << "number class must be positive !" << endl;
                    break;
                }
                myman.delete_student(name, stunum,
                                     freshmenclass);
            }
        }
        break;
        case 'p':
        {
            system("clear");
            cout << "Bring out all students" << endl;
            myman.print_all();
        }
        break;
        case 'q':
        {
            cout << "exit" << endl;
            isLast = false;
        }
        break;
        default:
        {
            cout << "Invalid argument" << endl;
        }
        break;
        }
    }
    return 0;
}