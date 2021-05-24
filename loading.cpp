#include "loading.h"
using namespace std;

string star = "************************************************************";

void display_welcome_surface(void)
{
    cout << star << "\n"
         << endl;
    cout << "                欢迎进入课程设计管理系统\n"
         << endl;
    cout << star << endl;
    system("pause");
}
void display_loading_menu()
{
    cout << "登录" << endl;
    cout << "1.管理员登录\n2.教师登录" << endl;
}
char receive_identity_message(bool &identity)
{
    while (1)
    {
        system("cls");
        display_loading_menu();
        char have = getch();
        if (have == '1')
        {
            identity = true;
            return '1';
        }
        else if (have == '2')
        {
            identity = false;
            return '2';
        }
        else
        {
            system("cls");
            cout << "输入无效，请重新输入!\a" << endl;
            system("pause");
        }
    }
}
vector<string> process_loading_message(char message)
{
    vector<string> messages;
    vector<vector<vector<string>>> all_data = localto_loadingall();
    if (message == '1')
    {
        vector<root> root_info = loading_root_info();
        messages=root_loading(root_info);
    }
    else
    {
        messages=teacher_loading(all_data);
    }
    return messages;
}
vector<string> root_loading(vector<root> root_info)
{
    while (true)
    {
        system("cls");
        cout << "管理员登录" << endl;
        cout << "账号:";
        string account, password;
        cin >> account;
        cout << "密码:";
        cin >> password;
        for (auto check : root_info)
        {
            if (check.check_both(account, password) == true)
            {
                cout << "登陆成功！" << endl;
                vector<string> message;
                message.push_back(account);
                message.push_back(password);
                return message;
            }
        }
        cout << "账号或密码错误，请重新输入！" << endl;
        system("pause");
    }
}
vector<string> teacher_loading(vector<vector<vector<string>>> all_data)
{
    vector<vector<string>> teacher_data = all_data[1];
    while (true)
    {
        system("cls");
        cout << "教师登录" << endl;
        cout << "账号:";
        string account, password;
        cin >> account;
        cout << "密码:";
        cin >> password;
        for (auto check : teacher_data)
        {
            if (check[4] == account && check[5] == password)
            {
                cout << "登陆成功！" << endl;
                vector<string> message;
                message.push_back(account);
                message.push_back(password);
                return message;
            }
        }
        cout << "账号或密码错误，请重新输入！" << endl;
        system("pause");
    }
}

vector<string> loading_init(bool &identity)
{
    display_welcome_surface();
    char message = receive_identity_message(identity);
    vector<string> messages = process_loading_message(message);
    return messages;
}