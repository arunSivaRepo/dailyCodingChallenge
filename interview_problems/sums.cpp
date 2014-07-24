#include <iostream>
#include <vector>
#include <string>

using namespace std;
// http://www.careercup.com/question?id=5653595164770304

// prints duplicates too. eg: n=5 => 3,2 and 2,3
void getSum(int n, int sum_sofar, vector<int> &vec, unsigned pos){
  if (n == sum_sofar){
    for(int i=0; i<pos ;++i){ cout <<vec[i]<<"\t"; }
    cout << endl;
    return;
  }
    
  for (int i=1; i<=n ;++i){
    if (sum_sofar+i > n) break;
    vec[pos] = i;
    getSum(n, sum_sofar+i, vec, pos+1);
  }
}

int main() {
  vector<int> vec;
  vec.resize(5);
  getSum(5, 0, vec, 0);
  cout << "Done!\n";
  return 0;
}
