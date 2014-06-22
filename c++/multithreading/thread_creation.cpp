#include <iostream>
#include <thread>

using namespace std;

void fun()
{
  for(int i=0 ; i<10; ++i) { cout << "In thread:" << i << endl;}
}

class Functor
{
public:
  void operator()(){
    for(int i=0 ; i<10; ++i) { cout << "In Func thread:" << i << endl;}
  }
};

int main(int argc, const char * argv[])
{
  thread t1(fun);
  Functor func;
  thread t2(func);
  for(int i=0 ; i<10; ++i) { cout << "In main:" << i << endl;}
  t1.detach();
  t2.join();
    
  cout << "Main thead id" << this_thread::get_id() <<"\tT1 id:"<<t1.get_id() << "T2 id:" << t2.get_id() <<"\n";
  return 0;
}
