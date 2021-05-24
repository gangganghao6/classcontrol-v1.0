#include "main.h"

int main()
{
    bool identity_is_root;
    vector<vector<vector<string>>> all_data = localto_loadingall(); //初始化本地数据

    vector<string> user_message = loading_init(identity_is_root); //登录与传递身份信息

    vector<student> student_class = student_to_class(all_data);
    vector<teacher> teacher_class = teacher_to_class(all_data);
    vector<subject> subject_class = subject_to_class(all_data); //将本地数据建立对象

    if (identity_is_root)
    {
        vector<root> root_class = loading_root_info();
        root root_account = set_root_identity(user_message, root_class);
        while (true)
        {
            char choice;
            char choose = print_root_menu();
            CLS;
            switch (choose)
            {
            case '1':
            {
                manage_student_info(student_class, teacher_class, subject_class, choice);
            }
            break;
            case '2':
            {
                manage_teacher_info(student_class, teacher_class, subject_class, choice);
            }
            break;
            case '3':
            {
                manage_subject_info(student_class, teacher_class, subject_class, choice);
            }
            break;
            case '4':
                in_file_data(student_class);
                break;
            case 'n':
                CLS;
                cout << "输入无效！请重新输入！" << endl;
                PAUSE;
                break;
            }

            all_data = class_to_vector(student_class, teacher_class, subject_class);
            tolocal_loadingall(all_data);
            PAUSE;
        }
    }
    else
    {
        teacher teacher_account = set_teacher_identity(user_message, teacher_class);
        while (true)
        {
            char choose = print_teacher_menu();
            CLS;
            switch (choose)
            {
            case '1':
            {
                check_student_info(student_class, teacher_account);
            }
            break;
            case '2':
            {
                teacher_manage_student_info(student_class, teacher_account, subject_class);
            }
            break;
            case '3':
            {
                check_teacher_info(teacher_account);
            }
            break;
            case 'n':
                CLS;
                cout << "输入无效！请重新输入！" << endl;
                PAUSE;
                break;
            }

            all_data = class_to_vector(student_class, teacher_class, subject_class);
            tolocal_loadingall(all_data);
            PAUSE;
        }
    }
    PAUSE;
    CLS;
}

vector<string> singlevector_to_vector(string data)
{
    vector<string> all_data;
    string medium;
    istringstream string1(data);
    while (getline(string1, medium, '/'))
    {
        all_data.push_back(medium);
    }
    return all_data;
}
vector<student> &student_to_class(vector<vector<vector<string>>> all_data)
{
    string yes("是");
    string no("否");
    bool is_submitted;
    bool is_judged;
    double score;
    static vector<student> student_class;

    vector<vector<string>> student_data = all_data[0];

    for (auto data : student_data)
    {
        if (data[8] == yes)
        {
            is_submitted = true;
        }
        else if (data[8] == no)
        {
            is_submitted = false;
        }
        if (data[9] == yes)
        {
            is_judged = true;
        }
        else if (data[9] == no)
        {
            is_judged = false;
        }
        score = stod(data[10]);
        student_class.push_back(student(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], is_submitted, is_judged, score));
    }
    return student_class;
}
vector<teacher> &teacher_to_class(vector<vector<vector<string>>> all_data)
{
    int count = 0;
    static vector<teacher> teacher_class;
    vector<vector<string>> teacher_data = all_data[1];
    for (auto data : teacher_data)
    {
        teacher_class.push_back(teacher(data[0], data[1], data[2], data[3], data[4], data[5]));
        teacher_class[count].add_teacher_class(singlevector_to_vector(data[6]));
        teacher_class[count].add_teacher_subject(singlevector_to_vector(data[7]));
        ++count;
    }
    return teacher_class;
}
vector<subject> &subject_to_class(vector<vector<vector<string>>> all_data)
{
    int count = 0;
    static vector<subject> subject_class;
    vector<vector<string>> subject_data = all_data[2];
    for (auto data : subject_data)
    {
        subject_class.push_back(subject(data[0], data[1], data[2], data[3], data[4]));
        subject_class[count].add_subject_class(singlevector_to_vector(data[5]));
        ++count;
    }
    return subject_class;
}

string vector_to_singlevector(vector<string> data)
{
    string all_data;
    for (auto datas : data)
    {
        all_data = all_data + datas + '/';
    }
    return all_data;
}
vector<vector<vector<string>>> class_to_vector(vector<student> student_data, vector<teacher> teacher_data, vector<subject> subject_data)
{
    vector<vector<vector<string>>> all_data;

    string is_submitted;
    string is_judged;
    string score;
    vector<vector<string>> student_datas;
    vector<vector<string>> teacher_datas;
    vector<vector<string>> subject_datas;
    vector<string> medium;
    for (auto student_info : student_data)
    {
        medium = student_info.get_all_info();
        student_datas.push_back(medium);
    }
    for (auto teacher_info : teacher_data)
    {
        medium = teacher_info.get_all_info();
        teacher_datas.push_back(medium);
    }
    for (auto subject_info : subject_data)
    {
        medium = subject_info.get_all_info();
        subject_datas.push_back(medium);
    }
    all_data.push_back(student_datas);
    all_data.push_back(teacher_datas);
    all_data.push_back(subject_datas);
    return all_data;
}

root set_root_identity(vector<string> data, vector<root> root_data)
{
    string account = data[0];
    string password = data[1];
    root sth;
    for (auto info : root_data)
    {
        if (info.check_both(account, password) == true)
        {
            return info;
        }
    }
    return sth;
}
teacher set_teacher_identity(vector<string> data, vector<teacher> teacher_data)
{
    string account = data[0];
    string password = data[1];
    teacher sth;
    for (auto info : teacher_data)
    {
        if (info.check_both(account, password) == true)
        {
            return info;
        }
    }
    return sth;
}
