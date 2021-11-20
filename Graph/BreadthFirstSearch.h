// #include "Graph.h"
#include <vector>
#include "dataTypes.h"
#include "Layers.h"

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
  Layers m_layers;
  // member functions (high level)
  void init(unsigned int startNode, unsigned int targetNode);
  void exploreGraph();
  void findPaths();
  void findAllPaths();
  // member functions (low level)
  void setGraphConnectionsIds(std::vector<std::vector<unsigned int>> *connectionsIdsMatrix);
  const std::vector<unsigned int> getNeighborsIdsOfNode(unsigned int nodeIndex);
  void addNeighborsIdsToExploredNodesVector(std::vector<unsigned int> *neighborsIds);
  void addNeighborsIdsToExploredNodesVectorWithoutRepetition(std::vector<unsigned int> *neighborsIds);
  int getIndex(std::vector<unsigned int> v, unsigned int target);
};
