#include "processtolocal.h"
using namespace std;

void tolocal_student_information(vector<vector<string>> student_vec_vec)
{
    ofstream student("D:\\studentinfo.csv", ios::trunc);
    for (auto &student_vec : student_vec_vec)
    {
        for (auto &student_info : student_vec)
        {
            student << student_info << ',';
        }
        student << '\n';
    }
    student.close();
}

void tolocal_teacher_information(vector<vector<string>> teacher_vec_vec)
{
    ofstream teacher("D:\\teacherinfo.csv", ios::trunc);
    for (auto &teacher_vec : teacher_vec_vec)
    {
        for (auto &teacher_info : teacher_vec)
        {
            teacher << teacher_info << ',';
        }
        teacher << '\n';
    }
    teacher.close();
}

void tolocal_subject_information(vector<vector<string>> subject_vec_vec)
{
    ofstream subject("D:\\subjectinfo.csv", ios::trunc);
    for (auto &subject_vec : subject_vec_vec)
    {
        for (auto &subject_info : subject_vec)
        {
            subject << subject_info << ',';
        }
        subject << '\n';
    }
    subject.close();
}

/*void tolocal_classandgrade_information(vector<vector<string>> classandgrade_vec_vec)
{
    ofstream classandgrade("C:\\Users\\53039\\Desktop\\classandgradeinfo.csv", ios::trunc);
    for (auto &classandgrade_vec : classandgrade_vec_vec)
    {
        for (auto &classandgrade_info : classandgrade_vec)
        {
            classandgrade << classandgrade_info << ',';
        }
        classandgrade << '\n';
    }
    classandgrade.close();
}*/

void tolocal_loadingall(vector<vector<vector<string>>> all_data)
{
    tolocal_student_information(all_data[0]);
    tolocal_teacher_information(all_data[1]);
    tolocal_subject_information(all_data[2]);
    //tolocal_classandgrade_information(all_data[3]);
}