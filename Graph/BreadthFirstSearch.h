// #include "Graph.h"
#include <vector>

/*
* Implementation of the Breadth First Search algorithm.
*/
class BreadthFirstSearch {
public:
  // constructor
  BreadthFirstSearch();
  BreadthFirstSearch(std::vector<std::vector<unsigned int>>connectionsIdsMatrix);

  // destructor
  ~BreadthFirstSearch();

  // member functions
  std::vector<unsigned int> getShortestPath(unsigned int startNode, unsigned int targetNode);
  std::vector<unsigned int> getShortestPath(std::vector<std::vector<unsigned int>> *connectionsMatrix, unsigned int startNode, unsigned int targetNode);

private:
  // member variables
  std::vector<std::vector<unsigned int>>m_connectionsIdsMatrix;
  unsigned int m_startNode;
  unsigned int m_targetNode;
  unsigned int m_currentNodeIndex;
  unsigned int m_currentNodeValue;
  //it might be interesting to store the nodes layers, but I don't know any application.
  std::vector<unsigned int>m_exploredNodesTree;
  // std::vector<std::vector<unsigned int>>m_connectionsMatrix;
  // member functions (high level)
  void init(unsigned int startNode, unsigned int targetNode);
  void fillVector();
  void findAllPathsAndRankThemByLength();
  // member functions (low level)
  void setGraphConnectionsIds(std::vector<std::vector<unsigned int>> *connectionsIdsMatrix);
  const std::vector<unsigned int> getNeighborsIdsOfNode(unsigned int nodeIndex);
  void addNeighborsIdsToVector(std::vector<unsigned int> *neighborsIds);
  void addNeighborsIdsToVectorWithoutRepetition(std::vector<unsigned int> *neighborsIds);
  void goToNextNode();
  void getShortestPath();
  int getIndex(std::vector<unsigned int> v, unsigned int target);
  // unsigned int getIndex(unsigned int target);
};
