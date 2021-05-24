#ifndef INFILE
#define INFILE

#define UNICODE
#include <iostream>
#include <windows.h>
#include <Commdlg.h>
#include <string>
#include <vector>
#include "student.h"
#include "localtoprocess.h"

using namespace std;


string get_localfile_message(void);
string WCharToMByte(LPCWSTR lpcwszStr);
void in_file_data(vector<student> &data);
void add_local_stu(vector<vector<string>> data, vector<student> &students);
#endif