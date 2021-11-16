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
}

/*
*
*/
void BreadthFirstSearch::fillVector()
{
  std::cout << "a) this->m_connectionsIdsMatrix.size(): " << this->m_connectionsIdsMatrix.size() << std::endl;
  std::vector<unsigned int> currentNodeNeighborsIds = {0};
  this->addNeighborsIdsToVector(&currentNodeNeighborsIds);


  std::cout << "\nthis->m_exploredNodesTree.size: " << this->m_exploredNodesTree.size();
  // std::cout << "\nneighborsIdsOfNode_ " << 0 << "_" << this->m_currentNodeValue << " = {";
  std::cout << "\nneighborsIdsOfNode_idx(" << 0 << ")_val(" << this->m_currentNodeValue << ") = {";
  // get neighbors of node
  /*std::vector<unsigned int>*/ currentNodeNeighborsIds = this->getNeighborsIdsOfNode(this->m_currentNodeValue);
  // update Vector
  this->addNeighborsIdsToVector(&currentNodeNeighborsIds);
  unsigned int currentNodeIndex = 0;//getIndex(this->m_exploredNodesTree, this->m_currentNodeValue);
  unsigned int currentNodeValue = this->m_exploredNodesTree[currentNodeIndex];
  // check if there are more nodes to explore
  // std::cout << "    {currentNodeIndex, currentNodeValue} = {" << currentNodeIndex << ", " << currentNodeValue << "}"<< std::endl;
  // this->m_currentNodeValue = currentNodeNeighborsIds[currentNodeIndex];
  currentNodeIndex++;
  currentNodeValue = this->m_exploredNodesTree[currentNodeIndex];


  int ctr = 0;
  // check if there are more nodes to explore
  while ((this->m_connectionsIdsMatrix.size() > currentNodeIndex) && (ctr < 20)) {
    ctr++;
    std::cout << "\nthis->m_exploredNodesTree.size: " << this->m_exploredNodesTree.size();
    std::cout << "\nneighborsIdsOfNode_idx(" << currentNodeIndex << ")_val(" << currentNodeValue << ") = {";
    // get neighbors of node
    currentNodeNeighborsIds = this->getNeighborsIdsOfNode(currentNodeValue);
    // update Vector
    this->addNeighborsIdsToVectorWithoutRepetition(&currentNodeNeighborsIds);
    // currentNodeIndex = getIndex(this->m_exploredNodesTree, this->m_currentNodeValue);
    // std::cout << "    {currentNodeIndex, currentNodeValue} = {" << currentNodeIndex << ", " << currentNodeValue << "}"<< std::endl;
    // this->m_currentNodeValue = currentNodeNeighborsIds[currentNodeIndex];
    currentNodeIndex++;
    currentNodeValue = this->m_exploredNodesTree[currentNodeIndex];
  }

  std::cout << "\n\nFinal explored nodes list {";
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
  // std::cout << "neighborsIdsOfNode_ " << nodeIndex << " = {";
  for (size_t i = 0; i < this->m_connectionsIdsMatrix.at(nodeIndex).size(); i++) {
    std::cout << this->m_connectionsIdsMatrix.at(nodeIndex)[i] << ", ";
  }
  std::cout << "}\n";
  return this->m_connectionsIdsMatrix.at(nodeIndex);
}

/*
*
*/
void BreadthFirstSearch::addNeighborsIdsToVector(std::vector<unsigned int> *neighborsIds)
{
  // i_vec1.insert(i_vec1.end(), i_vec2.begin(), i_vec2.end());
  // this->m_exploredNodesTree.push(*neighborsIds);
  this->m_exploredNodesTree.insert(this->m_exploredNodesTree.end(), neighborsIds->begin(), neighborsIds->end());
  std::cout << "    m_exploredNodesTree: { ";
  for (size_t i = 0; i < this->m_exploredNodesTree.size(); i++) {
    std::cout << this->m_exploredNodesTree[i] << ", ";
  }
  std::cout << "}, size(): " << this->m_exploredNodesTree.size() << std::endl;
}

/*
*
*/
void BreadthFirstSearch::addNeighborsIdsToVectorWithoutRepetition(std::vector<unsigned int> *neighborsIds)
{
  int index = -1;
  // std::cout << "    neighborsIds.size(): " << neighborsIds->size() << std::endl;
  std::cout << "    non-repeated: { ";


  for (size_t i = 0; i < neighborsIds->size(); i++) {
    index = getIndex(this->m_exploredNodesTree, neighborsIds->at(i));
    if (index == -1) {
      // std::cout << "index = " << index << ", i = " << i << ", push_back(" << neighborsIds->at(i) << ")\n";
      this->m_exploredNodesTree.push_back(neighborsIds->at(i));
      std::cout << neighborsIds->at(i) << ", ";
    }
  }
  std::cout << "}" << std::endl;


  std::cout << "    this->m_exploredNodesTree: { ";
  for (size_t i = 0; i < this->m_exploredNodesTree.size(); i++) {
    std::cout << this->m_exploredNodesTree[i] << ", ";
  }
  std::cout << "}, size(): " << this->m_exploredNodesTree.size() << std::endl;
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
// unsigned int BreadthFirstSearch::getIndex(std::vector<unsigned int> v, unsigned int target)
// {
//   unsigned int retVal_index = -1;
//   for (size_t i = 0; i < v.size(); i++) {
//     if (v[i] == target) {
//       retVal_index = i;
//     }
//   }
//   return retVal_index;
// }

/*
*
*/
// unsigned int BreadthFirstSearch::getIndex(std::vector<unsigned int> v, unsigned int target)
// {
//   // Check if target exists in vector
//   std::vector<unsigned int>::iterator it = std::find(v.begin(), v.end(), target);
//   // If element is found then it returns an iterator to the first element in the given range
//   // that’s equal to given element, else it returns an end of the list.
//   if (it != v.end())
//   {
//     std::cout << "target found" << std::endl;
//   }
//   else
//   {
//     std::cout << "target not found" << std::endl;
//   }
//   // Get index of element from iterator
//   unsigned int index = std::distance(v.begin(), it);
//   return index;
// }

/*
*
*/
int BreadthFirstSearch::getIndex(std::vector<unsigned int> v, unsigned int target)
{
  // std::cout << "\n______________\n";
  // std::cout << "     v.size(): " << v.size() << std::endl;
  // std::cout << "     target: " << target << std::endl;

  int retVal_index = -1;
  for (size_t i = 0; i < v.size(); i++) {
    // std::cout << "        v.at(" << i << "): " << v.at(i) << std::endl;
    if (v.at(i) == target) {
      retVal_index = i;
      break;
    }
  }
  return retVal_index;
}
