#include <iostream>
#include <vector>
#include <string>

using namespace std;
// create interleaved strings

void createInterleavedHelper(const string &str1, const string &str2,
			     unsigned str1pos, unsigned str2pos, string &out, unsigned outpos){
  if (str1pos == str1.size() && str2pos == str2.size()){
    cout << out << "\n";
    return;
  }
    
  if (str1pos < str1.size()) {
    out[outpos] = str1[str1pos];
    createInterleavedHelper(str1, str2, str1pos +1, str2pos, out, outpos+1);
  }
  if(str2pos < str2.size()){
    out[outpos] = str2[str2pos];
    createInterleavedHelper(str1, str2, str1pos, str2pos +1, out, outpos+1);
  }
}

void createInterleaved(const string &str1, const string &str2){
  string out;
  out.resize(str1.size() + str2.size());
  createInterleavedHelper(str1, str2, 0, 0, out, 0);
}

int main() {
  string s1("abcd"), s2("1234") , out;
  createInterleaved(s1, s2);
  cout << "Done!\n";
  return 0;
}
