#include "rootmenu.h"
char print_root_menu(void)
{
    system("cls");
    cout << "管理员-菜单" << endl;
    cout << "1.管理学生信息" << endl;
    cout << "2.管理教师信息" << endl;
    cout << "3.管理课设信息" << endl;
    cout << "4.从外部导入学生数据\n\n"
         << endl;
    cout << "注：若修改某个学生/教师/课设信息，需要同步修改其他信息" << endl;
    cout << "例如：若修改了教师 张三 的 管理班级，需要同时修改学生 李四 的 指导老师" << endl;
    char choose = process_root_choose();
    return choose;
}
char process_root_choose(void)
{
    char choose = getch();
    if (choose < '1' && choose > '4')
    {
        return 'n';
    }
    else
    {
        return choose;
    }
}
student manage_student_info(vector<student> &students, vector<teacher> &teachers, vector<subject> &subjects, char &choice)
{
    char choose = show_find_way();
    choice = choose;
    if (choose == '1')
    {
        cout << "按照院系班级查询" << endl;
        string find_college = show_all_college(students, teachers, subjects);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_department = show_all_department(students, teachers, subjects, find_college);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_class = show_all_class(students, find_department);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_student = show_all_student(students, find_class);
        system("cls");
        return (find_this_student(students, find_student, find_class));
    }
    else if (choose == '2')
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
        /*for (auto studentx : students)
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
                static student x;
                return (x);
            }
        }*/
        system("cls");
        return (find_this_student(students, student_names, class_names));
    }
    else if (choose == '3')
    {

        string college_names, department_names, class_names, subject_names, student_names, student_numbers, student_teachers, submit, judge;
        bool is_submits, is_judges;
        double scores;
        cout << "新增学生" << endl;
        cout << "学院:";
        cin >> college_names;
        cout << "专业:";
        cin >> department_names;
        cout << "班级:";
        cin >> class_names;
        cout << "学生姓名:";
        cin >> student_names;
        cout << "学号:";
        cin >> student_numbers;
        cout << "课设名称:";
        cin >> subject_names;
        cout << "指导老师:";
        cin >> student_teachers;
        cout << "是否提交:";
        cin >> submit;
        if (submit == "是")
        {
            is_submits = true;
        }
        else
        {
            is_submits = false;
        }
        cout << "是否评定:";
        cin >> judge;
        if (judge == "是")
        {
            is_judges = true;
        }
        else
        {
            is_judges = false;
        }
        cout << "课设成绩:";
        cin >> scores;
        student new_in = student("河南工业大学", college_names, department_names, class_names, student_names, student_numbers, subject_names, student_teachers, is_submits, is_judges, scores);
        students.push_back(new_in);
        cout << "添加成功！" << endl;
        return new_in;
    }
    cout << "未查询到相关学生信息！" << endl;
    system("pause");
    student studentx;
    return studentx;
}
teacher manage_teacher_info(vector<student> &students, vector<teacher> &teachers, vector<subject> &subjects, char &choice)
{
    char choose = show_find_way();
    choice = choose;
    if (choose == '1')
    {
        cout << "按照院系班级查询" << endl;
        string find_college = show_all_teacher_college(teachers);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_department = show_all_teacher_department(teachers, find_college);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_teacher = show_all_teacher(teachers, find_department);
        system("cls");
        return (find_this_teacher(teachers, find_department, find_teacher));
    }
    else if (choose == '2')
    {
        cout << "手动查询" << endl;
        string college_names, department_names, class_names, teacher_names;
        cout << "学院名称:";
        cin >> college_names;
        cout << "专业名称:";
        cin >> department_names;
        cout << "教师名称:";
        cin >> teacher_names;
        /*for (auto &teacherx : teachers)
        {
            if ((teacherx.compare_department(department_names) == true) && (teacherx.compare_teacher(teacher_names) == true))
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
                cout << "是否全部评定:";
                return teacherx;
            }
        }*/
        system("cls");
        return (find_this_teacher(teachers, department_names, teacher_names));
    }
    else if (choose == '3')
    {

        string college_names, department_names, class_names, teacher_names, teacher_numbers, teacher_passwords, include_classs, include_subjects;
        vector<string> include_class;
        vector<string> include_subject;
        cout << "新增教师" << endl;
        cout << "学院:";
        cin >> college_names;
        cout << "专业:";
        cin >> department_names;
        cout << "教师姓名:";
        cin >> teacher_names;
        cout << "手机号(账号):";
        cin >> teacher_numbers;
        cout << "密码:";
        cin >> teacher_passwords;
        cout << "负责班级:";
        cin.clear();
        cin.sync();
        getline(cin, include_classs);
        cout << "负责课设:";
        cin.clear();
        cin.sync();
        getline(cin, include_subjects);
        teacher new_in = teacher("河南工业大学", college_names, department_names, teacher_names, teacher_numbers, teacher_passwords);
        string s_medium;
        istringstream medium(include_classs);
        cin.clear();
        cin.sync();
        while (getline(medium, s_medium, ' '))
        {
            new_in.teacher_class.push_back(s_medium);
        }
        istringstream medium2(include_subjects);
        while (getline(medium2, s_medium, ' '))
        {
            new_in.teacher_subject.push_back(s_medium);
        }
        teachers.push_back(new_in);
        cout << "添加成功！" << endl;
        return new_in;
    }
    cout << "未查询到相关教师信息！" << endl;
    system("pause");
    teacher teacherx;
    return teacherx;
}
subject manage_subject_info(vector<student> &students, vector<teacher> &teachers, vector<subject> &subjects, char &choice)
{
    char choose = show_find_way();
    choice = choose;
    if (choose == '1')
    {
        cout << "按照院系班级查询" << endl;
        string find_college = show_all_subject_college(subjects);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_department = show_all_subject_department(subjects, find_college);
        system("cls");
        cout << "按照院系班级查询" << endl;
        string find_subject = show_all_subject(subjects, find_department);
        system("cls");
        return (find_this_subject(subjects, find_department, find_subject));
    }
    else if (choose == '2')
    {
        cout << "手动查询" << endl;
        string college_names, department_names, class_names, subject_names;
        cout << "学院名称:";
        cin >> college_names;
        cout << "专业名称:";
        cin >> department_names;
        cout << "课设名称:";
        cin >> subject_names;
        /*for (auto &subjectx : subjects)
        {
            if ((subjectx.compare_department(department_names) == true) && (subjectx.compare_subject(subject_names) == true))
            {
                cout << "学校:" << subjectx.school_name << endl;
                cout << "学院:" << subjectx.college_name << endl;
                cout << "专业:" << subjectx.department_name << endl;
                cout << "课设名称:" << subjectx.subject_name << endl;
                cout << "指导老师:" << subjectx.subject_teacher << endl;
                cout << "包含班级:" << endl;
                for (auto t_class : subjectx.subject_class)
                {
                    cout << "         " << t_class << endl;
                }
                return subjectx;
            }
        }*/
        system("cls");
        return (find_this_subject(subjects, department_names, subject_names));
    }
    else if (choose == '3')
    {

        string college_names, department_names, class_names, subject_names, teacher_names, include_class;
        vector<string> include_classs;
        cout << "新增课设" << endl;
        cout << "学院:";
        cin >> college_names;
        cout << "专业:";
        cin >> department_names;
        cout << "课设名称:";
        cin >> subject_names;
        cout << "指导老师:";
        cin >> teacher_names;
        subject new_in = subject("河南工业大学", college_names, department_names, subject_names, teacher_names);
        cout << "包含班级:";
        cin.clear();
        cin.sync();
        getline(cin, include_class);
        string s_medium;
        istringstream medium(include_class);
        while (getline(medium, s_medium, ' '))
        {
            new_in.subject_class.push_back(s_medium);
        }
        cout << "添加成功！" << endl;
        subjects.push_back(new_in);
        return new_in;
    }
    cout << "未查询到相关课设信息！" << endl;
    system("pause");
    subject subjectx;
    return subjectx;
}
char show_find_way(void)
{
    while (true)
    {
        system("cls");
        cout << "管理员-查找方式" << endl;
        cout << "1.按照院系班级查询" << endl;
        cout << "2.手动输入查询" << endl;
        cout << "3.添加信息" << endl;
        char choose = getch();
        if (choose != '1' && choose != '2' && choose != '3')
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
string show_all_college(vector<student> students, vector<teacher> teachers, vector<subject> subjects)
{
    cout << "河南工业大学" << endl;
    int count = 1;
    vector<string> comp_college;
    comp_college.push_back("none");
    for (auto studentx : students)
    {
        for (auto beg = comp_college.begin(), ending = comp_college.end(); beg != ending; beg++)
        {
            if (studentx.compare_college(*beg) == true)
            {
                goto reagin;
            }
        }
        cout << count << '.' << studentx.college_name << endl;
        comp_college.push_back(studentx.college_name);
        count++;
    reagin:;
    }
    string find;
    cout << "请输入你要查找的学院:";
    cin >> find;
    return find;
}
string show_all_department(vector<student> students, vector<teacher> teachers, vector<subject> subjects, string find_college)
{
    cout << find_college << endl;
    int count = 1;
    vector<string> comp_department;
    comp_department.push_back("none");
    for (auto studentx : students)
    {
        for (auto beg = comp_department.begin(), ending = comp_department.end(); beg != ending; beg++)
        {
            if (studentx.compare_department(*beg) == true)
            {
                goto reagin;
            }
        }
        if (studentx.compare_college(find_college) == true)
        {
            cout << count << '.' << studentx.department_name << endl;
            comp_department.push_back(studentx.department_name);
            count++;
        }
    reagin:;
    }
    string find;
    cout << "请输入你要查找的专业:";
    cin >> find;
    return find;
}
string show_all_class(vector<student> students, string find_department)
{
    cout << find_department << endl;
    int count = 1;
    vector<string> comp_class;
    comp_class.push_back("none");
    for (auto studentx : students)
    {
        for (auto beg = comp_class.begin(), ending = comp_class.end(); beg != ending; beg++)
        {
            if (studentx.compare_class(*beg) == true)
            {
                goto reagin;
            }
        }
        if (studentx.compare_department(find_department) == true)
        {
            cout << count << '.' << studentx.class_name << endl;
            comp_class.push_back(studentx.class_name);
            count++;
        }
    reagin:;
    }
    string find;
    cout << "请输入你要查找的班级:";
    cin >> find;
    return find;
}
string show_all_student(vector<student> students, string find_class)
{
    cout << find_class << endl;
    int count = 1;
    vector<string> comp_student;
    comp_student.push_back("none");
    for (auto studentx : students)
    {
        for (auto beg = comp_student.begin(), ending = comp_student.end(); beg != ending; beg++)
        {
            if (studentx.compare_student(*beg) == true)
            {
                goto reagin;
            }
        }
        if (studentx.compare_class(find_class) == true)
        {
            cout << count << '.' << studentx.student_name << endl;
            comp_student.push_back(studentx.student_name);
            count++;
        }
    reagin:;
    }
    string find;
    cout << "请输入你要查找的学生:";
    cin >> find;
    return find;
}
string show_all_subject(vector<subject> subjects, string find_department)
{
    cout << find_department << endl;
    int count = 1;
    vector<string> comp_subject;
    comp_subject.push_back("none");
    for (auto subjectx : subjects)
    {
        for (auto beg = comp_subject.begin(), ending = comp_subject.end(); beg != ending; beg++)
        {
            if (subjectx.compare_subject(*beg) == true)
            {
                goto reagin;
            }
        }
        if (subjectx.compare_department(find_department) == true)
        {
            cout << count << '.' << subjectx.subject_name << endl;
            comp_subject.push_back(subjectx.subject_name);
            count++;
        }
    reagin:;
    }
    string find;
    cout << "请输入你要查找的课设名称:";
    cin >> find;
    return find;
}
student &find_this_student(vector<student> &students, string find_student, string find_class)
{
    cout << find_student << endl;
    auto it = students.begin();
    for (auto &studentx : students)
    {
        if ((studentx.compare_class(find_class) == true) && (studentx.compare_student(find_student) == true))
        {
            cout << "学校:" << studentx.school_name << endl;
            cout << "学院:" << studentx.college_name << endl;
            cout << "专业:" << studentx.department_name << endl;
            cout << "班级:" << studentx.class_name << endl;
            cout << "姓名:" << studentx.student_name << endl;
            cout << "学号:" << studentx.student_number << endl;
            cout << "课设名称:" << studentx.student_subject << endl;
            cout << "指导老师:" << studentx.student_teacher << endl;
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
            cout << "按q修改学生信息,按x删除学生，enter键返回菜单" << endl;
            char ch = getch();
            if (ch == 'q')
            {
                system("cls");
                change_stu_info(studentx);
            }
            else if (ch == 'x')
            {
                system("cls");
                delete_this_student(it, students);
                break;
            }
        }
        it++;
    }
    static student studentx;
    return studentx;
}
teacher &find_this_teacher(vector<teacher> &teachers, string find_department, string find_teacher)
{
    auto it = teachers.begin();
    cout << find_teacher << endl;
    for (auto &teacherx : teachers)
    {
        if (teacherx.compare_department(find_department) && teacherx.compare_teacher(find_teacher))
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
            cout << "按q修改教师信息,按x删除教师,enter键返回菜单" << endl;
            char ch = getch();
            if (ch == 'q')
            {
                system("cls");
                change_teacher_info(teacherx);
            }
            else if (ch == 'x')
            {
                system("cls");
                delete_this_teacher(it, teachers);
                break;
            }

            it++;
        }
    }
    static teacher teacherss;
    return teacherss;
}
string show_all_teacher(vector<teacher> teachers, string find_department)
{
    cout << find_department << endl;
    int count = 1;
    vector<string> comp_teacher;
    comp_teacher.push_back("none");
    for (auto teacherx : teachers)
    {
        for (auto beg = comp_teacher.begin(), ending = comp_teacher.end(); beg != ending; beg++)
        {
            if (teacherx.compare_teacher(*beg) == true)
            {
                goto reagin;
            }
        }
        if (teacherx.compare_department(find_department) == true)
        {
            cout << count << '.' << teacherx.teacher_name << endl;
            comp_teacher.push_back(teacherx.teacher_name);
            count++;
        }
    reagin:;
    }
    string find;
    cout << "请输入你要查找的教师:";
    cin >> find;
    return find;
}
subject &find_this_subject(vector<subject> &subjects, string find_department, string find_subject)
{
    auto it = subjects.begin();
    cout << find_subject << endl;
    for (auto &subjectx : subjects)
    {
        if ((subjectx.compare_department(find_department) == true) && (subjectx.compare_subject(find_subject) == true))
        {
            cout << "学校:" << subjectx.school_name << endl;
            cout << "学院:" << subjectx.college_name << endl;
            cout << "专业:" << subjectx.department_name << endl;
            cout << "课设名称:" << subjectx.subject_name << endl;
            cout << "指导老师:" << subjectx.subject_teacher << endl;
            cout << "包含班级:" << endl;
            for (auto t_class : subjectx.subject_class)
            {
                cout << "         " << t_class << endl;
            }
            cout << "按q修改课设信息,按x删除课设,enter键返回菜单" << endl;
            char ch = getch();
            if (ch == 'q')
            {
                system("cls");
                change_subject_info(subjectx);
            }
            else if (ch == 'x')
            {
                system("cls");
                delete_this_subject(it, subjects);
                break;
            }
        }
        it++;
    }
    static subject subjectx;
    return subjectx;
}
string show_all_teacher_college(vector<teacher> teachers)
{
    cout << "河南工业大学" << endl;
    int count = 1;
    vector<string> comp_college;
    comp_college.push_back("none");
    for (auto teacherx : teachers)
    {
        for (auto beg = comp_college.begin(), ending = comp_college.end(); beg != ending; beg++)
        {
            if (teacherx.compare_college(*beg) == true)
            {
                goto reagin;
            }
        }
        cout << count << '.' << teacherx.college_name << endl;
        comp_college.push_back(teacherx.college_name);
        count++;
    reagin:;
    }
    string find;
    cout << "请输入你要查找的学院:";
    cin >> find;
    return find;
}
string show_all_teacher_department(vector<teacher> teachers, string find_college)
{
    cout << find_college << endl;
    int count = 1;
    vector<string> comp_department;
    comp_department.push_back("none");
    for (auto teacherx : teachers)
    {
        for (auto beg = comp_department.begin(), ending = comp_department.end(); beg != ending; beg++)
        {
            if (teacherx.compare_department(*beg) == true)
            {
                goto reagin;
            }
        }
        if (teacherx.compare_college(find_college) == true)
        {
            cout << count << '.' << teacherx.department_name << endl;
            comp_department.push_back(teacherx.department_name);
            count++;
        }
    reagin:;
    }
    string find;
    cout << "请输入你要查找的专业:";
    cin >> find;
    return find;
}
string show_all_subject_college(vector<subject> subjects)
{
    cout << "河南工业大学" << endl;
    int count = 1;
    vector<string> comp_college;
    comp_college.push_back("none");
    for (auto subjectx : subjects)
    {
        for (auto beg = comp_college.begin(), ending = comp_college.end(); beg != ending; beg++)
        {
            if (subjectx.compare_college(*beg) == true)
            {
                goto reagin;
            }
        }
        cout << count << '.' << subjectx.college_name << endl;
        comp_college.push_back(subjectx.college_name);
        count++;
    reagin:;
    }
    string find;
    cout << "请输入你要查找的学院:";
    cin >> find;
    return find;
}
string show_all_subject_department(vector<subject> subjects, string find_college)
{
    cout << find_college << endl;
    int count = 1;
    vector<string> comp_department;
    comp_department.push_back("none");
    for (auto subjectx : subjects)
    {
        for (auto beg = comp_department.begin(), ending = comp_department.end(); beg != ending; beg++)
        {
            if (subjectx.compare_department(*beg) == true)
            {
                goto reagin;
            }
        }
        if (subjectx.compare_college(find_college) == true)
        {
            cout << count << '.' << subjectx.department_name << endl;
            comp_department.push_back(subjectx.department_name);
            count++;
        }
    reagin:;
    }
    string find;
    cout << "请输入你要查找的专业:";
    cin >> find;
    return find;
}
void change_stu_info(student &data)
{
    cout << "1.学院\n2.专业\n3.班级\n4.姓名\n5.学号\n6.课设名称\n7.指导老师\n8.是否提交\n9.是否评定\n0.成绩 " << endl;
    cout << "请输入你要修改的选项:";
    cin.clear();
    cin.sync();
    char ch = getche();
    cout << "\n";
    cin.clear();
    cin.sync();
    if (ch < '0' || ch > '9')
    {
        cout << "输入无效!" << endl;
        system("pause");
        return;
    }
    else
    {
        string change;
        string yes("是");
        string no("否");
        cin.clear();
        cin.sync();
        switch (ch)
        {
        case '1':
            cout << "学院:";
            cin >> change;
            data.college_name = change;
            break;
        case '2':
            cout << "专业:";
            cin >> change;
            data.department_name = change;
            break;
        case '3':
            cout << "班级:";
            cin >> change;
            data.class_name = change;
            break;
        case '4':
            cout << "姓名:";
            cin >> change;
            data.student_name = change;
            break;
        case '5':
            cout << "学号:";
            cin >> change;
            data.student_number = change;
            break;
        case '6':
            cout << "课设名称:";
            cin >> change;
            data.student_subject = change;
            break;
        case '7':
            cout << "指导老师:";
            cin >> change;
            data.student_teacher = change;
            break;
        case '8':
            cout << "是否提交:";
            cin >> change;
            if (change == yes)
            {
                data.is_submitted = true;
            }
            else
            {
                data.is_submitted = false;
            }
            break;
        case '9':
            cout << "是否评定:";
            cin >> change;
            if (change == yes)
            {
                data.is_judged = true;
            }
            else
            {
                data.is_judged = false;
            }
            break;
        case '0':
            cout << "成绩:";
            cin >> change;
            int scores = stoi(change);
            data.score = scores;
            break;
        }
        cout << "修改成功!" << endl;
    }
}
void change_teacher_info(teacher &data)
{
    cout << "1.学院\n2.专业\n3.姓名\n4.手机号(账号)\n5.密码\n6.添加负责班级\n7.添加负责课设\n8.删除全部负责班级\n9.删除全部负责课设" << endl;
    cout << "(tip:若要修改负责班级或课设，请先删除全部班级或课设再重新添加)" << endl;
    cout << "请输入你要修改的选项:";
    cin.clear();
    cin.sync();
    char ch = getche();
    cout << "\n";
    cin.clear();
    cin.sync();
    if (ch < '1' || ch > '9')
    {
        cout << "输入无效!" << endl;
        system("pause");
        return;
    }
    else
    {

        string single_class, single_subject;
        vector<string> add_thing_1, add_thing_2;
        string change;
        string change_2;
        switch (ch)
        {
        case '1':
            cout << "学院:";
            cin >> change;
            data.college_name = change;
            break;
        case '2':
            cout << "专业:";
            cin >> change;
            data.department_name = change;
            break;
        case '3':
            cout << "姓名:";
            cin >> change;
            data.teacher_name = change;
            cout << "请同步修改课设指导老师" << endl;
            break;
        case '4':
            cout << "手机号(账号):";
            cin >> change;
            data.teacher_number = change;
            break;
        case '5':
            cout << "密码:";
            cin >> change;
            data.teacher_password = change;
            break;
        case '6':
        add_class:
            cout << "负责班级:";
            getline(cin, change);
            static istringstream iss(change);
            while (getline(iss, single_class, ' '))
            {
                add_thing_1.push_back(single_class);
            }
            data.add_teacher_class(add_thing_1);
            cout << "请同步修改班级学生对应指导老师" << endl;
            break;
        case '7':
        add_sub:
            cout << "负责课设:";
            getline(cin, change_2);
            static istringstream iss_2(change_2);
            while (getline(iss_2, single_subject, ' '))
            {
                add_thing_2.push_back(single_subject);
            }
            data.add_teacher_class(add_thing_2);
            cout << "请同步修改课设指导老师" << endl;
            break;
        case '8':
            system("cls");
            cout << "warning:你是否要删除全部负责班级?\n1.确认\n2.取消" << endl;
            ch = getche();
            cin.clear();
            cin.sync();
            if (ch < '1' || ch > '2')
            {
                cout << "输入无效!" << endl;
                system("pause");
                return;
            }
            data.delete_all_class();
            cout << "已删除" << endl;
            system("pause");
            goto add_class;
            break;
        case '9':
            system("cls");
            cout << "warning:你是否要删除全部负责课设?\n1.确认\n2.取消" << endl;
            ch = getche();
            cin.clear();
            cin.sync();
            if (ch < '1' || ch > '2')
            {
                cout << "输入无效!" << endl;
                system("pause");
                return;
            }
            data.delete_all_subject();
            cout << "已删除" << endl;
            system("pause");
            goto add_sub;
            break;
        }
        cout << "修改成功!" << endl;
    }
}
void change_subject_info(subject &data)
{
    cout << "1.学院\n2.专业\n3.课设名称\n4.指导老师\n5.包含班级\n6.删除全部包含班级" << endl;
    cout << "(tip:若要修改包含班级，请先删除全部包含班级再重新添加)" << endl;
    cout << "请输入你要修改的选项:";
    cin.clear();
    cin.sync();
    char ch = getche();
    cout << "\n";
    cin.clear();
    cin.sync();
    if (ch < '1' || ch > '6')
    {
        cout << "输入无效!" << endl;
        system("pause");
        return;
    }
    else
    {

        string single_class;
        vector<string> add_thing_1;
        string change;
        switch (ch)
        {
        case '1':
            cout << "学院:";
            cin >> change;
            data.college_name = change;
            break;
        case '2':
            cout << "专业:";
            cin >> change;
            data.department_name = change;
            break;
        case '3':
            cout << "课设名称:";
            cin >> change;
            data.subject_name = change;
            cout << "请同步修改学生及教师课设名称" << endl;
            break;
        case '4':
            cout << "指导老师:";
            cin >> change;
            data.subject_teacher = change;
            cout << "请同步修改指导老师负责课设" << endl;
            break;
        case '5':
        add_class:
            cout << "包含班级:";
            getline(cin, change);
            static istringstream iss(change);
            while (getline(iss, single_class, ' '))
            {
                add_thing_1.push_back(single_class);
            }
            data.add_subject_class_s(add_thing_1);
            cout << "请同步修改班级学生课设名称" << endl;
            break;
        case '6':
            system("cls");
            cout << "warning:你是否要删除全部包含班级?\n1.确认\n2.取消" << endl;
            ch = getche();
            cin.clear();
            cin.sync();
            if (ch < '1' || ch > '2')
            {
                cout << "输入无效!" << endl;
                system("pause");
                return;
            }
            data.delete_all_class();
            cout << "已删除" << endl;
            system("pause");
            goto add_class;
            break;
        }
        cout << "修改成功!" << endl;
    }
}
void delete_this_student(vector<student>::iterator it, vector<student> &students)
{
    students.erase(it);
    cout << "已删除" << endl;
}
void delete_this_teacher(vector<teacher>::iterator it, vector<teacher> &teachers)
{
    teachers.erase(it);
    cout << "已删除" << endl;
}
void delete_this_subject(vector<subject>::iterator it, vector<subject> &subjects)
{
    subjects.erase(it);
    cout << "已删除" << endl;
}