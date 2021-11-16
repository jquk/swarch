// #include "Graph.h"
#include <vector>
#include "Graph_dataTypes.h"

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
  Inputs_t m_inputs;
  CurrentState_t m_currentState;
  Outputs_t m_outputs;
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
};
