#include <iostream>
#include <thread>
#include <string>
using namespace std;
mutex mu;


void print(const string &str, int i )
{
  lock_guard<mutex> lg(mu);
  //mu.lock();
  cout << str<<":"<<i <<"\n";
  //mu.unlock();
}
void fun(const string &str)
{
  for(int i=0 ; i<10; ++i) { print(str,i);}
}

class Functor
{
public:
  void operator()(const string &str){
    for(int i=10 ; i<20; ++i) { print(str,i);}
  }
};

int main(int argc, const char * argv[])
{
  string s("Thread func t1:");
  thread t1(fun, ref(s));
  Functor func;
  s = "Thread func t2:";
  thread t2(func, s);
  for(int i=0 ; i<10; ++i) { cout << "In main:" << i << endl;}
  t1.join();
  t2.join();
    
  cout << "Main thead id" << this_thread::get_id() <<"\tT1 id:"<<t1.get_id() << "T2 id:" << t2.get_id() <<"\n";
  return 0;
}

