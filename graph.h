#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using std::vector;

struct graph {
  int size;
  vector<int> *adj;
  vector<int> *wgt;
  graph(int num_v);
  ~graph();
};

void BFS(graph* g, int s);
void DFS(graph* g, int s);

void print_graph(graph* g);

void add_edge(graph* g, int s, int v);

#endif /* GRAPH_H */
