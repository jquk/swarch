#include <vector>

/*
*
*/
class Node {
public:
  // constructor
  Node();
  Node(unsigned int nodeId);
  Node(unsigned int nodeId, unsigned int layerId);
  // destructor
  ~Node();

  // public member variables

  // public member functions
  bool getExplored();
  void setExplored(bool explored);
  unsigned int getNodeId();
  void setLayerId(unsigned int layerId);
  void setNodeId(unsigned int nodeId);
  std::vector<unsigned int> getNeighbors();
  void setNeighbors(std::vector<unsigned int> neighbors);

private:
  // private member variables
  bool m_nodeId;
  unsigned int m_layerId;
  std::vector<unsigned int> m_neighbors;
  bool m_explored;
  // private member functions
};
