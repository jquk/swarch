#include "Layer.h"

/*
*
*/
Layer::Layer(unsigned int layerId)
: m_layerId(layerId)
{

}

/*
*
*/
Layer::~Layer()
{

}

/*
*
*/
unsigned int Layer::getLayerId()
{
  return this->m_layerId;
}

/*
*
*/
void Layer::addNodeId(unsigned int nodeId)
{

}

/*
*
*/
void Layer::addNode(Node node)
{

}

/*
*
*/
Node Layer::getNodeById(unsigned int nodeId)
{
  Node retVal_node;
  for (size_t i = 0; i < this->m_nodes.size(); i++) {
    if(this->m_nodes.at(i).getNodeId() == nodeId) {
      retVal_node.setNodeId(nodeId);
    }
  }
  return retVal_node;
}

/*
*
*/
std::vector<unsigned int> Layer::getNodesIds()
{
  std::vector<unsigned int> nodes;
  return nodes;
}

/*
*
*/
std::vector<Node> Layer::getNodes()
{
  return this->m_nodes;
}

/*
*
*/
void Layer::addNodesIds(std::vector<unsigned int> nodesIds)
{

}

/*
*
*/
void Layer::addNodes(std::vector<Node> nodes)
{

}

/*
*
*/
void Layer::removeNodesByIds(std::vector<unsigned int> nodesIds)
{

}

/*
*
*/
void Layer::removeNodes(std::vector<Node> nodes)
{

}
