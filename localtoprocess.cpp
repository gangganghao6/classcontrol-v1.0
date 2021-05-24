#include "localtoprocess.h"
#include <iostream>
using namespace std;

vector<vector<string>> localto_student_information(void)
{
    ifstream student("D:\\studentinfo.csv", ios::in);
    if (!student.is_open())
    {
        vector<vector<string>> student_vec_vec;
        ofstream student("D:\\studentinfo.csv", ios::out);
        student.close();
        return student_vec_vec;
    }
    string line;
    vector<vector<string>> student_vec_vec;
    while (getline(student, line))
    {
        string temp;
        vector<string> student_vec;
        istringstream istudent(line);
        while (getline(istudent, temp, ','))
        {
            student_vec.push_back(temp);
        }
        student_vec_vec.push_back(student_vec);
    }
    return student_vec_vec;
}

vector<vector<string>> localto_teacher_information(void)
{
    ifstream teacher("D:\\teacherinfo.csv", ios::in);
    if (!teacher.is_open())
    {
        vector<vector<string>> teacher_vec_vec;
        ofstream teacher("D:\\teacherinfo.csv", ios::out);
        teacher.close();

        return teacher_vec_vec;
    }
    string line;

    vector<vector<string>> teacher_vec_vec;
    while (getline(teacher, line))
    {
        string temp;
        vector<string> teacher_vec;
        istringstream iteacher(line);
        while (getline(iteacher, temp, ','))
        {
            teacher_vec.push_back(temp);
        }
        teacher_vec_vec.push_back(teacher_vec);
    }
    return teacher_vec_vec;
}

vector<vector<string>> localto_subject_information(void)
{
    ifstream subject("D:\\subjectinfo.csv", ios::in);
    if (!subject.is_open())
    {
        vector<vector<string>> subject_vec_vec;
        ofstream subject("D:\\subjectinfo.csv", ios::out);
        subject.close();
        return subject_vec_vec;
    }
    string line;
    vector<vector<string>> subject_vec_vec;
    while (getline(subject, line))
    {
        string temp;
        vector<string> subject_vec;
        istringstream isubject(line);
        while (getline(isubject, temp, ','))
        {
            subject_vec.push_back(temp);
        }
        subject_vec_vec.push_back(subject_vec);
    }
    return subject_vec_vec;
}

vector<vector<vector<string>>> localto_loadingall(void)
{
    vector<vector<vector<string>>> all_data;
    vector<vector<string>> single_data;
    single_data = localto_student_information();
    all_data.push_back(single_data);
    single_data = localto_teacher_information();
    all_data.push_back(single_data);
    single_data = localto_subject_information();
    all_data.push_back(single_data);
    return all_data;
}

vector<vector<string>> infile_localto_student_information(string location)
{
    ifstream student(location, ios::in);
    string line;
    vector<vector<string>> student_vec_vec;
    while (getline(student, line))
    {
        string temp;
        vector<string> student_vec;
        istringstream istudent(line);
        while (getline(istudent, temp, ','))
        {
            student_vec.push_back(temp);
        }
        student_vec_vec.push_back(student_vec);
    }
    return student_vec_vec;
}