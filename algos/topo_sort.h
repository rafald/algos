#pragma once
#include <vector>
#include <set>
#include <unordered_map>
#include <map> //?
#include <algorithm>
#include "boost/graph/adjacency_list.hpp"

namespace algos {

template <class Int>	
using graph_t = std::multimap< Int, Int>;
//topo_sort(std::unordered_multimap< int, int> adj) { 

// Adjacency List, directed, acyclic
// continuous ids for nodes starting from 0 - Int()
template <class Int>
std::vector<Int> 
topo_sort(graph_t<Int> const & adj) { 
    //find indegrees for each node 
    std::vector<Int> indegrees;
    for( auto pc: adj ) { // parent/child
        auto const required_size = std::max(pc.second+1,pc.first+1);
        if(required_size > indegrees.size() ) indegrees.resize(required_size);
        ++indegrees[pc.second];
    }

    std::vector<Int> result;
    // look for nodes without incoming edges
    for( auto f = std::find(indegrees.begin(), indegrees.end(), 0); 
            f!=indegrees.end();  
            f = std::find(indegrees.begin(), indegrees.end(), 0)) {
        Int v = std::distance(indegrees.begin(), f);
        result.push_back(v);
        //auto [fe, le] = adj.equal_range(v);
        //std::for_each(fe, le, [&](auto e){--indegrees[e.second]; } );
        for (auto e: boost::make_iterator_range(adj.equal_range(v))) { 
            --indegrees[e.second];//remove 
        }
        *f=-1;//we do not remove processed nodes but mark as done with -1
    } 
    if( result.size() != indegrees.size()) {
        return {};
    }

    return result;
}
}
