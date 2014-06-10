#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define CHECK(num, power, ret, str) if(num/power) { \
    ret += getWords(num/power) + " " + str; \
    if (num%power) {\
      ret +=  " and " + getWords(num%power); \
    } \
    return ret; \
  } \


std::string getWords(long long num)
{
  static vector<string> ones = {"zero", "one" , "two" , "three", "four" , "five", "six", "seven", "eight", "nine"};
  static vector<string> teens = {"ten", "eleven", "twelve" , "thirteen" , "fourteen", "fifteen" , "sixteen", "seventeen", "eighteen", "nineteen"};
  static vector<string> tens = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  static string hundred = "hundred";
  static string thousand = "thousand";
  static string million = "million";
  static string billion = "billion";
    
  string ret;
  if (num <0) {
    ret = "Negative ";
    num = abs(num);
  }
  if (num >= 0) {
    CHECK(num, 1000000000, ret, billion);
    CHECK(num, 1000000, ret, million);
    CHECK(num, 1000, ret, thousand);
    CHECK(num, 100, ret, hundred);
    if (num/10 >= 2) {
      ret = tens[num/10 -1];
      if (num %10) {
	ret += " " + getWords(num%10);
      }
      return ret;
    }
    if (num/10 == 1) return (teens[num % 20 - 10]);
    if (num %10) return ones[num];
    return ones[num %10];

  }
  return ret;
}

int main() {
  std::cout << getWords(120) << "\n";
  std::cout << getWords(12345) << "\n";
  std::cout << getWords(19) << "\n";
  std::cout << getWords(34) << "\n";
  std::cout << getWords(567890200) << "\n";
  std::cout << getWords(-12345) << "\n";
  std::cout << getWords(20) << "\n";
  std::cout << getWords(0) << "\n";
  std::cout << getWords(1000) << "\n";
  std::cout << getWords(1000000) << "\n";
  std::cout << getWords(10) << "\n";
  std::cout << getWords(100) << "\n";
  std::cout << getWords(1) << "\n";
  return 0;
}


