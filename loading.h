#ifndef LOADING
#define LOADING

#include <iostream>
#include <string>
#include <conio.h> //即时输入
#include <cstdlib> //清屏
#include "localtoprocess.h"
#include "root.h"
using namespace std;

void display_welcome_surface(void);
void display_loading_menu(void);
void display_main_menu(void);

char receive_identity_message(bool &identity);
vector<string> process_loading_message(char message);
vector<string> root_loading(vector<root> root_info);
vector<string> teacher_loading(vector<vector<vector<string>>> all_data);

vector<string> loading_init(bool &identity);

#endif