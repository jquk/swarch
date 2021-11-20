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
: m_inputs({0, 0, connectionsIdsMatrix})
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
  this->findPaths();
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
  this->m_inputs.startNode = startNode;
  this->m_inputs.targetNode = targetNode;
  this->m_currentState.nodeValue = startNode;
  this->m_currentState.nodeIndex = 0;
}

/*
*
*/
void BreadthFirstSearch::fillVector()
{
  std::vector<unsigned int> currentNodeNeighborsIds = {this->m_inputs.startNode};//ensure that the starting node is the first, for a better sorting
  this->addNeighborsIdsToVector(&currentNodeNeighborsIds);

  // get neighbors of node
  currentNodeNeighborsIds = this->getNeighborsIdsOfNode(this->m_currentState.nodeValue);

  // update Vector
  this->addNeighborsIdsToVector(&currentNodeNeighborsIds);
  unsigned int currentNodeValue = this->m_currentState.exploredNodesTree[this->m_currentState.nodeIndex];
  this->m_currentState.nodeIndex++;
  currentNodeValue = this->m_currentState.exploredNodesTree[this->m_currentState.nodeIndex];

  // check if there are more nodes to explore
  while (this->m_inputs.connectionsIdsMatrix.size() > this->m_currentState.nodeIndex) {
    // get neighbors of node
    currentNodeNeighborsIds = this->getNeighborsIdsOfNode(currentNodeValue);
    // update Vector
    this->addNeighborsIdsToVectorWithoutRepetition(&currentNodeNeighborsIds);
    this->m_currentState.nodeIndex++;
    currentNodeValue = this->m_currentState.exploredNodesTree[this->m_currentState.nodeIndex];
  }

  std::cout << "Final explored nodes list {";
  for (size_t i = 0; i < this->m_currentState.exploredNodesTree.size(); i++) {
    std::cout << this->m_currentState.exploredNodesTree[i] << ", ";
  }
  std::cout << "}\n";
}

/*
* Calculate paths and distances:
* Strategy: move forward and backward in each explored patth.
* When a dead-end or a repeated node is found,
* then must go back in the path until a node with other non-explored options is found,
* in which case the vector is copied until that node, before resuming the exploration.
* Note that if the path in scope reaches a steps count larger than a previous valid path,
* then the exploration of that path shall stop to save time.
*/
void BreadthFirstSearch::findPaths()
{
  // calculate paths and distances
  // get shortest path
  // this->m_outputs.pathsToTarget
  int ctr = 0;
  this->m_currentState.nodeValue = this->m_inputs.startNode;
  std::vector<unsigned int> tmpPath = {this->m_inputs.startNode};
  std::vector<unsigned int> tmpExploredNodes = {};
  std::vector<unsigned int> neighborsIds = {};
  unsigned int neighborId = 0;
  int indexOfNeighborInTmpPath = -2;
  int indexOfNeighborInExploredNodesTreeOld = -2;
  int indexOfNeighborInExploredNodesTreeNew = -2;
  bool targetFound = false;

  while ((ctr < 30) && (!targetFound)) {
    ctr++;
    neighborsIds = getNeighborsIdsOfNode(this->m_currentState.nodeValue);

    std::cout << "\nnode_" << this->m_currentState.nodeValue << "'s neighborsIds = {";
    for (size_t i = 0; i < neighborsIds.size(); i++) {
      std::cout << neighborsIds.at(i) << ", ";
    }
    std::cout << "}\n";

    for (size_t i = 0; i < neighborsIds.size(); i++) {
      // if the i-th node is not in the tmpPath, then append it.
      std::cout << "tmpPath = {";
      for (size_t i = 0; i < tmpPath.size(); i++) {
        std::cout << tmpPath.at(i) << ", ";
      }
      std::cout << "}\n";

      neighborId = neighborsIds.at(i);
      std::cout << "  neighborId_" << neighborId << "\n";
      indexOfNeighborInTmpPath = getIndex(tmpPath/*tmpExploredNodes*/, neighborId);
      std::cout << "  indexOfNeighborInTmpPath_" << indexOfNeighborInTmpPath << "\n";
      indexOfNeighborInExploredNodesTreeNew = getIndex(this->m_currentState.exploredNodesTree, neighborId);
      // std::cout << "indexOfNeighborInExploredNodesTreeNew = " << indexOfNeighborInExploredNodesTreeNew << ", neighborId = " << neighborId << "\n";

      // if ((neighborId == 2) || (neighborId == 6) || (neighborId == 11)) {
      //   continue;
      // }

      // append it only if it is not already in, and if its index is not smaller (i.e. not going back in the layers)
      if (indexOfNeighborInTmpPath < 0) {
        std::cout << "    - New:\n";
        bool isInAHigherLayer = (indexOfNeighborInExploredNodesTreeOld < indexOfNeighborInExploredNodesTreeNew);
        if (isInAHigherLayer) {
          std::cout << "    - push\n";
          tmpPath.push_back(neighborId);
          tmpExploredNodes.push_back(neighborId);
          this->m_currentState.nodeValue = neighborId;
          indexOfNeighborInExploredNodesTreeOld = indexOfNeighborInExploredNodesTreeNew;
          break;
        } else {
          std::cout << "    - reject and continue (it is in a lower layer).\n";
          continue;
        }
      } else if(indexOfNeighborInTmpPath >= 0) {
        std::cout << "    - reject (not new) and continue.\n";
        // continue;
      // } else if (((-1 != indexOfNeighborInTmpPath) || (neighborsIds.size() == 0)) && (neighborId != this->m_inputs.targetNode)) {
        // roll backward if the node is already in, or has no neighbors, and is not the target node
        // roll backward until it finds connections that are not in the tmpPath.
        std::cout << "    - reject (not new) and roll back.\n";
        std::cout << "    - this->m_currentState.nodeValue: " << this->m_currentState.nodeValue << "\n";

        int tmpIndex = getIndex(tmpPath, this->m_currentState.nodeValue);
        if (tmpIndex > 0) {
          bool newNeighborPushed = false;
          while ((!newNeighborPushed) && (tmpIndex > 1) && (!targetFound)) {
            std::cout << "    - Rolling back in tmpPath: from {idx, val}={" << tmpIndex << ", " << tmpPath.at(tmpIndex) << "}, to {" << (tmpIndex - 1) << ", " << tmpPath.at(tmpIndex - 1) << "}.\n";
            tmpIndex = getIndex(tmpPath, this->m_currentState.nodeValue);
            tmpIndex--;
            this->m_currentState.nodeValue = tmpPath.at(tmpIndex);
            std::cout << "    - this->m_currentState.nodeValue: " << this->m_currentState.nodeValue << "\n";
            tmpPath.pop_back();
            neighborsIds = getNeighborsIdsOfNode(this->m_currentState.nodeValue);
            this->m_currentState.nodeValue = tmpPath.at(tmpIndex - 1);

            for (size_t i = 0; i < neighborsIds.size(); i++) {
              neighborId = neighborsIds.at(i);
              std::cout << "______neighborId = " << neighborsIds.at(i) << "\n";
              if (-1 == getIndex(tmpExploredNodes, neighborId)) {
                std::cout << "______push_" << neighborId << "\n";
                tmpPath.push_back(neighborId);
                tmpExploredNodes.push_back(neighborId);
                this->m_currentState.nodeValue = neighborId;
                newNeighborPushed = true;
                if (tmpPath.at((tmpPath.size() - 1)) == this->m_inputs.targetNode) {
                  std::cout << "\nTARGET_NODE_REACHED 1111\n";
                  targetFound = true;
                  break;
                }
              }
            }
            if (tmpPath.at((tmpPath.size() - 1)) == this->m_inputs.targetNode) {
              std::cout << "\nTARGET_NODE_REACHED 2222\n";
              targetFound = true;
              break;
            }
          }
          // break;
        } else {
          std::cout << "Not rolling back tm_currentState.nodeValue because the index is 0.\n";
        }
        // if (i > 0) {
        //   i--;
        //   this->m_currentState.nodeValue = neighborsIds.at(i);
        //   std::cout << "m_currentState.nodeValue = " << this->m_currentState.nodeValue << "\n";
        //   break;
        // }

        // int j = i;
        // do {
        //   if (j > 0) {
        //     j--;
        //   }
        //   // roll back one position in the tmpPath
        //   std::cout << "tmpPath.at(" << j << ") = " << tmpPath.at(j) << "\n";
        //   neighborsIds = getNeighborsIdsOfNode(tmpPath.at(j));
        //   // for each neighbor, check if they are new
        //   for (size_t k = 0; k < neighborsIds.size(); k++) {
        //     neighborId = neighborsIds.at(k);
        //     // std::cout << "________" << neighborId << "\n";
        //     indexOfNeighborInTmpPath = getIndex(tmpPath, neighborId);
        //     // if a new neighbor-node is found, then take it as currentNodeValue
        //     if (-1 == indexOfNeighborInTmpPath) {
        //       std::cout << "_____________________\n\n";
        //       this->m_currentState.nodeValue = neighborId;
        //       break;
        //     }
        //   }
        // } while((-1 != indexOfNeighborInTmpPath) && (j > 0));

      }
    }

    if (tmpPath.at((tmpPath.size() - 1)) == this->m_inputs.targetNode) {
      std::cout << "\nTARGET_NODE_REACHED 9999\n";
      targetFound = true;
      break;
    }
    // this->m_outputs.pathsToTarget.push_back()
  }

  std::cout << "ctr = " << ctr << "\n";
  std::cout << "\ntmpPath = {";
  for (size_t i = 0; i < tmpPath.size(); i++) {
    std::cout << tmpPath.at(i) << ", ";
  }
  std::cout << "}";
}

/*
*
*/
void BreadthFirstSearch::findAllPaths()
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
  this->m_inputs.connectionsIdsMatrix = *connectionsIdsMatrix;
}

/*
*
*/
const std::vector<unsigned int> BreadthFirstSearch::getNeighborsIdsOfNode(unsigned int nodeIndex)
{
  return this->m_inputs.connectionsIdsMatrix.at(nodeIndex);
}

/*
*
*/
void BreadthFirstSearch::addNeighborsIdsToVector(std::vector<unsigned int> *neighborsIds)
{
  this->m_currentState.exploredNodesTree.insert(this->m_currentState.exploredNodesTree.end(), neighborsIds->begin(), neighborsIds->end());
}

/*
* If any of current node's neighbors is on the list of explored nodes, then append them to it.
*/
void BreadthFirstSearch::addNeighborsIdsToVectorWithoutRepetition(std::vector<unsigned int> *neighborsIds)
{
  int index = -1;
  for (size_t i = 0; i < neighborsIds->size(); i++) {
    index = getIndex(this->m_currentState.exploredNodesTree, neighborsIds->at(i));
    if (index == -1) {
      this->m_currentState.exploredNodesTree.push_back(neighborsIds->at(i));
    }
  }
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
