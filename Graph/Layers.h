#include <vector>
#include "Layer.h"

/*
*
*/
class Layers {
public:
  // constructor
  Layers();
  // destructor
  ~Layers();

  // public member variables

  // public member functions
  // public member functions: get metadata of layers
  unsigned int getNumberOfLayers();
  unsigned int getNumberOfNodes();
  unsigned int getNumberOfNodesInLayer(unsigned int layerId);
  unsigned int getNumberOfNodesInLayer(Layer *layer);
  std::vector<Layer> getLayers();
  void printLayer(unsigned int layerId);
  void printLayer(Layer *layer);
  void printLayers();
  // public member functions: get layer
  Layer getLayerById(unsigned int layerId);
  Layer getLayerByNodeId(unsigned int nodeId);//returns the layer that the node belongs to
  // public member functions: add/remove layers
  void pushBackLayer();//add a new layer at the end of the vector
  int popFrontLayer();//remove the first layer of the vector
  // public member functions: operations with nodes
  void addNode(unsigned int nodeId);//adds a node to the last layer
  void addNode(Node *node);//adds a node to the last layer
  int removeNode(unsigned int nodeId);//removes a node from the last layer
  int addNodeToLayer(unsigned int nodeId, unsigned int layerId);
  int removeNodeFromLayer(unsigned int nodeId, unsigned int layerId);
  Node getNodeById(unsigned int nodeId);
  std::vector<unsigned int> getNodesIds();
  std::vector<Node> getNodes();
  std::vector<unsigned int> getNodesIdsOfLayer(unsigned int layerId);
  std::vector<Node> getNodesOfLayer(unsigned int layerId);
  void addNodesIds(std::vector<unsigned int> nodesIds);//add several nodes to the last layer
  void addNodes(std::vector<Node> *nodes);//add several nodes to the last layer
  void removeNodesByIds(std::vector<unsigned int> nodesIds);
  void removeNodes(std::vector<Node> *nodes);

private:
  // private member variables
  std::vector<Layer> m_layers;
  // private member functions
};
