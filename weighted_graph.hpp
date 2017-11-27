#ifndef WEIGHTED_GRAPH_HPP_
#define WEIGHTED_GRAPH_HPP_

#include <vector>
using std::vector;
using std::pair;


struct weighted_graph {
  int size;
  vector<pair<int,int> >* adj;
  weighted_graph(int num_v);
  ~weighted_graph();
};

//void priority_queue_test();

void print_graph(weighted_graph* wg);

void add_edge(weighted_graph* wg, int s, int v, int weight);

void dijkstras_shortest_path(weighted_graph *wg, int s);

#endif /* WEIGHTED_GRAPH_HPP_ */
