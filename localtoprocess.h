#ifndef LOCALTOPROCESS
#define LOCALTOPROCESS

#include <fstream> //文件io
#include <vector>
#include <sstream> //string io
#include <string>
#include "student.h"
#include "teacher.h"
#include "subject.h"
#include "classandgrade.h"

using namespace std;

vector<vector<string>> localto_student_information(void);
vector<vector<string>> localto_teacher_information(void);
vector<vector<string>> localto_subject_information(void);
/*vector<vector<string>> localto_class_information(void);*/

vector<vector<vector<string>>> localto_loadingall(void);

vector<vector<string>> infile_localto_student_information(string location);

#endif