#include <vector>
#include <iostream>

using namespace std;

// majority voting algorithm.
// get element which occurs >50% of time in O(n) time and O(1) space.
int getMajority(const vector<int> &A){
  unsigned counter = 0;
  int cur_elem;
  for (int i: A){
    if (!counter){
      ++counter;
      cur_elem = i;
    }
    else{
      (cur_elem == i) ? ++counter : --counter;
    }
  }
  counter = 0;
  for (int i: A){
    if (cur_elem == i) { ++counter;}
  }
  if (counter < A.size()/2) { cur_elem = -1; } // no majority
  return cur_elem;
}

// wiggle problem?
// form array so that a1 < a2 > a3 < a4 > a5 < a6 > a7 ....
void wiggleMe(vector<int> &A){
  // sort and swap alternate elements.
  sort(A.begin(), A.end());
  for (int i=1 ;i<A.size()-1; i+=2){
    swap(A[i], A[i+1]);
  }
    
  for (int i: A){
    cout << i << "\t";
  }
  cout << endl;
}

int max(int a, int b){
  return ((a >= b) ? a : b);
}

int min(int a, int b){
  return ((a <= b) ? a : b);
}

// find target in an almost sorted array.
// each element is atmost k position away from its actual position in a sorted array.
int getElem(const vector<int> &A, unsigned k, int target){
  int idx = -1;
    
  int low=0, high=A.size() -1, mid;
    
  while(low <= high){
    mid = (low + high)/2;
        
    for (int i = mid -k; i <= mid +k; ++i){
      if (i<0) continue;
      if (i >= A.size()) break;
      if ( A[i] == target) return i;
    }
    if(A[mid] <= target){
      low = max(mid + k, 0);
    }
    else{
      high = min(mid - k, A.size()-1);
    }
                
  }
    
    
  return idx;
}

int main(int argc, const char * argv[])
{
  vector<int> A = {6, 6, 4, 5, 6, 6, 7, 9, 6, 3};
  vector<int> B = {6, 1, 4, 5, 6, 6, 7, 9, 6, 3};
  vector<int> C = {1, 2, 3, 4, 5, 6};

  cout << getMajority(A)<<"\n";
  cout << getMajority(B)<<"\n";
    
  wiggleMe(A);
  wiggleMe(B);
  wiggleMe(C);

    
  vector<int> D = {10, 3, 40, 20, 50, 80, 70};
  cout << "Target 40:" << getElem(D, 1, 40) << "\n";
  cout << "Target 70:" << getElem(D, 2, 70) << "\n";
  cout << "Target 90:" << getElem(D, 1, 90) << "\n";
  cout << "Target 40:" << getElem(D, 3, 40) << "\n";

  std::cout << "Hello, World!\n";
  return 0;
}

