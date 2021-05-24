#ifndef ROOT
#define ROOT

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class root
{
friend vector<root> add_root();
public:
    root() = default;
    root(string account, string password) : root_account(account), root_password(password) {}
    bool check_both(string account, string password);
private:
    string root_account;
    string root_password;
};

vector<root> add_root(void);
vector<root> loading_root_info(void);

#endif

