#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
// http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/
pair<int, int> hasZeroSum(const vector<int> &vec){
  unordered_map<int, int> hash; // sum -> index ending.
  int sum = 0;
  for (unsigned i=0 ; i <vec.size() ; ++i){
    sum += vec[i];
    if (!sum){
      return {0, i};
    }
    if (hash.find(sum) != hash.end()){
      return {hash[sum], i};
    }
    hash[sum] = i;
  }
  return {-1, -1};
}

int main(int argc, const char * argv[])
{
  vector<int> A = {2, -3, 1, 6};
  pair<int, int> ret = hasZeroSum(A);
  cout << ret.first <<"\t" << ret.second << "\n";
  std::cout << "Done\n";
  return 0;
}

