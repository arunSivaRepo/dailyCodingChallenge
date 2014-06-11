//http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

#include <iostream>
#include <vector>

using namespace std;

int getMaxSum(const vector<int> &vec)
{
  if (vec.empty()) return 0;
  if (vec.size() == 1 ) return vec[0]; // special case
  int incl=vec[0], excl=0;
   
  for (auto it = vec.begin(); it!= vec.end() ; ++it){
    int prev_incl = incl;
    incl = max(excl + *it , *it);
    if (it == vec.begin() + 1)
      excl = prev_incl;
    else
      excl = max(prev_incl, excl);
  }
    
  return max(incl, excl);
}

int main(int argc, const char * argv[])
{
  vector<int> vec1 = {3,2,5,10,7};
  vector<int> vec2 = {3,2,10,7};
  vector<int> vec3 = {0,2,50,0,1};
  vector<int> vec4 = {0,0,0};
  vector<int> vec5 = {0,0,6,0};
    
  // negative
  vector<int> vec6 = {-3,-2,-10,7};
  vector<int> vec7 = {-10,-2,-50,0,-1};
  vector<int> vec8 = {-2,-1,-10};
  vector<int> vec9 = {-1,-2,-6,-10};
  vector<int> vec10 = {-4,1,-2,6,10};
  vector<int> vec11 = {-4};
  vector<int> vec12 = {-2,-4};

  
  std::cout << getMaxSum(vec1) << "\n";
  std::cout << getMaxSum(vec2) << "\n";
  std::cout << getMaxSum(vec3) << "\n";
  std::cout << getMaxSum(vec4) << "\n";
  std::cout << getMaxSum(vec5) << "\n";
    
  std::cout << "Negative arrays\n";
  std::cout << getMaxSum(vec6) << "\n";
  std::cout << getMaxSum(vec7) << "\n";
  std::cout << getMaxSum(vec8) << "\n";
  std::cout << getMaxSum(vec9) << "\n";
  std::cout << getMaxSum(vec10) << "\n";
  std::cout << getMaxSum(vec11) << "\n";
  std::cout << getMaxSum(vec12) << "\n";

  return 0;
}
