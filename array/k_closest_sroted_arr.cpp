#include <iostream>
#include <vector>

using namespace std;

// K closest elements in a sorted array
// http://www.geeksforgeeks.org/find-k-closest-elements-given-value/
template <class T>
int binarySearch(const vector<T> &vec, const T &val)
{
  int ret = -1;
  int low=0, high=static_cast<int>(vec.size())-1, mid = 0;
    
  while(low <= high){
    mid = (low+high)/2;
    if (vec[mid] == val) return mid;
    if (val > vec[mid]) low=mid +1;
    else high= mid-1;
  }
    
  return ret;
}

template <class T>
vector<T> findKclosestSorted(const vector<T> &vec, size_t k, const T &val)
{
  vector<int> ret;
  if (k > vec.size()) return ret;
  int pos = binarySearch(vec, val);
  if (pos == -1) return ret;
    
  ret.resize(k);
  int left=pos-1, right = pos+1;
  for (unsigned i=0; i<k ;++i){
    if (left>=0) {
      if(right>=vec.size() ||  abs(vec[pos] -  vec[left]) <= abs(vec[right] - vec[pos])){
	ret[i] = vec[left];
	--left;
	continue;
      }
    }
    if (right < vec.size()) {
      if(left < 0 ||  abs(vec[pos] -  vec[left]) >= abs(vec[right] - vec[pos])){
	ret[i] = vec[right];
	right++;
      }
    }
  }
    
  return ret;
}

template <class T>
void test(const vector<T> &vec, size_t k, const T &val)
{
  vector<T> ret=findKclosestSorted<T>(vec, k , val);
  for (auto it=ret.begin(); it != ret.end(); ++it)
    cout << *it << "\t" ;
  cout << endl;
}

int main(int argc, const char * argv[])
{
  vector<int> vec1 = {0,2,3,5,8,10,11,12,15,16,20};
  test<int>(vec1, 3 , 10);
  vector<int> vec2 = {0,2,3,5,8,10,11,12,15,16,20};
  test<int>(vec2, 5 , 5);
  test<int>(vec2, 3 , 0);
  test<int>(vec2, 3 , 20);
  test<int>(vec2, 3 , 16);
  vector<int> vec3 = {-20,-9,-8,-5,-1,0,2,3,5,8,10,11,12,15,16,20};
  test<int>(vec3, 5 , 5);
  test<int>(vec3, 5 , -5);

  return 0;
}

