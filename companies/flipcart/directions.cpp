#include <iostream>
#include <vector>
#include <string>

using namespace std;
// http://www.geeksforgeeks.org/flipkart-interview-set-10-campus-sde-1/

/*
 A person wants to go from origin to a particular location, he can move in only 4 directions(i.e East, West, North, South) 
 but his friend gave him a long route, help a person to find minimum Moves so that he can reach to the destination.
 Input – NESNWES
 Output – E
 You need to print the lexicographically sorted string. Assume the string will have only ‘E’ ‘N’ ‘S’ ‘W’ characters.
 E.g – SSSNEEEW
 output – EESS
*/

// no input validation. assume upper
std::string getShortRoute(const std::string &longRoute){
  std::string route;
  route.reserve(longRoute.size());
  int verticalCount = 0; // +1 for N, -1 for S
  int horizontalCount = 0; // +1 for E, -1 for W
    
  for (unsigned i=0; i<longRoute.size(); ++i){
    if (longRoute[i] == 'E') ++horizontalCount;
    else if (longRoute[i] == 'W') --horizontalCount;
    else if (longRoute[i] == 'N') ++verticalCount;
    else --verticalCount; //S
  }
  // for lexiographical order: E,N,S,W
  if(horizontalCount >0){ //E
    route.insert(route.end(),horizontalCount, 'E');
  }
  if(verticalCount >0){ //N
    route.insert(route.end(),verticalCount, 'N');
  }
  if(verticalCount <0){ //S
    route.insert(route.end(), abs(verticalCount), 'S');
  }
  if(horizontalCount <0){ //W
    route.insert(route.end(), abs(horizontalCount), 'W');
  }
  return route;
}

int main() {
  std::string inp1("NESNWES"), inp2("SSSNEEEW"), inp3("EEWWNSNS"), inp4("NENE");
  cout << getShortRoute(inp1)<<"\n";
  cout << getShortRoute(inp2)<<"\n";
  cout << getShortRoute(inp3)<<"\n";
  cout << getShortRoute(inp4)<<"\n";
  cout << "Done!\n";
  return 0;
}
