#include "topo_sort.h"
#include <iostream>

int main() {
  std::unordered_multimap< vertice_id, vertice_id> adj = { 
    {1,6}, 
    {2,5}, 
    {3,5}, 
    {4,5}, 
    {5,6}, 
    {4,7}, 
    {6,7}, 
    {7,8}, 
    {7,9}, 
    };
  std::vector<vertice_id> r = topo_sort(adj);

  for(auto v : r)
     std::cout << v << ", ";
  return 0;
}
