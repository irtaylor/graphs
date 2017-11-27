#include "graph.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

/*
TODO:
  - make graph an abstract class
  - create subclass for directed and undirected graphs
  - another subclass for weighted graphs vs unweighted?
*/


graph::graph(int num_v) {
  size = num_v;
  adj = new vector<int>[num_v]; // an array of num_v integer vectors
  wgt = new vector<int>[num_v];
}

graph::~graph() {
  delete[] this->adj;
  delete[] this->wgt;
}

void add_edge(graph* g, int s, int v) {
  g->adj[s].push_back(v);
  g->adj[v].push_back(s);
}


/* TODO: return something useful maybe... */
void BFS(graph* g, int s) {
  bool* explored = new bool[g->size](); // initialize the elements of the array when allocating
  queue<int> q;

  explored[s] = true;
  q.push(s);

  while(q.size() > 0) {
    int v = q.front();
    q.pop();
    // for each edge (v,w)
    for(auto w = g->adj[v].begin(); w != g->adj[v].end(); w += 1) {
      if(!explored[*w]) {
        explored[*w] = true;
        q.push(*w);
      }
    }
  }
  delete[] explored;
}

void _DFS_helper(graph* g, int s, bool* explored) {
  explored[s] = true;
  for(auto v = g->adj[s].begin(); v != g->adj[s].end(); v += 1) {
    if(!explored[*v]) {
      explored[*v] = true;
      _DFS_helper(g, *v, explored);
    }
  }
}

void DFS(graph* g, int s) {
  bool* explored = new bool[g->size]();
  _DFS_helper(g, s, explored);
  delete[] explored;
}

void print_graph(graph* g) {
  for(int i = 0; i < g->size; i += 1) {
    cout << "[" << i << "]: -> ";
    for(std::vector<int>::const_iterator j = g->adj[i].begin(); j != g->adj[i].end(); j += 1) {
      cout << *j << " -> ";
    }
    cout << "NULL" << endl;
  }
}
