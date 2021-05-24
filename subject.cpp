#include "subject.h"
vector<string> subject::add_subject_class(vector<string> data)
{
    for (auto datas : data)
    {
        subject_class.push_back(datas);
    }
    return subject_class;
}
vector<string> subject::get_all_info(void)
{
    vector<string> data;
    data.push_back(school_name);
    data.push_back(college_name);
    data.push_back(department_name);
    data.push_back(subject_name);
    data.push_back(subject_teacher);

    data.push_back(vector_to_singlevector(subject_class));

    return data;
}
bool subject::compare_department(string data)
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
bool subject::compare_subject(string data)
{
    if (data == subject_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool subject::compare_college(string data)
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
void subject::add_subject_class_s(vector<string> data)
{
    for (auto datas : data)
    {
        subject_class.push_back(datas);
    }
}
void subject::delete_all_class(void)
{
    subject_class.clear();
}