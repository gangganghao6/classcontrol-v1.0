#ifndef ROOTMENU
#define ROOTMENU

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include "student.h"
#include "teacher.h"
#include "subject.h"
#include "classandgrade.h"

using namespace std;
char print_root_menu(void);
char process_root_choose(void);
char show_find_way(void);

student manage_student_info(vector<student> &students, vector<teacher> &teachers, vector<subject> &subjects, char &choice);
teacher manage_teacher_info(vector<student> &students, vector<teacher> &teachers, vector<subject> &subjects, char &choice);
subject manage_subject_info(vector<student> &students, vector<teacher> &teachers, vector<subject> &subjects, char &choice);

string show_all_college(vector<student> students, vector<teacher> teachers, vector<subject> subjects);
string show_all_department(vector<student> students, vector<teacher> teachers, vector<subject> subjects, string find);

string show_all_class(vector<student> students, string find);
string show_all_student(vector<student> students, string find_class);
string show_all_teacher(vector<teacher> teachers, string find_department);
string show_all_subject(vector<subject> subjects, string find_department);

string show_all_teacher_college(vector<teacher> teachers);
string show_all_teacher_department(vector<teacher> teachers, string find_college);
string show_all_subject_college(vector<subject> subjects);
string show_all_subject_department(vector<subject> subjects, string find_college);

student &find_this_student(vector<student> &students, string find_student, string find_class);
teacher &find_this_teacher(vector<teacher> &teachers, string find_teacher, string find_department);
subject &find_this_subject(vector<subject> &subjects, string find_subject, string find_department);

void change_stu_info(student &data);
void change_teacher_info(teacher &data);
void change_subject_info(subject &data);
void delete_this_student(vector<student>::iterator it,vector<student> &students);
void delete_this_teacher(vector<teacher>::iterator it, vector<teacher> &teachers);
void delete_this_subject(vector<subject>::iterator it, vector<subject> &subjects);

#endif