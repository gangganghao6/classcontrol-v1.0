#ifndef SCHOOL
#define SCHOOL

#include <vector>
#include <string>
#include <sstream>
using namespace std;
class school
{
public:
    school() = default;
    school(string school_names) : school_name(school_names) {}
    //vector<string> creat_college(string add_colleges);
    string vector_to_singlevector(vector<string> data);

public:
    string school_name;

private:
    //vector<string> include_college;
};

#endif