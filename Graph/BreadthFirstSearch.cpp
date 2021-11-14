#include "BreadthFirstSearch.h"

/*
*
*/
BreadthFirstSearch::BreadthFirstSearch()
{

}

/*
*
*/
BreadthFirstSearch::BreadthFirstSearch(std::vector<std::vector<unsigned int>>connectionsMatrix)
: m_connectionsMatrix(connectionsMatrix)
{

}

/*
*
*/
BreadthFirstSearch::~BreadthFirstSearch()
{

}

/*
*
*/
std::vector<unsigned int> BreadthFirstSearch::getShortestPath(unsigned int startingNode, unsigned int targetNode)
{
  std::vector<unsigned int> shortestPath = {0, 1, 2, 3};
  return shortestPath;
}

/*
*
*/
std::vector<unsigned int> BreadthFirstSearch::getShortestPath(std::vector<std::vector<unsigned int>> graph, unsigned int startingNode, unsigned int targetNode)
{
  std::vector<unsigned int> shortestPath = {0, 1, 2, 3};
  return shortestPath;
}

/*
*
*/
void BreadthFirstSearch::setCurrentNode()
{

}

/*
*
*/
unsigned int BreadthFirstSearch::getCurrentNode()
{
  return 0;
}

/*
*
*/
int BreadthFirstSearch::getNeighborsOfCurrentNode(void)
{
  // for (unsigned int i = 0; i < this->m_currentNode.; i++) {
  //   this->m_neighborNodesQueue;
  // }
  return 0;
}
