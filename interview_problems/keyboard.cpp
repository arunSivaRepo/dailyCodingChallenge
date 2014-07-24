#include <iostream>
#include <vector>
#include <string>

#define NROWS 6
#define NCOLS 5

using namespace std;
// http://www.careercup.com/question?id=15542726

void printHelper(unsigned num, const string &str){
  for (unsigned i=0; i< num; ++i) cout << str<<"\n";
}
// print directions from one point to another
void printLoc(char mat[NROWS][NCOLS], char start, char end){
  int start_row, start_col, end_row, end_col;
  start_row = (start - 'a') / NCOLS;
  start_col = (start - 'a') % NCOLS;
  end_row = (end - 'a') / NCOLS;
  end_col = (end - 'a') % NCOLS;
    
  if (end_row > start_row){
    printHelper(abs(end_row - start_row) , "DOWN");
  }
  else if (start_row > end_row){
    printHelper(abs(end_row - start_row) , "UP");
  }
    
  if (end_col > start_col){
    printHelper(abs(end_col - start_col) , "RIGHT");
  }
  else if (start_col > end_col){
    printHelper(abs(end_col - start_col) , "LEFT");
  }
  cout << "CLICK:" << end << "\n";
}

void printSequence(char mat[NROWS][NCOLS], const string &str){
    
  char cur = 'a', target;
  for (unsigned i=0; i<str.size() ; ++i){
    target = str[i];
    if(cur!=target) {
      printLoc(mat, cur, target);
    }
    else{
      cout << "CLICK:" << cur << "\n";
    }
    cur = target;
  }
}

int main() {
  char mat[NROWS][NCOLS] ={
    { 'a', 'b', 'c', 'd', 'e' },
    { 'f', 'g', 'h', 'i', 'j' },
    { 'k', 'l', 'm', 'n', 'o' },
    { 'p', 'q', 'r', 's', 't' },
    { 'u', 'v', 'w', 'x', 'y' },
    { 'z' }
  };
  printSequence(mat, "zaxxvty");
  cout << "Done!\n";
  return 0;
}
