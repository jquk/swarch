#include <vector>
/*
*
*/
class Graph {
public:
  // constructor
  Graph();
  // destructor
  ~Graph();

  // public member variables


  // public member functions
  std::vector<std::vector<unsigned int>> getGraph();
  void printGraph();
  const std::vector<unsigned int> getNeighborsOfNode(unsigned int nodeIndex);
  void printNeighborsOfNode(unsigned int nodeIndex);

private:
  // private member variables
  std::vector<std::vector<unsigned int>>m_adjacentMatrix;
  // private member functions
};
