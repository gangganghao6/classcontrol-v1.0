#include "teachermenu.h"

char print_teacher_menu(void)
{
    system("cls");
    cout << "教师-菜单" << endl;
    cout << "1.查看学生信息" << endl;
    cout << "2.课设打分" << endl;
    cout << "3.查看教师信息" << endl;
    char choose = process_teacher_choose();
    return choose;
}
char process_teacher_choose(void)
{
    char choose = getch();
    if (choose < '1' && choose > '2')
    {
        return 'n';
    }
    else
    {
        return choose;
    }
}
char t_show_find_way(void)
{
    while (true)
    {
        system("cls");
        cout << "教师-查找方式" << endl;
        cout << "1.按照班级查询" << endl;
        cout << "2.手动输入查询" << endl;
        char choose = getch();
        if (choose != '1' && choose != '2')
        {
            system("cls");
            cout << "输入无效！请重新输入！" << endl;
            system("pause");
            continue;
        }
        else
        {
            system("cls");
            return choose;
        }
    }
}
void check_student_info(vector<student> &student_class, teacher &teacher_account)
{
    char choose = t_show_find_way();
    string t_department = teacher_account.department_name;
    if (choose == '1')
    {
        cout << "按照院系班级查询" << endl;
        string find_class = show_all_class(student_class, t_department);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_student = show_all_student(student_class, find_class);
        system("cls");
        find_this_student(student_class, find_student, find_class);
    }
    else
    {
        cout << "手动查询" << endl;
        string college_names, department_names, class_names, student_names;
        cout << "学院名称:";
        cin >> college_names;
        cout << "专业名称:";
        cin >> department_names;
        cout << "班级名称:";
        cin >> class_names;
        cout << "学生姓名:";
        cin >> student_names;
        for (auto studentx : student_class)
        {
            if ((studentx.compare_college(college_names) == true) && (studentx.compare_department(department_names) == true) &&
                (studentx.compare_class(class_names) == true) && (studentx.compare_student(student_names) == true))
            {
                cout << "学校:" << studentx.school_name << endl;
                cout << "学院:" << studentx.school_name << endl;
                cout << "专业:" << studentx.school_name << endl;
                cout << "班级:" << studentx.school_name << endl;
                cout << "姓名:" << studentx.school_name << endl;
                cout << "学号:" << studentx.school_name << endl;
                cout << "课设名称:" << studentx.school_name << endl;
                cout << "指导老师:" << studentx.school_name << endl;
                cout << "是否提交:";
                if (studentx.is_submitted == true)
                {
                    cout << "是" << endl;
                }
                else
                {
                    cout << "否" << endl;
                }
                cout << "是否评定:";
                if (studentx.is_judged == true)
                {
                    cout << "是" << endl;
                }
                else
                {
                    cout << "否" << endl;
                }
                cout << "评定成绩:" << studentx.score << endl;
                return;
            }
        }
    }
}
void check_teacher_info(teacher &teacherx)
{
    cout << "学校:" << teacherx.school_name << endl;
    cout << "学院:" << teacherx.college_name << endl;
    cout << "专业:" << teacherx.department_name << endl;
    cout << "姓名:" << teacherx.teacher_name << endl;
    cout << "手机号(账号):" << teacherx.teacher_number << endl;
    cout << "密码:" << teacherx.teacher_password << endl;
    cout << "负责班级:" << endl;
    for (auto t_class : teacherx.teacher_class)
    {
        cout << "         " << t_class << endl;
    }
    cout << "负责课设:" << endl;
    for (auto t_subject : teacherx.teacher_subject)
    {
        cout << "         " << t_subject << endl;
    }
}
void teacher_manage_student_info(vector<student> &student_class, teacher &teacher_account, vector<subject> &subject_class)
{
    system("cls");
    for (auto &single_stu : student_class)
    {
        system("cls");

        if (single_stu.student_teacher == teacher_account.teacher_name)
        {
            if (single_stu.is_submitted && (!single_stu.is_judged))
            {
                cout << "学生-" << single_stu.student_name << "课设评定" << endl;
                cout << "课设名称:" << single_stu.student_subject << endl;
                cout << "成绩:";
                int score;
                cin >> score;
                single_stu.score = score;
                single_stu.is_judged = true;
                subject change_sub = find_this_subject(subject_class, single_stu.student_subject, single_stu.department_name);
            }
        }
    }
}
