#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
// http://www.geeksforgeeks.org/find-all-possible-interpretations/
void recurse(int arr[], int rem, string s) {
  if (!rem) { cout << s <<"\n"; return;}
  int d = arr[0];
  string one_s = s;
  one_s += ('a'-1 + d);
  recurse(arr+1, rem-1, one_s);
  if (rem >=2) {
    d = arr[0]*10 + arr[1];
    if (d <=26) {
      string two_s= s;
      two_s += ('a'-1 + d);
      recurse(arr+2, rem-2, two_s);
    }
  }
}

int main() {
  int arr[] = {1,1,2,3,1};
  string s;
  recurse(arr,sizeof(arr)/sizeof(int),s);
  return 0;
}
