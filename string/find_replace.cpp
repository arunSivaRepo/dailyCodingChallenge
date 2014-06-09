#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isSubstr(const std::string &str, const std::string &findStr, size_t startPos=0) 
{
  if (str.length() - startPos < findStr.length()) return false;
  std::string::const_iterator i=str.begin() + startPos, j=findStr.begin(); 
  for(; i!= str.end() && j!=findStr.end() ; ++i, ++j ) {
    if (*i != *j) return false;
  }
  return (j==findStr.end());
}

// find and replace naive
std::string findAndReplace(const std::string &str, const std::string &findStr, const std::string &replaceStr) 
{
  std::string repl;
  size_t strLen = str.length(), findStrLen = findStr.length(), replaceStrLen = replaceStr.length();

  for (size_t i=0; i!= strLen; ) {
    if (isSubstr(str, findStr, i)) {
      for (size_t j=0 ; j!= replaceStrLen ; ++j) {
        repl += replaceStr[j];
      }
      i += findStrLen;
    }
    else {
      repl += str[i++];
    }
  }
  return repl;
}

int main() {
  std::cout << findAndReplace("my1ab2","1","one") << "\n";
  std::cout << findAndReplace("my1ab2","ab2","two") << "\n";
  std::cout << findAndReplace("my1ab2","my1ab2","") << "\n";
  std::cout << findAndReplace("my1ab2","my","MY") << "\n";
  std::cout << findAndReplace("my1myabmymymy2my","my","MY") << "\n";
  // overlapping
  std::cout << findAndReplace("my1myabmymymymy2my","mymymy","MY1") << "\n";
  return 0;
}
