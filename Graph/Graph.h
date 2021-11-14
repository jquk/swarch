#include <vector>
// #include "BreadthFirstSearch.h"
enum GraphAlgorithm { BREADTH_FIRST_SEARCH, DEPTH_FIRST_SEARCH };


/*
*
*/
class Graph {
public:
  // constructor
  Graph();
  Graph(std::vector<std::vector<unsigned int>>graph);
  // destructor
  ~Graph();

  // public member variables

  // public member functions
  void setGraph(unsigned int graphId);
  std::vector<std::vector<unsigned int>> getGraphConnections();
  void calculateGraphConnectionsIds();
  std::vector<std::vector<unsigned int>> getGraphConnectionsIds();
  void printGraphConnections();
  void printGraphConnectionsIds();
  const std::vector<unsigned int> getNeighborConnectionsOfNode(unsigned int nodeIndex);
  const std::vector<unsigned int> getNeighborsIdsOfNode(unsigned int nodeIndex);
  void printNeighborConnectionsOfNode(unsigned int nodeIndex);
  void printNeighborIdsOfNode(unsigned int nodeIndex);
  std::vector<unsigned int> getShortestPath(GraphAlgorithm algorithm, unsigned int startingNode, unsigned int targetNode);

private:
  // private member variables
  std::vector<std::vector<unsigned int>>m_connectionsMatrix;
  std::vector<std::vector<unsigned int>>m_connectionsIdsMatrix;
  // private member functions
};
