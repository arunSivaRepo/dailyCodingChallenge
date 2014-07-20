#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
// http://www.careercup.com/question?id=5652139279908864
// Weighted Random.

unsigned getIndexLower(const vector<float> &vec, float target){
    
  if (vec.size() <=1 )return vec.size();
  unsigned low =0, high= vec.size()-1;
  while(low < high){
    unsigned mid = (low+high)/2;
    if (vec[mid] <= target && (mid <high && vec[mid+1] > target)){
      return mid+1;
    }
    if (vec[mid] < target) { low = mid+1; }
    else { high = mid; }
  }
  return low;
}

template <class T>
T getWeightedRandom(const vector<T> &vec, const vector<float> &weights){
    
  srand(time(NULL));
  static bool init = false;
  static vector<float> cumulative_weights;
  if (!init){ // initialize cumulative weights just once.
    float tot=0;
    for (auto &i: weights){
      tot += i;
      cumulative_weights.push_back(tot);
      init = true;
    }
    cout << "Total = " << tot << "\n";
  }
    
  float rand_val = rand()%1000/1000.0;
  unsigned idx = getIndexLower(cumulative_weights, rand_val);
  cout << "RAND=" << rand_val<< "\tIDX = " << idx << "\n";
  return vec[idx];
}

using namespace std;
int main() {
  vector<char> inp = {'a', 'b', 'c', 'd'};
  vector<float> wts = {0.1, 0.2, 0.3, 0.4};
  cout << getWeightedRandom<char>(inp, wts) << "\n";
  cout << "Done!\n";
  return 0;
}
