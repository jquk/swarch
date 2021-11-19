#include <vector>
#include "Node.h"

/*
*
*/
class Layer {
public:
  // constructor
  Layer(unsigned int layerId);
  Layer(unsigned int layerId, std::vector<int> nodesIds);
  Layer(unsigned int layerId, std::vector<Node> nodes);
  // destructor
  ~Layer();

  // public member variables

  // public member functions
  unsigned int getLayerId();
  void addNodeId(unsigned int nodeId);
  void addNode(Node node);
  Node getNodeById(unsigned int nodeId);
  std::vector<unsigned int> getNodesIds();
  std::vector<Node> getNodes();
  void addNodesIds(std::vector<unsigned int> nodesIds);
  void addNodes(std::vector<Node> nodes);
  void removeNodesByIds(std::vector<unsigned int> nodesIds);
  void removeNodes(std::vector<Node> nodes);

private:
  // private member variables
  unsigned int m_layerId;
  std::vector<Node> m_nodes;
  // private member functions
};
