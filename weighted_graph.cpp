#include "weighted_graph.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <queue>
using std::queue;
using std::priority_queue;
using std::greater;
using std::make_pair;

#define INF 0x3f3f3f3f  // https://sxkdz.org/why-programmers-like-to-set-infinity-to-0x3f3f3f3f/

typedef pair<int, int> int_pair;

weighted_graph::weighted_graph(int num_v) {
  size = num_v;
  adj = new vector<int_pair >[num_v]; // pair.first is the vertex, pair.second is the edge weight
}

weighted_graph::~weighted_graph() {
  delete[] this->adj;
}

void add_edge(weighted_graph* wg, int s, int v, int weight) {
  wg->adj[s].push_back(make_pair(v, weight));
  wg->adj[v].push_back(make_pair(s, weight));
}

// see: http://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
void dijkstras_shortest_path(weighted_graph *wg, int s) {
  // TODO: I should probably have a custom comparator for pairs, since i want only the
  // weights compared, and the comparison may accidentally happen on vertex ids: http://en.cppreference.com/w/cpp/utility/pair/operator_cmp
  priority_queue< int_pair, vector <int_pair> , greater<int_pair> > pq; // min-heap of vertices processed so far. see http://www.geeksforgeeks.org/implement-min-heap-using-stl/
  vector<int> distances(wg->size, INF); // computed shortest path distances.
  pq.push(make_pair(s, 0));
  distances[s] = 0;
  // NOTE: the Coursera course checks pq != wg->size, probably just keep growing pq without popping the top
  while(!pq.empty()) {
    int v = pq.top().first;
    for(auto i = wg->adj[v].begin(); i != wg->adj[v].end(); i += 1) {
      int u = i->first;
      int wgt = i->second;

      cout << u << ", "  << wgt << endl;
      if(distances[u] > distances[v] + wgt) { // "Dijkstra's Greedy Criterion"
        distances[u] = distances[v] + wgt;
        pq.push(make_pair(u, distances[u]));
      }
    }
  }
  // Print shortest distances stored in dist[]
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < wg->size; ++i) {
    printf("%d \t\t %d\n", i, distances[i]);
  }
}

void print_graph(weighted_graph* wg) {
  for(int i = 0; i < wg->size; i += 1) {
    cout << "[" << i << "]: -> (";
    for(auto j = wg->adj[i].begin(); j != wg->adj[i].end(); j += 1) {
      cout << j->first << ", " << j->second << ") -> (";
    }
    cout << "NULL)" << endl;
  }
}
