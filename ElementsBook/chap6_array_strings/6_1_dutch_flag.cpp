#include <iostream>
#include <vector>

using namespace std;

// Problem:
// sort array so that first we have all elements <arr[idx], followed
// by all elems=arr[idx] and then all elems>arr[idx]


void swap(vector<int> &vec, size_t i, size_t j)
{
  int temp = vec[i];
  vec[i] = vec[j];
  vec[j] = temp;
}

// counting method
// then exchange inplace
void naive(vector<int> &vec, size_t idx)
{
  unsigned num_smaller=0, num_equal=0, num_greater=0;
  int target = vec[idx];
  for (int i : vec){
    if (i > target) ++num_greater;
    else if (i == target) ++num_equal;
    else ++num_smaller;
  }
    
  unsigned less_idx=0, equal_idx=num_smaller, greater_idx=num_smaller + num_equal;
    
  while(1){
    while (less_idx < vec.size() && vec[less_idx] < target) ++less_idx;
    while (equal_idx < vec.size() && vec[equal_idx] == target) ++equal_idx;
    while (greater_idx < vec.size() && vec[greater_idx] > target) ++greater_idx;

    if (less_idx == num_smaller &&
	equal_idx == (num_smaller + num_equal) &&
	greater_idx == vec.size()){
      return;
    }
    if (less_idx < num_smaller) {
      if (vec[less_idx] == target) swap(vec, less_idx, equal_idx);
      else swap(vec, less_idx, greater_idx);
      continue;
    }
    // if we are this far, all elemets < target are in place.
    if (equal_idx < (num_smaller + num_equal)) {
      // since all elements < target are in place, swap with the element out of order on the
      // greater bucket.
      swap(vec, equal_idx, greater_idx);
    }
  }
}

void dutch(vector<int> &vec, size_t idx)
{

  // logic: http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
  size_t less_idx=0, greater_idx=vec.size()-1, equal_idx=0;
  int target = vec[idx];

  while(equal_idx <= greater_idx){
    while (less_idx < vec.size() && vec[less_idx] < target) ++less_idx;
    while (greater_idx > equal_idx && vec[greater_idx] > target) --greater_idx;
    if (equal_idx < less_idx) equal_idx = less_idx;
    if (vec[equal_idx] == target)  ++equal_idx;
    else if (vec[equal_idx] < target) { swap(vec,equal_idx, less_idx); ++less_idx; }
    else { swap(vec,equal_idx, greater_idx); --greater_idx; }
  }
}

void test(vector<int> &vec, size_t idx)
{
  //naive(vec, idx);
  dutch(vec, idx);
  for(int i : vec) cout << i << "\t" ;
  cout << endl;
}

int main() {
  vector<int> vec1 = {0,2,13,15,-8,-10,11,2,15,6,20};
  test(vec1, 3); //15
  // sorted
  vector<int> vec2 = {0,1,2,3,4,5,6,7,8};
  test(vec2, 3); //3
  // Reverse order
  // WARNING Bug: When run for naive() the output for vec3 looks correct, but hangs while returning. bug only in Xcode.
  vector<int> vec3 = {0,-1,-2,-3,-4,-5,-6,-7,-8};
  test(vec3, 3); //-3
  vector<int> vec4 = {10,9,8,7,6,5,4,3,2,1,0};
  test(vec4, 3);
  cout << "Done.\n";
  return 0;
}
