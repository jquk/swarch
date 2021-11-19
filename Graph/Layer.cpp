#include "Layer.h"
#include <algorithm>//for the std::find() function

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
  this->m_nodes.push_back(node);
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
  for (size_t i = 0; i < this->m_nodes.size(); i++) {
    nodes.push_back(this->m_nodes.at(i).getNodeId());
  }
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
unsigned int Layer::getNumberOfNodes()
{
  return this->m_nodes.size();
}

/*
*
*/
void Layer::addNodesIds(std::vector<unsigned int> nodesIds)
{
  for (size_t i = 0; i < nodesIds.size(); i++) {
    Node node(nodesIds.at(i));
    this->m_nodes.push_back(node);
  }
}

/*
*
*/
void Layer::addNodes(std::vector<Node> *nodes)
{
  for (size_t i = 0; i < nodes->size(); i++) {
    this->m_nodes.push_back(nodes->at(i));
  }
}

/*
*
*/
void Layer::removeNodesByIds(std::vector<unsigned int> nodesIds)
{
  // for (size_t i = 0; i < nodesIds.size(); i++) {
  //   for (size_t j = 0; j < this->m_nodes.size(); j++) {
  //     if (nodesIds.at(i) == this->m_nodes.at(j).getNodeId()) {
  //       this->m_nodes.erase(&this->m_nodes.at(j));
  //     }
  //   }
  // }
}

/*
*
*/
void Layer::removeNodes(std::vector<Node> *nodes)
{
  // for (size_t i = 0; i < nodes->size(); i++) {
  //   unsigned int *p_node = std::find(this->m_nodes.begin(), this->m_nodes.end(), nodes->at(i));
  //   if (p_node) {
  //     this->m_nodes.erase(p_node);
  //   }
  // }
}

/*
*
*/
void Layer::removeNodeById(unsigned int nodeId)
{
  // unsigned int *p_node = std::find(this->m_nodes.begin(), this->m_nodes.end(), nodeId);
  // if (p_node) {
  //   this->m_nodes.erase(p_node);
  // }
}

/*
*
*/
void Layer::removeNode(Node node)
{
  // Node *p_node = std::find(this->m_nodes.begin(), this->m_nodes.end(), node);
  // this->m_nodes.erase(p_node);

  // auto it = std::find(this->m_nodes.begin(), this->m_nodes.end(), node);
  // if (it == this->m_nodes.end())
  // {
  //   // name not in vector
  // } else
  // {
  //   auto index = std::distance(this->m_nodes.begin(), it);
  //   this->m_nodes.erase(this->m_nodes.begin() + index);
  // }
}
