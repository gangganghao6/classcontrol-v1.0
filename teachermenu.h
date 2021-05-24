#ifndef TEACHERMENU
#define TEACHERMENU

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include "student.h"
#include "teacher.h"
#include "subject.h"
#include "classandgrade.h"
#include "rootmenu.h"

using namespace std;

char print_teacher_menu(void);
char process_teacher_choose(void);
char t_show_find_way(void);

void check_student_info(vector<student> &student_class, teacher &teacher_account);
void teacher_manage_student_info(vector<student> &student_class, teacher &teacher_account, vector<subject> &subject_class);
void check_teacher_info(teacher &teacher_account);

#endif