#include <iostream>

struct My {
 int i;
 std::once_flag fg;
 void init(){
   i = 100;
 }

  void fun(){
   std::call_once(fg, std::bind(&My::init,this));
   std::cout << i << "\n";
   i +=1;
  }

};

int main() {
  My m;
  for (int i=0; i <5; ++i) m.fun();
  return 0;
}
