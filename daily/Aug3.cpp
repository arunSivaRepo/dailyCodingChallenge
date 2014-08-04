#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
// http://www.geeksforgeeks.org/move-zeroes-end-array/
void push0s(vector<int> &vec)
{
  for (unsigned i=0, j=1; i < vec.size() ; ++i ){
    if (vec[i] == 0){
      if ( j < i ) j = i+1;
      while ( j < vec.size() && !vec[j]) ++j;
      if (j == vec.size()) break;
      swap(vec[i], vec[j]);
    }
  }
    
  for (int &i : vec) cout << i << "\t";
  cout <<endl;
}

// http://www.geeksforgeeks.org/merge-k-sorted-arrays/
struct Elem{
  int data;
  unsigned arrno, index;
  Elem(int d, int a, int i) : data(d), arrno(a), index(i) {}
};

bool comp(const Elem &a, const Elem &b){
  return a.data > b.data;
}

void merge(const vector<vector<int>> &arrs){
  vector<int> out;
  vector<Elem> heap;
  for (unsigned i= 0; i<arrs.size() ; ++i){
    heap.push_back(Elem(arrs[i][0],i,0));
  }
    
  while (!heap.empty()){
    std::make_heap(heap.begin(), heap.end(), comp);
    std::pop_heap(heap.begin(), heap.end(), comp);
    Elem &smallest = heap.back();
    out.push_back(arrs[smallest.arrno][smallest.index]);
    ++smallest.index;
    if (smallest.index < arrs[smallest.arrno].size()){
      smallest.data = arrs[smallest.arrno][smallest.index];
    }
    else {
      heap.pop_back();
    }
  }
    
  for (auto &i: out) cout << i << ", ";
  cout << endl;
    
}

int main(int argc, const char * argv[])
{
  vector<int> A = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
  push0s(A);
    
  vector< vector<int>> arrs = {
    {1, 2, 5, 10},
    { -1, 4, 9, 10, 18},
    {0, 1, 2, 7}
  };
  merge(arrs);
    
  std::cout << "Done\n";
  return 0;
}

