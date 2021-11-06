#include "Graph.h"
#include "Graph_Cfg.h"
#include <iostream>

/*
*
*/
Graph::Graph()
{
  m_adjacentMatrix = adjacentMatrix_Cfg_1;
}

/*
*
*/
Graph::~Graph()
{

}

/*
* Getter function for the private member variable m_adjacentMatrix.
*/
std::vector<std::vector<unsigned int>> Graph::getGraph()
{
  return this->m_adjacentMatrix;
}

/*
* This function will print all the connections of the adjacent matrix.
*/
void Graph::printGraph()
{
  std::string adjacentMatrix_str("");
  std::cout << "Graph:\n";
  for (size_t i = 0; i < this->m_adjacentMatrix.size(); i++) {
    adjacentMatrix_str += "Node#" + std::to_string(i) + "'s connections: ";
    for (size_t j = 0; j < this->m_adjacentMatrix.at(i).size(); j++) {
      adjacentMatrix_str += std::to_string(this->m_adjacentMatrix.at(i).at(j)) + " ";
    }
    adjacentMatrix_str += "\n";
  }
  std::cout << adjacentMatrix_str;
}

/*
* This function takes in an input parameter that corresponds to the node
* for which it will return a vector containing the connections to the rest of the nodes.
*/
const std::vector<unsigned int> Graph::getNeighborsOfNode(unsigned int nodeIndex)
{
  // std::vector<unsigned int> nodeNeighbors;
  // for (unsigned int i = 0; i < this->m_adjacentMatrix.at(nodeIndex).size; i++) {
  //   nodeNeighbors.push_back(i);
  // }
  return this->m_adjacentMatrix.at(nodeIndex);
}

/*
*
*/
void Graph::printNeighborsOfNode(unsigned int nodeIndex)
{
  std::vector<unsigned int> nodeNeighbors = this->getNeighborsOfNode(nodeIndex);
  std::string nodeNeighbors_str("");
  for (size_t i = 0; i < nodeNeighbors.size(); i++) {
    nodeNeighbors_str += std::to_string(nodeNeighbors.at(i)) + " ";
  }
  std::cout << "Node#" << std::to_string(nodeIndex) << "'s connections: " << nodeNeighbors_str << std::endl;
}
