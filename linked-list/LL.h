#pragma once
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
template <class T>
class Node {
 public:
 Node(const T &data, std::shared_ptr<Node <T>> ptr = nullptr) :
  _data(data), _next(ptr) {}
 Node(std::shared_ptr<Node <T>> ptr = nullptr) : _next(ptr) {}
    
  // data members
  std::shared_ptr<Node <T>> _next;
  T _data;
    
};

template <class T>
class LinkedList {
 public:
 LinkedList() : _head(nullptr), _tail(nullptr), _sorted(false) {}
    
 LinkedList(bool sorted) : _head(nullptr), _tail(nullptr), _sorted(sorted) {}
    
  void clearList(){
    std::shared_ptr<Node <T>> cur = _head, next;
    while (cur){
      next = cur->_next;
      cur.reset();
      cur = next;
    }
  }
    
  void createList(const std::vector<T> &data) {
    clearList(); //clear the current linked list;
        
    for (const T &val: data){
      std::shared_ptr<Node <T>> cur;
      cur.reset(new Node<T>(val));
      if (!_head) {
	_head = _tail = cur;
	continue;
      }
      _tail->_next = cur;
      _tail = cur;
    }
  }
    
  std::shared_ptr<Node <T>> deleteMin(std::shared_ptr<Node <T>> &start, T min){
    std::shared_ptr<Node <T>> prev = nullptr, minprev, ret;
    for(std::shared_ptr<Node <T>> cur = start; cur ; cur=cur->_next){
      if (cur->_data < min){
	min = cur->_data;
	minprev = prev;
      }
      prev = cur;
    }
        
    if (minprev){
      ret = minprev->_next;
      minprev->_next = minprev->_next->_next;
      if (minprev->_next == nullptr) _tail = minprev;
    }
    else{ // deleting head
      ret = _head;
      _head = _head->_next;
    }
        
    return ret;
  }
    
  // O(n^2 sort)
  void sort(T max) {
    LinkedList<T> sorted;
    while (_head){
      sorted += deleteMin(_head, max);
    }
    clearList();
    _head = sorted._head;
    _tail = sorted._tail;
  }
    
  void reverse(){
    std::shared_ptr<Node <T>> next, cur, prev;
    prev = nullptr;
    _tail = cur = _head;
    while (cur){
      next = cur->_next;
      cur->_next = prev;
      prev = cur;
      cur = next;
    }
    _head = prev;
  }
    
  // recursive
  std::shared_ptr<Node <T>> recReverseHelper(std::shared_ptr<Node <T>> cur){
    if (cur->_next == nullptr){
      _head = cur;
    }
    else {
      std::shared_ptr<Node <T>> last = recReverseHelper(cur->_next);
      last->_next = cur;
      //cur->_next = nullptr;
    }
    return cur;
  }
  // recursive
  void recReverse(){
    _tail = recReverseHelper(_head);
    _tail->_next = nullptr;
  }

  LinkedList<T>& sortedAppend() {
  }
    
  // return default constructed value if invalid.
  T getNthNodeFromLast(unsigned n){
    T result;
    std::shared_ptr<Node<T> > slow = _head, fast = _head;
        
    for (unsigned i=0; i<n ;++i){
      if (fast == nullptr) return result;
      fast = fast->_next;
    }
        
    while (fast){
      fast = fast->_next;
      slow = slow->_next;
    }
        
    return slow->_data;
  }
    
  // append a node.
  LinkedList<T>& operator+=(const std::shared_ptr<Node <T>> &node) {
    if (_tail) {
      _tail->_next = node;
    }
    else {
      _head = node;
    }
    node->_next = nullptr;
    _tail = node;
    return *this;
  }
    
  bool isPalindromeHelper(const std::shared_ptr<Node <T>> &cur){
    static std::shared_ptr<Node <T>> front = _head;
    static bool ret = true;
        
    if(cur->_next){
      if (!isPalindromeHelper(cur->_next)) return false;
    }
    if (front->_data != cur->_data) ret = false;
    front = front->_next;
        
    return ret;

  }
    
  bool isPalindrome(){
    return isPalindromeHelper(_head);
  }
    
  void printList(std::ostream &out = std::cout) const{
    std::shared_ptr<Node <T>> cur = _head;
    while (cur){
      out << cur->_data <<" , ";
      cur = cur->_next;
    }
    out << std::endl;
  }
    
  // data members
  std::shared_ptr<Node <T>> _head, _tail;
  bool _sorted;
};
