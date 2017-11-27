#include "graph.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

  cout << "\nGraph:" << endl;
  graph* g = new graph(5);
  add_edge(g, 0, 3);
  add_edge(g, 0, 4);
  add_edge(g, 1, 4);
  add_edge(g, 1, 2);

  print_graph(g);

  //cout << "\n\nBFS:\n";
  //BFS(g, 0);

  cout << "\n\nDFS:" << endl;
  DFS(g, 0);

  delete g;
  return 0;
}
