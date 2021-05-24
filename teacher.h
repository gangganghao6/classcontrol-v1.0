#ifndef TEACHER
#define TEACHER

#include "department.h"
//#include "creataccount.h"
using namespace std;
class teacher : public department
{
public:
    teacher() = default;
    teacher(string school_names, string college_names, string department_names, string teacher_names,
            string teacher_numbers, string teacher_passwords) : department(school_names, college_names, department_names), teacher_name(teacher_names), teacher_number(teacher_numbers),
                                           teacher_password(teacher_passwords) {}
    void add_teacher_subject(vector<string> data);
    void add_teacher_class(vector<string> data);
    vector<string> get_all_info(void);
    bool check_both(string account, string password);
    bool compare_teacher(string data);
    bool compare_department(string data);
    bool compare_college(string data);
    void delete_all_class(void);
    void delete_all_subject(void);

public:
    string teacher_name;
    string teacher_number;
    string teacher_password;
    vector<string> teacher_class;
    vector<string> teacher_subject;
};

#endif