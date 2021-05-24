#include "root.h"
vector<root> add_root(void)
{
    vector<root> root_info;
    root_info.push_back(root("haut","haut"));
    return root_info;
}
vector<root> loading_root_info(void)
{
    vector<root> root_info = add_root();
    return root_info;
}
bool root::check_both(string account, string password)
{
    if (root_account == account && root_password == password)
    {
        return true;
    }
    else
        return false;
}