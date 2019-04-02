#include <iostream>
#include <string>
#include <vector>

class Graph {
public:
  typedef std::pair<std::vector<int>::iterator, std::vector<int>::iterator>
      adjIter;
  Graph(int v);
  void addEdge(int u, int v);
  adjIter adj(int v);

  int getEdgeNos();
  int getVertexNos();
  void toString();

private:
  int m_nNodes;
  int m_nEdges;
  std::vector<std::vector<int> > m_bag;
};
