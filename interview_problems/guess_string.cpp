#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>

using namespace std;

template <class T>
struct GraphNode{
  T data;
  vector<GraphNode<T> *> children;
    
  GraphNode(T d):data(d){}
};

// reservior sampling.
// no order.
template <class T>
void getKRandom(const vector<T> &vec, unsigned k, vector<T> &ret)
{

  ret.clear();
  ret.resize(k);
  copy(vec.begin(), min(vec.end(), vec.begin()+k), ret.begin());
  if (vec.size() <= k) return;
  //srand(time(NULL));
  for(size_t i = k; i < vec.size(); ++i){
    unsigned rand_idx = rand() % i;
    if (rand_idx < k){
      ret[rand_idx] = vec[i] ;
    }
  }
  sort(ret.begin(), ret.end());
  for (auto &ch: ret){
    cout << ch << "\t";
  }
  cout << "\n";
}

// maintain order of input
template <class T>
void getKRandomOrder(const vector<T> &vec, unsigned k, vector<T> &ret)
{
    
  ret.clear();
  ret.resize(k);
  copy(vec.begin(), min(vec.end(), vec.begin()+k), ret.begin());
  if (vec.size() <= k) return;
  vector<unsigned> rand_indices;
  rand_indices.resize(k);
  for(unsigned i = k; i < vec.size(); ++i){
    //srand(time(NULL));
    unsigned rand_idx = rand() % i;
    if (rand_idx < k){
      rand_indices[rand_idx] = i ;
    }
  }
    
  sort(rand_indices.begin(), rand_indices.end());
  for (unsigned i=0; i<k ;++i) ret[i] = vec[rand_indices[i]];
    
  for (auto &ch: ret){
    cout << ch << "\t";
  }
  cout << "\n";
}

template <class T>
void printGraph(const map<T, GraphNode<T> *> &hash){
  for (auto it=hash.begin(); it!=hash.end(); ++it){
    cout << it->first << "  -> " ;
    vector<GraphNode<T> *> &children = it->second->children;
    for(auto child_it = children.begin(); child_it != children.end() ; ++child_it){
      cout << (*child_it)->data << ",";
    }
    cout << "\n";
  }
}

template <class T>
void print(const set<T> &s){
  cout <<"Set: ";
  for (auto it=s.begin(); it!=s.end(); ++it){
    cout << *it << "\t";
  }
  cout << "\n";
}

template <class T>
void guessString(const vector<T> &str_vec){
  map<T, GraphNode<T> *> hash;
  static const int k = 3;
  unsigned long iters =0;
  set<T> no_indegree, out_degree;
  //copy(str_vec.begin(), str_vec.end(), no_indegree.begin());
  for(auto it = str_vec.begin(); it != str_vec.end() ; ++it) no_indegree.insert(*it);
  while(no_indegree.size() != 1 || (out_degree.size() != str_vec.size() -1)){ //hash.size() != str_vec.size()){
    vector<T> ret;
    getKRandom<T>(str_vec, k, ret);
    srand(++iters + time(NULL));
    for (int i=0; i!=ret.size()-1; ++i){
      auto parentIt = hash.find(ret[i]);
      auto childIt = hash.find(ret[i+1]);
      GraphNode<T> *parent, *child;
      if(parentIt == hash.end()) {
	parent = new GraphNode<T>(ret[i]);
	hash[ret[i]] = parent;
      }
      else{
	parent = parentIt->second;
      }
      if (childIt == hash.end()){
	child = new GraphNode<T>(ret[i+1]);
	hash[ret[i+1]] = child;
      }
      else{
	child = childIt->second;
      }
      if(no_indegree.find(ret[i+1]) != no_indegree.end()) no_indegree.erase(ret[i+1]);
      if(out_degree.find(ret[i]) == out_degree.end()) out_degree.insert(ret[i]);
      vector<GraphNode<T> *> &children = parent->children;
      if(find(children.begin(), children.end(), child) == children.end()) {
	children.push_back(child);
      }
    }
  }

  printGraph(hash);

  // now do the topological sort.
    
}

int main() {

  vector<char> a = {'a', 'b' , 'c' , 'd' , 'e'};
  vector<char> ret;
  //getKRandomOrder<char>(a, 2, ret);
  guessString<char>(a);
  cout << "Done!\n";
  return 0;
}
