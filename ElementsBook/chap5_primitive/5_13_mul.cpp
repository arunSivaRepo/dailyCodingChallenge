#include <iostream>
#include <string>

using namespace std;

// sum without using + operator
unsigned int sum(unsigned int a, unsigned int b){
  unsigned int sum = 0,  k = 1, carryin =0;
  while(k){
    unsigned int ak = a & k, bk = b & k, carryout = 0;
    sum |= carryin ^ ak ^ bk;
    carryout = (carryin & ak) | (carryin & bk) | (ak & bk);
    k <<= 1;
    carryin = carryout << 1;
  }
  return sum;
}

// a*b without airthmetic operators.
unsigned int mul(unsigned int a, unsigned int b){
  unsigned int ret = 0 , twice_b = b;
  while(a){
    if (1 & a) ret = sum(ret, twice_b);
    twice_b <<= 1;
    a >>= 1;
  }
    
  return ret;
}
int main(int argc, const char * argv[])
{
  cout << sum(3,6) << "\n";
  cout << mul(3,6) << "\n";
  cout << mul(5,16) << "\n";
  std::cout << "Done!\n";
  return 0;
}

