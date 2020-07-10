#pragma once
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using vertice_id = int;
std::vector<vertice_id> 
topo_sort(std::unordered_multimap< vertice_id, vertice_id> adj) { // Adjacency List, directed, acyclic
    std::vector<vertice_id> S;// scan for start nodes - nodes without incomming edges
    std::set<vertice_id> all_v;
    std::set<vertice_id> have_parent_v;
    for( auto p: adj ) {
        all_v.insert(p.first);
        all_v.insert(p.second);
        have_parent_v.insert(p.second);
    }
    std::set_difference (all_v.begin(), all_v.end(), have_parent_v.begin(), have_parent_v.end(), std::back_inserter(S));
/*
    std::vector<vertice_id> torder;
    for(auto s : S) {
        for (auto e: adj.equal_range(s)) {

        }
    }*/
    return S;
}