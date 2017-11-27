#include "weighted_graph.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <queue>
using std::queue;

/*
TODO:
  - make graph an abstract class
  - create subclass for directed and undirected graphs
  - another subclass for weighted graphs vs unweighted?
*/


weighted_graph::weighted_graph(int num_v) {
  size = num_v;
  adj = new vector<pair<int,int> >[num_v]; // an array of num_v integer vectors
}

weighted_graph::~weighted_graph() {
  delete[] this->adj;
}

void add_edge(weighted_graph* wg, int s, int v, int weight) {
  wg->adj[s].push_back(make_pair(v, weight));
  wg->adj[v].push_back(make_pair(s, weight));
}

// dijkstra's algorithm
// s := start vertex
// v := destination vertex
// X := vertices dealth with
// V := vertices not dealt with
// A := shortest path distances from src to all other vertices
// e.g. A[s] = 0

/*
while X != V

*/

void print_graph(weighted_graph* wg) {
  for(int i = 0; i < wg->size; i += 1) {
    cout << "[" << i << "]: -> ";
    for(auto j = wg->adj[i].begin(); j != wg->adj[i].end(); j += 1) {
      cout << j->first << ", " << j->second << " -> ";
    }
    cout << "NULL" << endl;
  }
}
