#include <iostream>
#include "student.h"
#include "teacher.h"
#include "classandgrade.h"
#include "loading.h"
#include "processtolocal.h"
#include "subject.h"
#include "rootmenu.h"
#include "teachermenu.h"
#include "in_file.h"
#include <vector>
//#include <iterator>
#include <conio.h> //即时输入
#include <cstdlib> //清屏
#include <fstream> //文件io
#include <sstream> //string io
#include <ctime>
#define CLS system("cls")
#define PAUSE system("pause")
using namespace std;

vector<string> singlevector_to_vector(string data);

vector<student> &student_to_class(vector<vector<vector<string>>> all_data);
vector<teacher> &teacher_to_class(vector<vector<vector<string>>> all_data);
vector<subject> &subject_to_class(vector<vector<vector<string>>> all_data);
//vector<classandgrade> &classandgrade_to_class(vector<vector<vector<string>>> all_data);

string vector_to_singlevector(vector<string> data);

root set_root_identity(vector<string> data, vector<root> root_data);
teacher set_teacher_identity(vector<string> data, vector<teacher> teacher_data);

vector<vector<vector<string>>> class_to_vector(vector<student> student_data, vector<teacher> teacher_data, vector<subject> subject_data);
