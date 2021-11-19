#include "Node.h"

/*
*
*/
Node::Node()
{

}

/*
*
*/
Node::Node(unsigned int layerId)
: m_layerId(layerId)
{

}

/*
*
*/
Node::~Node()
{

}

/*
*
*/
bool Node::getExplored()
{
  return this->m_explored;
}

/*
*
*/
void Node::setExplored(bool explored)
{
  this->m_explored = explored;
}

/*
*
*/
unsigned int Node::getNodeId()
{
  return this->m_nodeId;
}

/*
*
*/
void Node::setLayerId()
{

}

/*
*
*/
void Node::setNodeId(unsigned int nodeId)
{

}

/*
*
*/
std::vector<unsigned int> Node::getNeighbors()
{
  std::vector<unsigned int> retVal_neighbors = {};
  return retVal_neighbors;
}

/*
*
*/
void Node::setNeighbors(std::vector<unsigned int> neighbors)
{

}
