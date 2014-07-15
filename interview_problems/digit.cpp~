#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int getSecondLargest(const vector<int> &a){
  int max = INT_MIN, max2 = INT_MIN +1;
    
  for (int i=0; i< a.size(); ++i){
    if (a[i] > max2) {
      if (a[i] > max) { max2 = max; max = a[i];}
      else max2 = a[i];
    }
  }
    
  return max2;
}

// Given a number, find the just greater number than the given number containing the same digits as the given number. Write code for this.
int findGreater(int num)
{
  int ret =0;
  vector<int> vec, vec2;
  while(num){
    vec.push_back(num%10);
    num /= 10;
  }
  for(int i =0 ; i < vec.size() ; ++i) {
    for (int j =i+1; j<vec.size(); ++j){
      if (vec[j] < vec[i]) {
	swap(vec[j], vec[i]);
	for (int k =vec.size() -1; k>=j; --k) { ret = ret*10 + vec[k]; }
	sort(vec.begin(), vec.begin() + j -1);
	for (int k = 0; k < j; ++k) { ret = ret*10 + vec[k]; }
	return ret;
      }
    }
  }
  return ret;
}

int main() {
  cout << findGreater(576823)<<"\n";
  cout << findGreater(7120986)<<"\n";
  cout << findGreater(38276)<<"\n";

  cout << "-----------\n";
  vector<int> a = {11, 32, 8, 19, 10, 15, 19, -20, 215, 70};
  vector<int> b = {311, 7, 130, 99};
  vector<int> c = {130, 99};
  vector<int> d = {99};
  cout <<  getSecondLargest(a) << "\n";
  cout <<  getSecondLargest(b) << "\n";
  cout <<  getSecondLargest(c) << "\n";
  cout <<  getSecondLargest(d) << "\n";
  return 0;
}
