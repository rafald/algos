#include <iostream>
#include "algos/topo_sort.h"

int main() {
  //std::unordered_multimap< int, int> adj = { 
  std::multimap< int, int> adj = { 
    {0,7},
    {1,6}, 
    {2,5}, 
    {3,5}, 
    {4,5}, 
    {5,6}, 
    {4,7}, 
    {6,7}, 
    {7,8}, 
    {9,7},
    };
  auto r = topo_sort(adj);

  std::cout << "\n";
  for(auto v : r)
     std::cout << v << ", ";
  std::cout << "\nDONE";
  return 0;
}
