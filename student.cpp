#include "student.h"
vector<string> student::get_all_info(void)
{
    vector<string> data;
    data.push_back(school_name);
    data.push_back(college_name);
    data.push_back(department_name);
    data.push_back(class_name);
    data.push_back(student_name);
    data.push_back(student_number);
    data.push_back(student_subject);
    data.push_back(student_teacher);
    if (is_submitted == true)
    {
        data.push_back("是");
    }
    else
    {
        data.push_back("否");
    }
    if (is_judged == true)
    {
        data.push_back("是");
    }
    else
    {
        data.push_back("否");
    }
    ostringstream medium;
    medium << score;
    string mediums = medium.str();
    data.push_back(mediums);
    return data;
}
bool student::compare_college(string data)
{
    if (data == college_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool student::compare_department(string data)
{
    if (data == department_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool student::compare_class(string data)
{
    if (data == class_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool student::compare_student(string data){
    if (data == student_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}