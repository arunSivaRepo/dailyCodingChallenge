#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
// http://www.geeksforgeeks.org/count-possible-groups-size-2-3-sum-multiple-3/
unsigned getCombos(const vector<unsigned> &vec)
{
  vector<unsigned> mods = {0, 0, 0};
  for (auto &&i : vec){
    ++mods[i%3];
  }
  unsigned ret = mods[0] * mods[1] * mods[1]; // one from each group
  if (mods[0] >= 2){
    ret+= mods[0] * (mods[0] -1)/2; // 2 of 0 remainders
  }
  if (mods[0] >= 3){
    ret += (mods[0] * (mods[0] -1) * (mods[0] -2))/6; // 3 of 0 remainders
  }
  if (mods[1] >= 3){
    ret += (mods[1] * (mods[1] -1) * (mods[1] -2))/6; // 3 of 1 remainders
  }
  if (mods[2] >= 3){
    ret += (mods[2] * (mods[2] -1) * (mods[2] -2))/6; // 3 of 2 remainders
  }
  ret += mods[1] * mods[2]; // one from 1 remainder and one form 2 reaminder.
    
  return ret;
}

int main(int argc, const char * argv[])
{
  vector<unsigned> A = {3, 6, 7, 2, 9};
  std::cout << getCombos(A) << "\n";
  std::cout << "Done\n";
  return 0;
}

