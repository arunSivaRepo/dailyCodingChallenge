#include <vector>
#include <iostream>

using namespace std;
// http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
// O(n + m) time and O(1) space.
void printMaxSum(const vector<int> &A, const vector<int> &B){
    
  int i=0, j=0, sum1=0, sum2=0, sum=0;
    
  while ( i < A.size() && j < B.size()){
    if (i < A.size() && A[i] < B[j]) {
      sum1 += A[i++];
    }
    else if(j < B.size() && (i >= A.size() || A[i] > B[j]))  {
      sum2 += B[j++];
    }
    else if (A[i] == B[j]){
      sum += A[i] + max(sum1, sum2);
      sum1 = sum2 = 0;
      ++i; ++j;
    }
  }
    
  while (i < A.size()) sum1 += A[i++];
  while (j < B.size()) sum2 += B[j++];
  sum += max(sum1, sum2);
    
  cout << "Total sum:" << sum << "\n";
}

int main(int argc, const char * argv[])
{
  vector<int> A = {1, 7, 9, 11, 12, 13, 18};
  vector<int> B = {1, 2, 9, 15, 18, 19};
  printMaxSum(A,B);
  vector<int> ar1 = {2, 3, 7, 10, 12}, ar2 = {1, 5, 7, 8},
					 a1 = {2, 3, 7, 10, 12, 15, 30, 34, 50},
					   a2 = {1, 5, 7, 8, 10, 15, 16, 19, 50};
					   printMaxSum(ar1,ar2);
					   printMaxSum(a1,a2);
					   std::cout << "Done\n";
					   return 0;
}

