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
 LinkedList() : _head(nullptr), _tail(nullptr) {}
    
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
      cout << _head->_data << "\t" << cur->_data <<"\n";
    }
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
    
};
