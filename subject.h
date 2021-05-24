#ifndef SUBJECT
#define SUBJECT

#include "department.h"
using namespace std;
class subject : public department
{
public:
    subject() = default;
    subject(string school_names, string college_names, string department_names, string subject_names,
            string subject_teachers, int should_submits = 0, int actual_submits = 0, int actual_judges = 0) : department(school_names, college_names, department_names), subject_name(subject_names),
                                                                                                              subject_teacher(subject_teachers)
    {
    }
    vector<string> add_subject_class(vector<string> data);
    vector<string> get_all_info(void);
    bool compare_subject(string data);
    bool compare_department(string data);
    bool compare_college(string data);
    void add_subject_class_s(vector<string> data);
    void delete_all_class(void);

public:
    string subject_name;
    string subject_teacher;
    vector<string> subject_class;
};

#endif