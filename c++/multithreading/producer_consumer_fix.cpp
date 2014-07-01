#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <queue>
using namespace std;
// Question: See towards the end: http://www.classes.cs.uchicago.edu/archive/2013/spring/12300-1/labs/lab6/
int main() {
  int c = 0;
  bool done = false;
  queue<int> goods;
  mutex m;
  condition_variable cond;

  thread producer([&]() {
      for (int i = 0; i < 500; ++i) {
	unique_lock<mutex> locker(m);
	goods.push(i);
	c++;
	m.unlock();
	cond.notify_one();
      }
      done = true;
    });

  thread consumer([&]() {
      while (!done && !goods.empty()) {
	  unique_lock<mutex> locker(m);
	  cond.wait(locker, [&] { return !goods.empty();} );
	  goods.pop();
	  c--;
	  m.unlock();
      }
    });

  producer.join();
  consumer.join();
  cout << "Net: " << c << endl;
}
