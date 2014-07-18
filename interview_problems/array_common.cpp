#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// http://www.careercup.com/question?id=6261752413028352
int getSum(const vector<int> &a, const vector<int> &b){
  int max_sum = 0;
  unordered_set<int> a_hash;
  vector<int> common;
  common.reserve(max(a.size(), b.size()));
  // find the common elements.
  for(auto &i: a){
    a_hash.insert(i);
  }
  for(auto &i: b){
    if(a_hash.find(i) != a_hash.end()) common.push_back(i);
  }
    
  unsigned i=0, j=0;
  int sum_a =0, sum_b =0;
  bool done = false;
  for(auto it= common.begin(); !done; ++it){
    sum_a =0; sum_b =0;
    if (it == common.end()) { done=true; } // still need to proceed(just once) to add elements beyond the last common point.
    for(;i<a.size();++i){
      if (!done && a[i] == *it) break;
      sum_a += a[i];
    }
    for(;j<b.size();++j){
      if (!done && b[j] == *it) break;
      sum_b += b[j];
    }
    max_sum += std::max(sum_a, sum_b) + *it;
    ++i; ++j; // move past the common element
  }
  return max_sum;
}

int main() {

  vector<int> a = {3, 5, 7, 9, 20, 25, 30, 40, 55, 56, 57, 60, 62};
  vector<int> b = {1, 4, 7, 11, 14, 25, 44, 47, 55, 57, 100};
  cout << getSum(a,b)<< "\n";
  vector<int> ret;
  cout << "Done!\n";
  return 0;
}
