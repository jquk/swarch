#include "Graph_Cfg.h"
#include "Graph.h"
#include <iostream>

/*
*
*/
Graph::Graph()
{

}

/*
*
*/
Graph::Graph(std::vector<std::vector<unsigned int>>connectionsMatrix)
: m_connectionsMatrix(connectionsMatrix)
{
  // Using the fill constructor to construct a vector of vectors
  // vector<vector<int>> mat(R, vector<int>(C));
  this->calculateGraphConnectionsIds();
}

/*
*
*/
Graph::~Graph()
{

}

/*
* This function allows the program user to select different graphs without recompiling.
* When calling the program with the command line interface, the parameter passed for the Graph Id,
* will select the corresponding case of the switch block.
* connectionsMatrix_Cfg is a 3D matrix, containing 2D graphs, in the Graph_Cfg.h file.
*/
void Graph::setGraph(unsigned int graphId)
{
  switch (graphId) {
    case 1:
    {
      this->m_connectionsMatrix = connectionsMatrix_Cfg[1];
      break;
    }
    case 2:
    {
      this->m_connectionsMatrix = connectionsMatrix_Cfg[2];
      break;
    }
    default:
    {
      this->m_connectionsMatrix = connectionsMatrix_Cfg[0];
    }
  }
  this->calculateGraphConnectionsIds();
}

/*
* Getter function for the private member variable m_connectionsMatrix.
*/
std::vector<std::vector<unsigned int>> Graph::getGraphConnections()
{
  return this->m_connectionsMatrix;
}

/*
* This function will print all the connections of the connection matrix.
*/
void Graph::printGraphConnections()
{
  std::string connectionMatrix_str("");
  std::cout << "Adjacency matrix:\n";
  // For each row (node), iterate also over the columns (connections to other nodes)
  for (size_t i = 0; i < this->m_connectionsMatrix.size(); i++) {
    connectionMatrix_str += "Node#" + std::to_string(i) + "'s connections: ";
    for (size_t j = 0; j < this->m_connectionsMatrix.at(i).size(); j++) {
      connectionMatrix_str += std::to_string(this->m_connectionsMatrix.at(i).at(j)) + " ";
    }
    connectionMatrix_str += "\n";
  }
  std::cout << connectionMatrix_str;
}

/*
* Getter function for the private member variable m_connectionsIdsMatrix.
*/
void Graph::calculateGraphConnectionsIds()
{
  if (this->m_connectionsIdsMatrix.empty()) {
    this->m_connectionsIdsMatrix.resize(this->m_connectionsMatrix.size());
    // For each row (node), iterate also over the columns (connections to other nodes)
    // Here the index j corresponds to the connected neighbor's ID.
    for (size_t i = 0; i < this->m_connectionsMatrix.size(); i++) {
      for (size_t j = 0; j < this->m_connectionsMatrix.at(i).size(); j++) {
        // connectionMatrix_str += std::to_string(this->m_connectionsMatrix.at(i).at(j)) + " ";
        if (this->m_connectionsMatrix.at(i).at(j) == 1) {
          this->m_connectionsIdsMatrix.at(i).push_back(j);
        }
      }
    }
  }
}

/*
* Getter function for the private member variable m_connectionsIdsMatrix.
*/
std::vector<std::vector<unsigned int>> Graph::getGraphConnectionsIds()
{
  return this->m_connectionsIdsMatrix;
}

/*
*
*/
void Graph::printGraphConnectionsIds()
{
  std::string connectionsIdsMatrix_str("");
  std::cout << "Adjacency list:\n";
  for (size_t i = 0; i < this->m_connectionsIdsMatrix.size(); i++) {
    connectionsIdsMatrix_str += "Node#" + std::to_string(i) + "'s connections: { ";
    for (size_t j = 0; j < this->m_connectionsIdsMatrix.at(i).size(); j++) {
      connectionsIdsMatrix_str += std::to_string(this->m_connectionsIdsMatrix.at(i).at(j)) + " ";
    }
    connectionsIdsMatrix_str += "}\n";
  }
  std::cout << connectionsIdsMatrix_str;
}

/*
* This function takes in an input parameter that corresponds to the node
* for which it will return a vector containing the connections to the rest of the nodes.
*/
const std::vector<unsigned int> Graph::getNeighborConnectionsOfNode(unsigned int nodeIndex)
{
  // std::vector<unsigned int> nodeNeighbors;
  // for (unsigned int i = 0; i < this->m_connectionsMatrix.at(nodeIndex).size; i++) {
  //   nodeNeighbors.push_back(i);
  // }
  return this->m_connectionsMatrix.at(nodeIndex);
}

/*
*
*/
const std::vector<unsigned int> Graph::getNeighborsIdsOfNode(unsigned int nodeIndex)
{
  return this->m_connectionsIdsMatrix.at(nodeIndex);
}

/*
*
*/
void Graph::printNeighborConnectionsOfNode(unsigned int nodeIndex)
{
  std::vector<unsigned int> nodeNeighbors = this->getNeighborConnectionsOfNode(nodeIndex);
  std::string nodeNeighborsConnections_str("");
  std::string nodeNeighborIds_str("");
  for (size_t i = 0; i < nodeNeighbors.size(); i++) {
    nodeNeighborsConnections_str += std::to_string(nodeNeighbors.at(i)) + " ";
  }
  std::cout << "Node#" << std::to_string(nodeIndex) << "'s neighbor connections = { " << nodeNeighborsConnections_str << "}" << std::endl;
}

/*
*
*/
void Graph::printNeighborIdsOfNode(unsigned int nodeIndex)
{
  std::vector<unsigned int> nodeNeighbors = this->getNeighborsIdsOfNode(nodeIndex);
  std::string nodeNeighborIds_str("");
  for (size_t i = 0; i < nodeNeighbors.size(); i++) {
    nodeNeighborIds_str += std::to_string(nodeNeighbors.at(i)) + " ";
  }
  std::cout << "Node#" << std::to_string(nodeIndex) << "'s neighbor IDs = { " << nodeNeighborIds_str << "}" << std::endl;
}

/*
*
*/
std::vector<unsigned int> Graph::getShortestPath(GraphAlgorithm algorithm, unsigned int startingNode, unsigned int targetNode)
{
  std::vector<unsigned int> retVal_shortestPath;

  switch (algorithm) {
    case BREADTH_FIRST_SEARCH:
      {
        BreadthFirstSearch breadthFirstSearch(this->m_connectionsIdsMatrix);
        retVal_shortestPath = breadthFirstSearch.getShortestPath(startingNode, targetNode);
        break;
      }
    case DEPTH_FIRST_SEARCH:
      {
        break;
      }
    default:
      {
      }
  }

  return retVal_shortestPath;
}
