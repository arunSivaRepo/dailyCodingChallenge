#include <vector>
#include <iostream>

using namespace std;
// http://www.geeksforgeeks.org/find-number-zeroes/

unsigned getNumZeroes(const vector<int> &vec){
  if (vec.empty()) return 0;
  if (!vec[0]) return vec.size(); // need this because we only find transition point 1->0 which would be absent in this case.
  unsigned num = 0;
  unsigned low = 0, high = vec.size() - 1 , target = vec.size() -1;
    
  while (low < high){
    unsigned mid = (low + high)/2;
    if (vec[mid]){
      if (!vec[mid+1]) { target = mid; break; }
      low = mid + 1;
    }
    else {
      high = mid;
    }
  }
  // vec[target] = 1 and vec[target+1] = 0 ;
  return vec.size() - target - 1;
}

int main(int argc, const char * argv[])
{
  vector<int> A = {1, 1, 1, 1, 1, 0, 0, 0, 0};
  vector<int> B = {0, 0, 0, 0};
  vector<int> C = {1, 1, 1, 1, 1, 1, 1, 1, 0};
  vector<int> D = {1, 1, 1, 1, 1};

  cout << getNumZeroes(A) << "\n";
  cout << getNumZeroes(B) << "\n";
  cout << getNumZeroes(C) << "\n";
  cout << getNumZeroes(D) << "\n";

  std::cout << "Done\n";
  return 0;
}

