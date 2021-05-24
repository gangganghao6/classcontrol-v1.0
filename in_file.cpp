#include "in_file.h"

string get_localfile_message(void)
{
    OPENFILENAME ofn;
    char szFile[300];
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = (LPWSTR)szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = L"All\0*.*\0CSV\0*.CSV\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if (GetOpenFileName(&ofn))
    {
        string str = WCharToMByte(ofn.lpstrFile);
        return str;
    }
    else
    {
        string str("null");
        return str;
    }
    return 0;
}
string WCharToMByte(LPCWSTR lpcwszStr)
{
    string str;
    DWORD dwMinSize = 0;
    LPSTR lpszStr = NULL;
    dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, NULL, 0, NULL, FALSE);
    if (0 == dwMinSize)
    {
        return FALSE;
    }
    lpszStr = new char[dwMinSize];
    WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, lpszStr, dwMinSize, NULL, FALSE);
    str = lpszStr;
    delete[] lpszStr;
    return str;
}
void in_file_data(vector<student> &data)
{
    cout << "warning:请确认导入文件格式与本程序数据存储结构相同!且导入文件不要出现程序已有数据!" << endl;
    cout << "程序数据结构:" << endl;
    cout << "*.csv:学校 学院 专业 班级 姓名 学号 课设名称 指导老师 是否提交 是否评定 成绩" << endl;
    system("pause");
    vector<vector<string>> add_stu;
    string location = get_localfile_message();
    if (location == "null")
    {
        return;
    }
    add_stu = infile_localto_student_information(location);
    add_local_stu(add_stu, data);
    cout << "导入成功!" << endl;
}
void add_local_stu(vector<vector<string>> student_data, vector<student> &students)
{
    string yes("是");
    string no("否");
    bool is_submitted;
    bool is_judged;
    double score;

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
        students.push_back(student(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], is_submitted, is_judged, score));
    }
}
