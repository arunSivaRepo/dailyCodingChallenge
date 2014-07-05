#include <iostream>
#include <string>

using namespace std;

class BigInteger {

public:
  explicit BigInteger(std::string str) : _str(str) {}
  BigInteger() : _str("") {}

  long toInt() const{
    long ret = 0;
    for(size_t i=0 ;i<_str.length() ;++i){
      ret = ret*10 + (_str[i] - '0');
    }
    return ret;
  }
    
  BigInteger operator*(const BigInteger &num) const{
    BigInteger ret;
        
    return ret;
  }
    
  BigInteger reverse(){
    BigInteger ret = *this;
    if (ret._str.empty()) return ret;
    for (size_t i = ((ret._str[0] == '-') ? 1 : 0), j = ret._str.length() -1 ;
	 i < j; ++i, --j){
      std::swap(ret._str[i], ret._str[j]);
    }
    return ret;
  }
    
  friend ostream& operator<< (std::ostream & out, const BigInteger &big);
    
  // no error check on non digits
  BigInteger operator*(char digit){
    BigInteger ret;
    if (_str.empty()) return ret;
    unsigned sum, carry = 0;
    ret = this->reverse();
    std::string out;
    if(ret._str[0] == '-') out += '-';
    for (size_t i = ((ret._str[0] == '-') ? 1 : 0); i < ret._str.length(); ++i){
      unsigned mul = (digit - '0') * (ret._str[i] - '0') + carry;
      sum = mul % 10;
      carry = mul/10;
      out += '0' + sum;
    }
    if(carry) out += '0' + carry;
    ret._str = out;
    return ret.reverse();
  }
    
  BigInteger operator*=(char digit){
    return (*this = this->operator*(digit));
  }
    
  BigInteger operator*(BigInteger &other){
    BigInteger ret, other_num = other.reverse();
    if (_str.empty()) return ret;
    unsigned sum, carry = 0;
    ret = this->reverse();
    std::string out;
    size_t i = (ret._str[0] == '-') ? 1 : 0;
    size_t j = (other_num._str[0] == '-') ? 1 : 0;
    while( i < ret._str.length() || j < other_num._str.length()){
      unsigned mul =  1;
      if (i < ret._str.length()) mul *= (ret._str[i] - '0');
      if (j < other_num._str.length()) mul *= (other_num._str[j] - '0');
      mul += carry;
      sum = mul % 10;
      carry = mul/10;
      out += '0' + sum;
      ++i;
      ++j;
    }
    if(carry) out += '0' + carry;
    ret._str = out;
    return ret.reverse();
  }
    
  BigInteger operator*=(BigInteger &other){
    return (*this = this->operator*(other));
  }
    
    
  BigInteger operator+(BigInteger &other){
    BigInteger ret, other_num = other.reverse();
    if (_str.empty()) return ret;
    unsigned sum, carry = 0;
    ret = this->reverse();
    std::string out;
    size_t i = (ret._str[0] == '-') ? 1 : 0;
    size_t j = (other_num._str[0] == '-') ? 1 : 0;
    while( i < ret._str.length() || j < other_num._str.length()){
      unsigned mul =  carry;
      if (i < ret._str.length()) mul += (ret._str[i] - '0');
      if (j < other_num._str.length()) mul += (other_num._str[j] - '0');
      sum = mul % 10;
      carry = mul/10;
      out += '0' + sum;
      ++i;
      ++j;
    }
    if(carry) out += '0' + carry;
    ret._str = out;
    return ret.reverse();

  }
    
  BigInteger operator+=(BigInteger &other){
    return (*this = this->operator+(other));
  }
    
  std::string _str;
};

ostream& operator<< (std::ostream & out, const BigInteger &big){
  out << big._str << "\n";
  return out;
}
        
void tests()
{
    
  BigInteger num1("12345"), num2;
  cout << num1.toInt() << "\n";
  BigInteger r = num1.reverse();
  cout << r.toInt() << "\n";
  char c = '9';
  r =r *c;
  std::cout << r;
  r *= c;
  std::cout << r;
  BigInteger a1("12345"), a2("100");
  BigInteger ret = a1 + a2;
  std::cout << ret;
  BigInteger large("4567890145");
  ret += large;
  std::cout << ret;
  BigInteger mlarge("4567890145"), msmall("11");
  msmall *= mlarge;
  std::cout << msmall;

}

int main(int argc, const char * argv[])
{
  tests();
  std::cout << "Done!\n";
  return 0;
}
