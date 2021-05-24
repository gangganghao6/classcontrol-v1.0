#include "teacher.h"

void teacher::add_teacher_subject(vector<string> data)
{
    for (auto datas : data)
    {
        teacher_subject.push_back(datas);
    }
}
void teacher::add_teacher_class(vector<string> data)
{
    for (auto datas : data)
    {
        teacher_class.push_back(datas);
    }
}
vector<string> teacher::get_all_info(void)
{
    vector<string> data;
    data.push_back(school_name);
    data.push_back(college_name);
    data.push_back(department_name);
    data.push_back(teacher_name);
    data.push_back(teacher_number);
    data.push_back(teacher_password);
    data.push_back(vector_to_singlevector(teacher_class));
    data.push_back(vector_to_singlevector(teacher_subject));
    return data;
}
bool teacher::check_both(string account, string password)
{
    if (teacher_number == account && teacher_password == password)
    {
        return true;
    }
    else
        return false;
}
bool teacher::compare_teacher(string data)
{
    if (data == teacher_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool teacher::compare_department(string data)
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
bool teacher::compare_college(string data)
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
void teacher::delete_all_class(void)
{
    teacher_class.clear();
}
void teacher::delete_all_subject(void)
{
    teacher_subject.clear();
}
