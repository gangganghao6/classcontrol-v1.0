#ifndef STUDENT
#define STUDENT

#include "classandgrade.h"
using namespace std;
class student : public classandgrade
{
public:
    student() = default;
    student(string school_names, string college_names, string department_names,
            string class_names, string student_names, string student_numbers, string student_subjects, string student_teachers,
            bool is_submitteds = false, bool is_judgeds = false, double scores = 0) : classandgrade(school_names, college_names, department_names, class_names),
                                                                                      student_name(student_names), student_number(student_numbers), student_subject(student_subjects),
                                                                                      student_teacher(student_teachers), is_submitted(is_submitteds), is_judged(is_judgeds),
                                                                                      score(scores) {}
    vector<string> get_all_info(void);
    bool compare_college(string data);
    bool compare_department(string data);
    bool compare_class(string data);
    bool compare_student(string data);
    friend void show_all_college(void);

public:
    string student_name;
    string student_number;
    string student_subject;
    string student_teacher;
    bool is_submitted;
    bool is_judged;
    double score;
};

#endif