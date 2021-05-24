#ifndef COLLEGE
#define COLLEGE

#include "school.h"
using namespace std;
class college : public school
{
public:
    college() = default;
    college(string school_names, string college_names) : school(school_names), college_name(college_names) {}

public:
    string college_name;

private:
    //vector<string> include_department;
};

#endif