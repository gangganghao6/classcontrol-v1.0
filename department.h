#ifndef DEPARTMENT
#define DEPARTMENT

#include "college.h"
using namespace std;
class department : public college
{
public:
    department() = default;
    department(string school_names,string college_names,string department_names) : college(school_names,college_names), department_name(department_names) {}

public:
    string department_name;

private:
    //vector<string> include_class;
};

#endif