#include <iostream>
using namespace std;
//прототип класса
class Student;
class Manager
{
public:
    // Методы класса
    int add_student(string name, int stunum,
                    string labname);
    int add_student(string name, int stunum,
                    int freshmenclass);
    int find_student(string name, int stunum,
                     string labname);
    int find_student(string name, int stunum,
                     int freshemenclass);
    int delete_student(string name, int stunum,
                       string labname);
    int delete_student(string name, int stunum,
                       int freshmenclass);
    int print_all();
    Student *manager_list[300];
    static int tot_stu;
};
class Student
{
private:
    string name;
    int stunum;
    int a;

public:
    //используем в конструкторе список
    /// инициализации вместо присваивания
    Student(string name_1, int
                               stunum_1) : name(name_1), stunum(stunum_1)
    {
    }
    //перезагрузка конструктора
    Student(int valueA) : a(valueA)
    {
    }
    //
    int isgrad;
    virtual void getinfo() const = 0;
    void printname() const
    {
        cout << "Student name " << name << ", student number " << stunum;
    }
    //объявляем дружественные функции перед
    // прототипом
    //перезагрузка оператора сравнения
    friend bool
    operator==(const Student &x,
               const Student &y);
    friend int Manager::add_student(string name,
                                    int stunum, string labname);
    friend int Manager::add_student(string name,
                                    int stunum, int freshmenclass);
    friend int Manager::delete_student(string
                                           name,
                                       int stunum, string labname);
    friend int Manager::delete_student(string
                                           name,
                                       int stunum, int freshmenclass);
};
//университет
class Grad_Student : public Student
{
private:
    string labname;
    //делигирующий конструктор
public:
    Grad_Student(string name, int stunum,
                 string labname_1) : Student(name, stunum)
    {
        labname = labname_1;
    }
    void getinfo() const
    {
        printname();
        cout << ", Group: " << labname << endl;
    }
    friend bool operator==(const Student &x,
                           const Student &y);
};
//школьники
class Undergrad_Student : public Student
{
private:
    int freshmenclass;

public:
    //делигирующий конструктор
    Undergrad_Student(string name, int stunum,
                      int freshmenclass_1) : Student(name, stunum)
    {
        freshmenclass = freshmenclass_1;
    }
    void getinfo() const
    {
        printname();
        cout << ", Grade: " << freshmenclass << endl;
    }
    //перегрузка оператора =
    friend bool operator==(const Student &x,
                           const Student &y);
};
