#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

// http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
// Largest subarray with equal number of 0s and 1s
pair<int,int> getLargestSubArr(const vector<int> &vec)
{
  pair<int, int> max;
  int max_dist = 0;
  int sum=0;
  map<int,int> hash;
  for (int i =0 ; i< vec.size(); ++i){
    if (vec[i])
      sum += 1;
    else
      sum-= 1;
    if (hash.find(sum) != hash.end()){
      if (i - hash[sum] + 1 > max_dist){
	max_dist = hash[sum] - i + 1;
	max.first = hash[sum] + 1;
	max.second = i;
      }
    }
    else{
      hash[sum] = i;
      //cout << "Insert:" << sum << "=>" << hash[sum] << "\n";
    }
    //cout << "i=" << i << "\tsum=" << sum << "\tmax_dist=" << max_dist << "\n";
  }
  if (sum == 0) // special case, whole array!
    return {0, vec.size()-1};
  return max;
}

int main() {

  vector<int> a = {0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0};
  vector<int> b = {0, 1, 1, 1, 0};
  vector<int> c = {1, 0}; // special case -- doesnt work.
  vector<int> d = {0, 0, 1};
  vector<int> e = {0};
  vector<int> f = {0, 0};
  vector<int> g = {0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1}; // whole array 0..15
  pair<int,int> ret;
  ret= getLargestSubArr(a);
  cout << ret.first<<":" << ret.second <<"\n";
  ret= getLargestSubArr(b);
  cout << ret.first<<":" << ret.second <<"\n";
  ret= getLargestSubArr(c);
  cout << ret.first<<":" << ret.second <<"\n";
  ret= getLargestSubArr(d);
  cout << ret.first<<":" << ret.second <<"\n";
  ret= getLargestSubArr(e);
  cout << ret.first<<":" << ret.second <<"\n";
  ret= getLargestSubArr(f);
  cout << ret.first<<":" << ret.second <<"\n";
  ret= getLargestSubArr(g);
  cout << ret.first<<":" << ret.second <<"\n";
  return 0;
}
