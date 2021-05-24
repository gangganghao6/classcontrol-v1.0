#ifndef PROCESSTOLOCAL
#define PROCESSTOLOCAL

#include<fstream>   //文件io
#include<vector>
#include<sstream>   //string io
#include<string>

using namespace std;

void tolocal_student_information(vector<vector<string>> student_vec_vec);
void tolocal_teacher_information(vector<vector<string>> teacher_vec_vec);
void tolocal_subject_information(vector<vector<string>> subject_vec_vec);
/*void tolocal_class_information(vector<vector<string>> classandgrade_vec_vec);*/

void tolocal_loadingall(vector<vector<vector<string>>> all_data);

#endif