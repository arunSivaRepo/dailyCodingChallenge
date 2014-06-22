#include <iostream>
#include <vector>

using namespace std;

// Elements of programming. Problem #6.3 Robot capacity problem.
int getCapacity(const vector<int> &heights)
{
  int max_capacity =0;
  int cur_capacity = 0, i= static_cast<int> (heights.size()-1);
  while (i>=0 && heights[i] <0 ) --i;
    
  for (; i>=0 ; --i){
    cur_capacity += heights[i];
    if (cur_capacity > max_capacity) max_capacity = cur_capacity;
  }
    
  return max_capacity;
}

int main(int argc, const char * argv[])
{

  vector<int> vec1 = {1,1,1,1,1,1};
  vector<int> vec2 = {1,-1,1,-1,-1,1};
  vector<int> vec3 = {1,-19,0,10,1,0};
  vector<int> vec4 = {4,-7,-1,10,12,-21};
  vector<int> vec5 = {-4,-7,-1,-10,12,-21};
  vector<int> vec6 = {-4,-7,-1,-10,-12,-21};
  vector<int> vec7 = {-4,4,-1,1,-12,12};
  vector<int> vec8 = {4,-4,1,-1,12,-12};

  cout << getCapacity(vec1) << "\n";
  cout << getCapacity(vec2) << "\n";
  cout << getCapacity(vec3) << "\n";
  cout << getCapacity(vec4) << "\n";
  cout << getCapacity(vec5) << "\n";
  cout << getCapacity(vec6) << "\n";
  cout << getCapacity(vec7) << "\n";
  cout << getCapacity(vec8) << "\n";
    
  std::cout << "Done\n";
  return 0;
}

