#include "Layers.h"

/*
*
*/
Layers::Layers()
{

}

/*
*
*/
Layers::~Layers()
{

}

// public member functions
// public member functions: get metadata of layers

/*
*
*/
unsigned int Layers::getNumberOfLayers()
{
  return this->m_layers.size();
}

/*
*
*/
unsigned int Layers::getNumberOfNodes()
{
  unsigned int retVal_numberOfNodes = 0;
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    retVal_numberOfNodes += this->m_layers.at(i).getNumberOfNodes();
  }
  return retVal_numberOfNodes;
}

/*
*
*/
unsigned int Layers::getNumberOfNodesInLayer(unsigned int layerId)
{
  unsigned int retVal_numberOfNodes = 0;
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    if (this->m_layers.at(i).getLayerId() == layerId) {
      retVal_numberOfNodes = this->m_layers.at(i).getNumberOfNodes();
    }
  }
  return retVal_numberOfNodes;
}

/*
*
*/
unsigned int Layers::getNumberOfNodesInLayer(Layer *layer)
{
  unsigned int retVal_numberOfNodes = 0;
  unsigned int layerId = layer->getLayerId();
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    if (this->m_layers.at(i).getLayerId() == layerId) {
      retVal_numberOfNodes = this->m_layers.at(i).getNumberOfNodes();
    }
  }
  return retVal_numberOfNodes;
}

/*
*
*/
std::vector<Layer> Layers::getLayers()
{
  return this->m_layers;
}

/*
*
*/
void Layers::printLayer(unsigned int layerId)
{

}

/*
*
*/
void Layers::printLayer(Layer *layer)
{

}

/*
*
*/
void Layers::printLayers()
{

}

// public member functions: get layer

/*
*
*/
Layer *Layers::getLayerById(unsigned int layerId)
{
  Layer *retVal_layer;
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    if (this->m_layers.at(i).getLayerId() == layerId) {
      retVal_layer = &this->m_layers.at(i);
    }
  }
  return retVal_layer;
}

/*
* returns the layer that the node belongs to
*/
// Layer *getLayerByNodeId(unsigned int nodeId)
// {
//
// }

// public member functions: add/remove layers

/*
*
*/
void Layers::addLayer()
{
  if (this->m_layers.size() > 0) {
    Layer layer(this->m_layers.at(this->m_layers.size() - 1).getLayerId() + 1);
    this->m_layers.push_back(layer);
  } else {
    Layer layer(0);
    this->m_layers.push_back(layer);
  }
}

/*
* add a new layer at the end of the vector
*/
void Layers::pushBackLayer(Layer layer)
{
  this->m_layers.push_back(layer);
}

/*
* remove the first layer of the vector
*/
// int Layers::popFrontLayer()
// {
//   return -1;
// }

// public member functions: operations with nodes

/*
* adds a node to the last layer
*/
void Layers::addNode(unsigned int nodeId)
{
  this->m_layers.at(this->m_layers.size()).addNodeId(nodeId);
}

/*
* adds a node to the last layer
*/
void Layers::addNode(Node node)
{
  this->m_layers.at(this->m_layers.size()).addNode(node);
}

/*
* removes a node from the last layer
*/
// int Layers::removeNode(unsigned int nodeId)
// {
//
// }

/*
*
*/
void Layers::addNodeToLayer(unsigned int nodeId, unsigned int layerId)
{
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    if (this->m_layers.at(i).getLayerId() == layerId) {
      this->m_layers.at(i).addNodeId(nodeId);
    }
  }
}

/*
*
*/
// int Layers::removeNodeFromLayer(unsigned int nodeId, unsigned int layerId)
// {
//
// }

/*
*
*/
// Node Layers::getNodeById(unsigned int nodeId)
// {
//
// }

/*
*
*/
std::vector<unsigned int> Layers::getNodesIds()
{
  std::vector<unsigned int> retVal_nodesIds;
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    for (size_t j = 0; j < this->m_layers.at(i).getNumberOfNodes(); j++) {
      retVal_nodesIds.push_back(this->m_layers.at(i).getNodes().at(j).getNodeId());
    }
  }
  return retVal_nodesIds;
}

/*
*
*/
std::vector<Node> Layers::getNodes()
{
  std::vector<Node> retVal_nodes;
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    for (size_t j = 0; j < this->m_layers.at(i).getNumberOfNodes(); j++) {
      retVal_nodes.push_back(this->m_layers.at(i).getNodes().at(j));
    }
  }
  return retVal_nodes;
}

/*
*
*/
std::vector<unsigned int> Layers::getNodesIdsOfLayer(unsigned int layerId)
{
  std::vector<unsigned int> retVal_nodesIds;
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    if (this->m_layers.at(i).getLayerId() == layerId) {
      for (size_t j = 0; j < this->m_layers.at(i).getNumberOfNodes(); j++) {
        retVal_nodesIds.push_back(this->m_layers.at(i).getNodes().at(j).getNodeId());
      }
    }
  }
  return retVal_nodesIds;
}

/*
*
*/
std::vector<Node> Layers::getNodesOfLayer(unsigned int layerId)
{
  std::vector<Node> retVal_nodes;
  for (size_t i = 0; i < this->m_layers.size(); i++) {
    if (this->m_layers.at(i).getLayerId() == layerId) {
      for (size_t j = 0; j < this->m_layers.at(i).getNumberOfNodes(); j++) {
        retVal_nodes.push_back(this->m_layers.at(i).getNodes().at(j));
      }
    }
  }
  return retVal_nodes;
}

/*
* add several nodes to the last layer
*/
void Layers::addNodesIds(std::vector<unsigned int> nodesIds)
{

}

/*
* add several nodes to the last layer
*/
void Layers::addNodes(std::vector<Node> *nodes)
{

}

/*
*
*/
void Layers::removeNodesByIds(std::vector<unsigned int> nodesIds)
{

}

/*
*
*/
void Layers::removeNodes(std::vector<Node> *nodes)
{

}
