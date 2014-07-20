#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
// http://www.careercup.com/question?id=5749794861481984
// flood fill.

inline unsigned getKey(unsigned row, unsigned col, unsigned ncols){
  return row * ncols + col;
}

template <size_t T>
void fill(char mat[][T], int i, int j, unsigned nrows, unsigned ncols, const unordered_map<unsigned, unsigned> &hash,
	  unordered_set<unsigned> &visited, unsigned regionId, bool diag){

  if (i <0 || i >= nrows || j<0 || j>= ncols || mat[i][j] != 'x') return;
    
  unsigned key = getKey(i,j,ncols);
  if (visited.find(key) != visited.end()) return;
  cout << "Visited:" << i<<"," <<j<<"\n";
  visited.insert(key);
    
  if(diag) fill(mat, i-1, j-1, nrows, ncols, hash, visited, regionId, diag);
  fill(mat, i-1, j, nrows, ncols, hash, visited, regionId, diag);
  if(diag) fill(mat, i-1, j+1, nrows, ncols, hash, visited, regionId, diag);
  fill(mat, i, j-1, nrows, ncols, hash, visited, regionId, diag);
  fill(mat, i, j+1, nrows, ncols, hash, visited, regionId, diag);
  if(diag) fill(mat, i+1, j-1, nrows, ncols, hash, visited, regionId, diag);
  fill(mat, i+1, j, nrows, ncols, hash, visited, regionId, diag);
  if(diag) fill(mat, i+1, j+1, nrows, ncols, hash, visited, regionId, diag);

}

template <size_t T>
unsigned getNumRegions(char mat[][T], unsigned nrows, unsigned ncols, bool diag = false){
  unsigned num = 0;
  unordered_map<unsigned, unsigned> hash;
  unordered_set<unsigned> visited;
    
  for (unsigned i=0; i<nrows; ++i){
    for (unsigned j=0; j<ncols; ++j){
      unsigned key = getKey(i,j,ncols);
      if (mat[i][j] != 'x' || (visited.find(key) != visited.end()) ) continue;
      cout << "Fill:" << i<<"," <<j<<"\n";
      fill<T>(mat, i, j, nrows, ncols, hash, visited, ++num, diag);
    }
  }
    
  return num;
}

int main() {
  char mat[4][3] = {
    {'x','o','o'},
    {'o','x','x'},
    {'x','o','o'},
    {'o','x','x'}
  };
    
  cout << getNumRegions<3>(mat,4,3) <<"\n";
  cout << getNumRegions<3>(mat,4,3, true) <<"\n";
  cout << "Done!\n";
  return 0;
}
