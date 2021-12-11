#include <iostream>
#include "student.h"
//инициализируем статическую переменную
int Manager::tot_stu = 0;
int Manager::add_student(string name, int stunum,
                         string labname)
{
    // Добавляет объект Grad_Student с заданным аргументом
    // stunum положительный и уникальный. Если этот метод вызывается с существующим stunum, он возвращает 1
    // Возвращает общее количество объектов в массиве
    //  student после добавления и в случае неудачи
    // возвращает - 1. if (stunum <= 0) 23 if (stunum <= 0) return -1;
    if (tot_stu == 300)
    {
        return -1;
    }
    if (tot_stu != 0)
    {
        for (int j = 0; j < tot_stu; j++)
        {
            if (manager_list[j]->stunum == stunum)
            {
                return -1;
            }
        }
    }
    Student *grad_student = new Grad_Student(name,
                                             stunum, labname);
    grad_student->isgrad = 1;
    manager_list[tot_stu] = grad_student;
    tot_stu += 1;
    cout << "university student added" << endl;
    return tot_stu;
};
int Manager::add_student(string name, int stunum,
                         int freshmenclass)
{
    // Создает объект Undergrad_Student с заданным аргументом
    // stunum положительный и уникальный. Если этот метод вызывается с существующим stunum, он
    // возвращает -
    //  1.
    // Возвращает общее количество объектов в массиве
    //student после добавления и в случае неудачи
    //     возвращает -1.
    if (stunum <= 0 || freshmenclass <= 0 || tot_stu == 300)
        return -1;
    if (tot_stu != 0)
    {
        for (int j = 0; j < tot_stu; j++)
        {
            if (manager_list[j]->stunum == stunum)
            {
                return -1;
            }
        }
    }
    Student *undergrad_student = new Undergrad_Student(name, stunum, freshmenclass);
    undergrad_student->isgrad = 0;
    manager_list[tot_stu] = undergrad_student;
    tot_stu += 1;

    cout << "School student added" << endl;
    return tot_stu;
};
int Manager::find_student(string name, int stunum,
                          string labname)
{
    // Находит объект Grad_Student в массиве student, который совпадает с объектом Grad_Student
    //с заданным аргументом
    // Этот метод печатает всю информацию о
    //подобранном объекте
    // Возвращает индекс совпадающего объекта (индекс
    //первого объекта = 0), -1, если совпадения нет
    int i = -1;
    Student *grad_student = new Grad_Student(name,
                                             stunum, labname);
    grad_student->isgrad = 1;
    for (int j = 0; j < tot_stu; j++)
    {
        if (*manager_list[j] == *grad_student)
        {
            i = j;

            cout << "There is already such a student:" << endl;
            manager_list[j]->getinfo();
            break;
        }
        else
        {
            cout << "There is no such student" << endl;
        }
    }
    delete grad_student;

    return i;
};
int Manager::find_student(string name, int stunum,
                          int freshmenclass)
{
    // Находит объект Undergrad_Student в массиве
    //student, который совпадает с объектом
    //Undergrad_Student с заданным аргументом
    // Этот метод должен печатать вспечатает всю
    //информацию о подобранном объекте
    // Возвращает индекс совпадающего объекта (индекс
    //первого объекта = 0), -1, если совпадения нет
    int i = -1;
    Student *undergrad_student = new Undergrad_Student(name, stunum, freshmenclass);
    undergrad_student->isgrad = 0;
    for (int j = 0; j < tot_stu; j++)
    {
        if (*manager_list[j] == *undergrad_student)
        {
            i = j;
            cout << "There is already such a student:" << endl;
            manager_list[j]->getinfo();
            break;
        }
        else
        {
            cout << "There is no such student" << endl;
        }
    }
    delete undergrad_student;

    return i;
};
int Manager::delete_student(string name, int stunum, string labname)
{
    // Удаляет объект Grad_Student в массиве
    //student, который совпадает с объектом Grad_Student с заданным аргументом, ничего не делает, если нет совпадения
    // Возвращает общее количество объектов в массиве
    // student после удаления
    // Если нет объекта, соответствующего объекту
    //аргумента,
    //  возвращает - 1.
    int i = -1;
    Student *grad_student = new Grad_Student(name,
                                             stunum, labname);
    grad_student->isgrad = 1;
    int k;
    for (int j = 0; j < tot_stu; j++)
    {
        if (*manager_list[j] == *grad_student)
        {
            tot_stu -= 1;
            i = tot_stu;
            k = j;
            delete manager_list[j];
            for (k; k < tot_stu; k++)
            {
                manager_list[k] = manager_list[k + 1];
            }
            manager_list[tot_stu] = NULL;
            break;
        }
    }
    delete grad_student;
    cout << "university student excluded" << endl;
    return i;
};
int Manager::delete_student(string name, int stunum, int freshmenclass)
{
    // Удаляет объект Undergrad_Student в массиве
    // student, который совпадает с объектом Undergrad_Student с заданным аргументом, ничего не делает, если нет совпадения
    // Возвращает общее количество объектов в массиве
    // student после удаления
    // Если нет объекта, соответствующего объекту
    //аргумента,
    // возвращает - 1.
    int i = -1;
    Student *undergrad_student = new Undergrad_Student(name, stunum, freshmenclass);
    undergrad_student->isgrad = 0;
    int k;
    for (int j = 0; j < tot_stu; j++)
    {
        if (*manager_list[j] == *undergrad_student)
        {
            tot_stu -= 1;
            i = tot_stu;
            k = j;
            delete manager_list[j];
            for (k; k < tot_stu; k++)
            {
                manager_list[k] = manager_list[k + 1];
            }
            manager_list[tot_stu] = NULL;
            break;
        }
    }
    delete undergrad_student;
    cout << "School student excluded" << endl;
    return i;
};
int Manager::print_all()
{
    // Выводит всю информацию о существующем объекте в
    /// массиве student
    // Возвращает общее количество объектов в массиве student
    if (tot_stu == 0)
    {
        cout << "There are no students in our university" << endl;
        return 0;
    }
    int i = 0;
    for (i; i < tot_stu; i++)
    {
        manager_list[i]->getinfo();
    }

    return tot_stu;
};
bool operator==(const Student &x, const Student &
                                      y)
{
    // эксплуатационная перегрузка оператора ==
    // (используется в функции поиска студента)
    // Проверьте, имеют ли два студента x, y
    //одинаковую информацию или нет.
    // Возвращает true, если два студента одинаковы, в
    // противном случае  false.
    if (x.isgrad != y.isgrad)
    {
        return false;
    }

    if (x.isgrad == 0)
    {
        const Student &z = x;
        const Student &w = y;
        const Undergrad_Student &u =
            (Undergrad_Student &)(z);
        const Undergrad_Student &un =
            (Undergrad_Student &)(w);
        if (u.name != un.name || u.stunum != un.stunum || u.freshmenclass != un.freshmenclass)
        {
            return false;
        }
    }
    if (x.isgrad == 1)
    {
        const Student &z = x;
        const Student &w = y;
        const Grad_Student &p = (Grad_Student &)(z);
        const Grad_Student &pn = (Grad_Student &)(w);
        if (p.name != pn.name || p.stunum != pn.stunum || p.labname != pn.labname)
        {
            return false;
        }
    }
    return true;
};
