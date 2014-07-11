#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// A =1, AA= 27, BA = 53
int getExcelColId(const string &str){
  int ret=0;
  int pow = 1;
  for(auto it = str.begin(); it != str.end() ; ++it){
    ret += (*it - 'A' + 1) * pow;
    pow *= 26;
  }
    
  return ret;
}

int main(int argc, const char * argv[])
{
  cout<<getExcelColId("A") <<"\n";
  cout<<getExcelColId("AA") <<"\n";
  cout<<getExcelColId("Z") <<"\n";
  cout<<getExcelColId("ABA") <<"\n";
  std::cout << "Done";
  return 0;
}

