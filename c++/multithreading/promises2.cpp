#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future
#include <chrono>

void print_int (std::future<int>& fut) {
  auto start = std::chrono::system_clock::now();
  std::cout << "Some work before future get\n";
  int x = fut.get();
  auto end = std::chrono::system_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "value: " << x <<"\tGot it in:" <<elapsed.count()  <<"ms\n";
}

int main ()
{
  std::promise<int> prom;                      // create promise
  std::future<int> fut = prom.get_future();    // engagement with future
  std::thread th1 (print_int, std::ref(fut));  // send future to new thread
  std::this_thread::sleep_for(std::chrono::milliseconds(100));  // nap for a while
  prom.set_value (10);                         // fulfill promise
                                               // (synchronizes with getting the future)
  th1.join();
  return 0;
}
