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
Node::Node(unsigned int nodeId, unsigned int layerId)
: m_nodeId(nodeId), m_layerId(layerId)
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
void Node::setLayerId(unsigned int layerId)
{
  this->m_layerId = layerId;
}

/*
*
*/
void Node::setNodeId(unsigned int nodeId)
{
  this->m_nodeId = nodeId;
}

/*
*
*/
std::vector<unsigned int> Node::getNeighbors()
{
  return this->m_neighbors;
}

/*
*
*/
void Node::setNeighbors(std::vector<unsigned int> neighbors)
{
  this->m_neighbors = neighbors;
}
