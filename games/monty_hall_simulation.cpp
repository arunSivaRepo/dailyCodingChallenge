#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void sim(unsigned long num)
{
  srand (time(NULL));
  unsigned long noSwitchWins=0, switchWins=0;
  for (unsigned long i=0 ;i<num ;++i){
    unsigned car = rand() % 3;
    unsigned user_pick = rand() % 3;
    unsigned host_pick;
    for (unsigned j=0; j<3 ;++j) {
      if (j==user_pick || j==car) continue;
      host_pick = j ; break;
    }
    // user doesnt switch
    if (user_pick == car) ++noSwitchWins;
    unsigned switch_pick;
    for (unsigned j=0; j<3 ;++j) {
      if (j==user_pick || j==host_pick) continue;
      switch_pick = j ; break;
    }
    if (switch_pick == car) ++switchWins;
  }
  cout << "Total=" << num <<"\tNo switch wins=" << noSwitchWins << "\tSwitch wins=" << switchWins << "\n";
}

int main(){
  sim(100);
  sim(100000); //100K
  sim(1000000); //1M
  sim(100000000); //100M
  return 0;
}
