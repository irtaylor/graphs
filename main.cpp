#include "graph.hpp"
#include "weighted_graph.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {

  /*cout << "\nGraph:" << endl;
  graph* g = new graph(6);


  print_graph(g);*/

  weighted_graph* wg = new weighted_graph(6);

  cout << "\nWeighted Graph:" << endl;
  add_edge(wg, 0, 1, 1);
  add_edge(wg, 0, 2, 2);
  add_edge(wg, 1, 2, 3);
  add_edge(wg, 1, 3, 2);
  add_edge(wg, 1, 4, 2);
  add_edge(wg, 2, 4, 2);
  add_edge(wg, 3, 5, 4);
  add_edge(wg, 4, 5, 1);
  print_graph(wg);

  delete wg;
  return 0;
}
