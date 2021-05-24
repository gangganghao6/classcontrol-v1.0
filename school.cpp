#include "school.h"

/*vector<string> school::creat_college(string add_colleges)
{
  include_college.push_back(add_colleges);
  return include_college;
}*/
string school::vector_to_singlevector(vector<string> data)
{
  string all_data;
  for (auto datas : data)
  {
    all_data = all_data + datas + "/";
  }
  return all_data;
}