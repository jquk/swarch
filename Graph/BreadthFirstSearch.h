#include <queue>

/*
* Implementation of the Breadth First Search algorithm.
*/
class BreadthFirstSearch {
public:
  // constructor
  BreadthFirstSearch();
  BreadthFirstSearch(std::vector<std::vector<unsigned int>>graph);


  // destructor
  ~BreadthFirstSearch();

  // member functions
  std::vector<unsigned int> getShortestPath(unsigned int startingNode, unsigned int targetNode);
  std::vector<unsigned int> getShortestPath(std::vector<std::vector<unsigned int>> graph, unsigned int startingNode, unsigned int targetNode);

private:
  // member variables
  unsigned int m_currentNode;
  std::queue<int>m_neighborNodesQueue;
  std::vector<std::vector<unsigned int>>m_connectionsMatrix;
  // member functions
  void setCurrentNode();
  unsigned int getCurrentNode();
  int getNeighborsOfCurrentNode(void);
};
