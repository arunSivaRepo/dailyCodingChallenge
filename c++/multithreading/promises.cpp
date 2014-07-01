#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <future>
#include <mutex>

std::mutex mu;

// just to protect cout
void print(const std::string &str){
  std::unique_lock<std::mutex> locker(mu);
  std::cout << str << "\n";
}

// return from thread
std::string getNum1(int &x) {
  print("In getNum1");
  x += 10;
  std::ostringstream oss;
  oss << "In get Num1:" << x;
  return oss.str();
}

// return from thread
int getNum2(std::future<int> &f) {
  print("In getNum1");
  return f.get() + 10;
}

int main(int argc, const char * argv[])
{
  int x = 100;
  std::promise <int> p;
  std::future <int> f = p.get_future();
  std::future<int> res = std::async(std::launch::async, getNum2, std::ref(f));
  std::future<std::string> res1 = std::async(std::launch::async, getNum1, std::ref(x));

  std::chrono::milliseconds ms(100);
  std::this_thread::sleep_for(ms);
  // take a nap and then provide value
  p.set_value(10);
  std::cout <<"Get value back=" << res.get()<< "\n";
  std::cout <<"Get value back=" << res1.get()<< "\n";

  std::cout << "Done\n";
  return 0;
}
