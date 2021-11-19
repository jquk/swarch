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
Layer::Layer(unsigned int layerId, std::vector<int> nodesIds)
: m_layerId(layerId)
{
  for (size_t i = 0; i < nodesIds.size(); i++) {
    this->addNodeId(nodesIds.at(i));
  }
}

/*
*
*/
Layer::Layer(unsigned int layerId, std::vector<Node> nodes)
: m_layerId(layerId), m_nodes(nodes)
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
* Add a node to the last layer.
*/
void Layer::addNodeId(unsigned int nodeId)
{
  Node node(nodeId, this->m_layerId);
  this->m_nodes.push_back(node);
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
