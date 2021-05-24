#ifndef CLASSANDGRADE
#define CLASSANDGRADE

#include "department.h"
using namespace std;
class classandgrade : public department
{
public:
    classandgrade() = default;
    classandgrade(string school_names, string college_names, string department_names, string class_names) : department(school_names, college_names, department_names), class_name(class_names) {}
    //void add_class_student(vector<string> data);
    //vector<string> get_all_info(void);
    //friend classandgrade creat_class_account(string college_name, string department_name, string class_name, vector<string> class_students);

public:
    string class_name;

private:
    //vector<string> class_student;
};

#endif