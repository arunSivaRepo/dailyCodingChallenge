#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// print longest sequence of same chars.
// http://www.careercup.com/question?id=6431075731505152
void printLongestRun(const string &str){
  if (str.length() <=1) {
    cout <<str<<"\n";
    return;
  }
  unsigned cur =0, next=0, max =0, max_start =0;
  while(str[cur]){
    while (next < str.length() && str[cur] == str[next]) ++next;
    unsigned end = (next != str.length()) ? next-1 : str.length()-1;
    if (end - cur + 1 > max){
      max = end - cur + 1;
      max_start = cur;
    }
    cur = next;
  }
  cout << str << "\t=>"<<str.substr(max_start, max) << "\n";
}

void testLongestRun(){
  string a("aaaabbbbcccccbbbbbbddddddddd"), b("a"), c("abcdef"),
    d (""), e("cdddaabcdef"), f("aabcdfe");
    
  printLongestRun(a);
  printLongestRun(b);
  printLongestRun(c);
  printLongestRun(d);
  printLongestRun(e);
  printLongestRun(f);
}

// http://www.careercup.com/question?id=5192571630387200
void printStrReplacementsRecursion(std::string str, unsigned start_idx){
    
  while (start_idx < str.length() && str[start_idx] != '?') ++start_idx;
  if (start_idx == str.length()) {
    cout << str << endl;
    return;
  }
  str[start_idx] = '0';
  printStrReplacementsRecursion(str, start_idx+1);
  str[start_idx] = '1';
  printStrReplacementsRecursion(str, start_idx+1);
}

void testStrRepl(){
  string a("abcd?sds??ddss?"), b("???");
  printStrReplacementsRecursion(a, 0);
  printStrReplacementsRecursion(b, 0);
}

void strRotate(string &inp, unsigned n){
  n = n % inp.length();
  //np = inp.substr(n) + inp.substr(0, n);
  // naive:
  for(int j=0; j<n; ++j)
    for (int i=0; i< inp.length()-1; ++i){
      char t=inp[i];
      inp[i] = inp[i+1%(inp.length())];
      inp[i+1%(inp.length())] = t;
    }
}

void testRotate(){
  string a("abcdef");
  string b("12");
  strRotate(a, 3);
  cout << a << "\n";
  strRotate(b, 3);
  cout << b << "\n";
}

int main() {
  testLongestRun();
  testStrRepl();
  testRotate();
  cout << "Done!\n";
  return 0;
}
