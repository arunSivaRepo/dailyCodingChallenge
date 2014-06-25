#include "LinkedList.h"
#include <vector>
#include <iostream>

using namespace std;
int main(int argc, const char * argv[])
{
  LinkedList<int> ll;
  const vector<int> vec = {10,-20,30,50,60,70};
  ll.createList(vec);
  ll.printList();
  // insert code here...
  std::cout << "Done!\n";
  return 0;
}

