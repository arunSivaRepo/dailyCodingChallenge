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
int getNum1(int &x) {
  print("In getNum1");
  x += 10;
  return x;
}


int main(int argc, const char * argv[])
{
  int a =20;
    
  // default future. may create a thread or deffered. (implementaiton specific)
  // default policy = std::launch::async|std::launch::deferred
  std::future<int> fu = std::async(getNum1, std::ref(a) );
  print("In main, created future -- 1");
  std::chrono::microseconds ns(5);
  std::this_thread::sleep_for(ns);
  std::ostringstream oss;
  oss <<"In main, future value -- 1 = " << fu.get() ;
  print(oss.str());
    
  oss.clear();
  // deffered async -- wont create a thread
  std::future<int> fu1 = std::async( std::launch::deferred, getNum1, std::ref(a) );
  print("In main, created future -- 2 ");
  std::this_thread::sleep_for(ns);
  oss <<"In main, future value --2 = " << fu1.get() ;
  print(oss.str());
    
    
  oss.clear();
  // dalways create a thread
  std::future<int> fu2 = std::async( std::launch::async, getNum1, std::ref(a) );
  print("In main, created future -- 3 ");
  std::this_thread::sleep_for(ns);
  oss <<"In main, future value --3 = " << fu2.get() ;
  print(oss.str());
  std::cout << "Done\n";
  return 0;
}

