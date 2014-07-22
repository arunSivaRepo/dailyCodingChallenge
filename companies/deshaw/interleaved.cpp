#include <iostream>
#include <string>

using namespace std;

bool isInterleaved(const string &s1, const string &s2, const string &s3){

  unsigned s1idx=0, s2idx=0, s3idx=0;
  for (; s3idx <s3.size() ; ){
    unsigned cur_s3idx = s3idx, cur_s1idx=s1idx, cur_s2idx = s2idx;
    while (cur_s1idx < s1.size() && cur_s3idx <s3.size() && s3[cur_s3idx] == s1[cur_s1idx]){
      ++cur_s1idx; ++cur_s3idx;
    }
    unsigned s1len = cur_s3idx - s3idx ; //num of matches.
    cur_s3idx = s3idx;
    while (cur_s2idx < s2.size() && cur_s3idx <s3.size() && s3[cur_s3idx] == s2[cur_s2idx]){
      ++cur_s2idx; ++cur_s3idx;
    }
    unsigned s2len = cur_s3idx - s3idx ; //num of matches.

    if (!s1len && !s2len) return false;
 
    if (s1len > s2len) {
      s3idx += s1len;
      s1idx = cur_s1idx;
    }
    else{
      s3idx += s2len;
      s2idx = cur_s2idx;
    }

  }
  return (s1idx == s1.size() && s2idx == s2.size() && s3idx == s3.size());
}

int main(){
  string  s1("abcdef"), s2("1234567"), s3("a123b4cd56ef7");
  cout << isInterleaved(s1,s2,s3) << "\n";

  s1 = "aab";
  s2 = "aaab";
  s3 = "aaaaabb";
  cout << isInterleaved(s1,s2,s3) << "\n";

  s1 = "aa";
  s2 = "aaa";
  s3 = "aaaaa";
  cout << isInterleaved(s1,s2,s3) << "\n";

  s1 = "a1a";
  s2 = "aa1a";
  s3 = "aaa1a1a";
  string s4 = "aaa1aa1";
  cout << isInterleaved(s1,s2,s3) << "\n";
  cout << isInterleaved(s1,s2,s4) << "\n";

  return 0;

}
