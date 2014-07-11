#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getDecVal(char c){
  c = tolower(c);
  if (c >= '0' && c <= '9'){
    return c -'0';
  }
  else {
    return 10 + c - 'a';
  }
}

char toOtherBase(int n){
  n = abs(n);
  if (n >=0 && n<=9){
    return '0' +n;
  }
  else {
    return 'a' + (n-10);
  }
}

// inefficient - convert to decimal first and then to appropriate base.
string convertToBase(string inp, int from_base, int to_base)
{
  string out;
  int dec = 0;
  int pow = 1;
  bool neg = false;
  for (auto it = inp.rbegin(); it != inp.rend(); ++it){
    if (*it == '-') {neg = true; break;}
    dec += getDecVal(*it) * pow;
    pow *= from_base;
  }
  if (neg) dec = -dec;
  cout << "Decimal equivalent = " << dec << "\n";
    
  while(dec){
    out += toOtherBase(dec % to_base);
    dec /= to_base;
  }
  if (neg) out += '-';
  if (out.empty()) out ="0";
  else reverse(out.begin(), out.end());
  return out;
}

int main(int argc, const char * argv[])
{
  cout << convertToBase("2102",3,8) << "\n";
  cout << convertToBase("101",8,11) << "\n";
  cout << convertToBase("10991ffa",16,5) << "\n";
  cout << convertToBase("-10991ffa",16,5) << "\n";

  std::cout << "Done";
  return 0;
}

