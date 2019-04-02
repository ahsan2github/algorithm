#include "graph.h"

Graph::Graph(int v) : m_nNodes(v), m_bag(v, std::vector<int>()) {
  // do nothing
}

void Graph::addEdge(int u, int v){
  m_bag[u].emplace_back(v);
  m_bag[v].emplace_back(u);
  m_nEdges+=1;
}
Graph::adjIter Graph::adj(int v) {
  return std::make_pair(m_bag[v].begin(), m_bag[v].end());
}

int Graph::getEdgeNos() { return m_nEdges; }

int Graph::getVertexNos() { return m_nNodes; }

void Graph::toString() {
  std::cout << getVertexNos() << std::endl;
  std::cout << getEdgeNos() << std::endl;
  for(int ii=0; ii < getVertexNos(); ++ii ){
    if(!m_bag[ii].empty()){
      Graph::adjIter x = adj(ii);
      std::cout << ii << "  ";
      if(x.first != x.second){
        for(std::vector<int>::iterator itr = x.first; itr != x.second; ++itr){
          std::cout << *itr << "  ";
        }
        std::cout << std::endl;
      }
    }
  }
  std::cout << std::endl;
}
