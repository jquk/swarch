#include "BreadthFirstSearch.h"
#include <iostream>

/*
*
*/
BreadthFirstSearch::BreadthFirstSearch()
{

}

/*
*
*/
BreadthFirstSearch::BreadthFirstSearch(std::vector<std::vector<unsigned int>>connectionsIdsMatrix)
: m_connectionsIdsMatrix(connectionsIdsMatrix)
{

}

/*
*
*/
BreadthFirstSearch::~BreadthFirstSearch()
{

}

/*------------------------------------------ Public Member Functions ------------------------------------*/

/*
*
*/
std::vector<unsigned int> BreadthFirstSearch::getShortestPath(unsigned int startNode, unsigned int targetNode)
{
  this->init(startNode, targetNode);
  this->fillVector();
  std::vector<unsigned int> shortestPath = {0, 1, 2, 3};
  return shortestPath;
}

/*
*
*/
std::vector<unsigned int> BreadthFirstSearch::getShortestPath(std::vector<std::vector<unsigned int>> *connectionsMatrix, unsigned int startNode, unsigned int targetNode)
{
  this->init(startNode, targetNode);
  this->fillVector();
  std::vector<unsigned int> shortestPath = {0, 1, 2, 3};
  return shortestPath;
}


/*----------------------------------- Private Member Functions (high level) -----------------------------*/

/*
*
*/
void BreadthFirstSearch::init(unsigned int startNode, unsigned int targetNode)
{
  this->m_startNode = startNode;
  this->m_targetNode = targetNode;
  this->m_currentNodeValue = startNode;
  this->m_currentNodeIndex = 0;
}

/*
*
*/
void BreadthFirstSearch::fillVector()
{
  std::vector<unsigned int> currentNodeNeighborsIds = {0};
  this->addNeighborsIdsToVector(&currentNodeNeighborsIds);

  // get neighbors of node
  currentNodeNeighborsIds = this->getNeighborsIdsOfNode(this->m_currentNodeValue);

  // update Vector
  this->addNeighborsIdsToVector(&currentNodeNeighborsIds);
  this->m_currentNodeIndex = 0;//getIndex(this->m_exploredNodesTree, this->m_currentNodeValue);
  unsigned int currentNodeValue = this->m_exploredNodesTree[this->m_currentNodeIndex];
  this->m_currentNodeIndex++;
  currentNodeValue = this->m_exploredNodesTree[this->m_currentNodeIndex];

  // check if there are more nodes to explore
  while (this->m_connectionsIdsMatrix.size() > this->m_currentNodeIndex) {
    // get neighbors of node
    currentNodeNeighborsIds = this->getNeighborsIdsOfNode(currentNodeValue);
    // update Vector
    this->addNeighborsIdsToVectorWithoutRepetition(&currentNodeNeighborsIds);
    this->m_currentNodeIndex++;
    currentNodeValue = this->m_exploredNodesTree[this->m_currentNodeIndex];
  }

  std::cout << "\nFinal explored nodes list {";
  for (size_t i = 0; i < this->m_exploredNodesTree.size(); i++) {
    std::cout << this->m_exploredNodesTree[i] << ", ";
  }
  std::cout << "}\n";
}

/*
*
*/
void BreadthFirstSearch::findAllPathsAndRankThemByLength()
{
  // calculate paths and distances
  // get shortest path
}

/*----------------------------------- Private Member Functions (low level) -----------------------------*/

/*
*
*/
void BreadthFirstSearch::setGraphConnectionsIds(std::vector<std::vector<unsigned int>> *connectionsIdsMatrix)
{
  this->m_connectionsIdsMatrix = *connectionsIdsMatrix;
}

/*
*
*/
const std::vector<unsigned int> BreadthFirstSearch::getNeighborsIdsOfNode(unsigned int nodeIndex)
{
  return this->m_connectionsIdsMatrix.at(nodeIndex);
}

/*
*
*/
void BreadthFirstSearch::addNeighborsIdsToVector(std::vector<unsigned int> *neighborsIds)
{
  this->m_exploredNodesTree.insert(this->m_exploredNodesTree.end(), neighborsIds->begin(), neighborsIds->end());
}

/*
* If any of current node's neighbors is on the list of explored nodes, then append them to it.
*/
void BreadthFirstSearch::addNeighborsIdsToVectorWithoutRepetition(std::vector<unsigned int> *neighborsIds)
{
  int index = -1;
  for (size_t i = 0; i < neighborsIds->size(); i++) {
    index = getIndex(this->m_exploredNodesTree, neighborsIds->at(i));
    if (index == -1) {
      this->m_exploredNodesTree.push_back(neighborsIds->at(i));
    }
  }
}

/*
*
*/
void BreadthFirstSearch::goToNextNode()
{
  // get the index of m_currentNode in m_exploredNodesTree
  // get the nodeId of the next element in m_exploredNodesTree
  // set m_currentNode to that new value
}

/*
*
*/
void BreadthFirstSearch::getShortestPath()
{

}

/*
*
*/
int BreadthFirstSearch::getIndex(std::vector<unsigned int> v, unsigned int target)
{
  int retVal_index = -1;
  for (size_t i = 0; i < v.size(); i++) {
    if (v.at(i) == target) {
      retVal_index = i;
      break;
    }
  }
  return retVal_index;
}
