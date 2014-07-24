#include "LL.h"
#include <vector>
#include <iostream>

using namespace std;
int main(int argc, const char * argv[])
{
  LinkedList<int> ll;
  const vector<int> vec = {10,-20,30,50,60,70};
  ll.createList(vec);
  ll.printList();
  std::shared_ptr<Node <int>> cur(new Node<int>(100));
  ll += cur;
  ll.printList();
  ll.recReverse();
  ll.printList();
  cout << ll.getNthNodeFromLast(4) << endl;
  cout << ll.getNthNodeFromLast(14) << endl;
    
  // palindrome
  cout << "Palindrome tests...\n";
  LinkedList<char> cl;
  const vector<char> cvec = {'a','b', 'm', 'b','a'}; //{'a','b','c','a'}; //{'a','b','b','a'};
  cl.createList(cvec);
  cl.printList();
  cout << cl.isPalindrome() << "\n";
    
  cout << "sort tests...\n";
  //ll.sort(INT_MAX);
  ll.printList();
  cl.sort('Z');
  cl.printList();
  // insert code here...
  std::cout << "Done!\n";
  return 0;
}
