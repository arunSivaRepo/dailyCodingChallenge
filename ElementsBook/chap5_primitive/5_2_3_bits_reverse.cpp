#include <iostream>
#include <string>
#include <utility>

using namespace std;

// swap bit at positions i,j
unsigned swap(unsigned num, unsigned int i, unsigned int j)
{
  unsigned ret = num;
  ret = (( ret >>i | (num>>j & 1) ) << i ) | num ;
  ret = (( ret >>j | (num>>i & 1) ) << j ) | num ;
  return ret;
}

// reverse bits.
unsigned reverse(unsigned num)
{
  unsigned ret = 0;
  while(num){
    ret = ret | (num & 1);
    num >>= 1;
    ret <<= 1;
  }
  return ret >> 1;
}

int main(int argc, const char * argv[])
{
  cout << swap (10,2,1) << "\n";
  cout << reverse(18) << "\n";
  cout << reverse(14) << "\n";
  cout << reverse(10) << "\n";
  cout << reverse(9) << "\n";
  cout << reverse(15) << "\n";
  cout << reverse(16) << "\n";
  std::cout << "Done!\n";
  return 0;
}
