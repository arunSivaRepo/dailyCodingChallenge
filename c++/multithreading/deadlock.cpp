#include <thread>
#include <mutex>
#include <string>
#include <iostream>
#include <chrono>

std::mutex mu1,mu2;

void print1(const std::string &s)
{
  std::lock_guard<std::mutex> l(mu1);
  std::chrono::microseconds ns(10); // force deadlock
  std::this_thread::sleep_for(ns);
  std::lock_guard<std::mutex> l2(mu2);

  for(int i=0;i<10; ++i) {
    std::cout << s << i <<"\n";
  }
}

void print2(const std::string &s)
{
  std::lock_guard<std::mutex> l(mu2);
  std::chrono::microseconds ns(10);
  std::this_thread::sleep_for(ns);
  std::lock_guard<std::mutex> l1(mu1);

  for(int i=0;i<10; ++i) {
    std::cout << s << i <<"\n";
  }
}

void fun()
{
  print1("In fun:");
}

int main(int argc, const char * argv[])
{

  std::thread t(fun);
  std::chrono::microseconds ns(5);
  std::this_thread::sleep_for(ns);
  print2("In main:");
  t.join();
  std::cout << "Done\n";
  return 0;
}

