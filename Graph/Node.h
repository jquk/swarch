#include <vector>

/*
*
*/
class Node {
public:
  // constructor
  Node(unsigned int layer);
  // destructor
  ~Node();

  // public member variables

  // public member functions
  bool hasBeenExplored();
  unsigned int getLayerId();
  void setLayerId(unsigned int layerId);
  std::vector<unsigned int> getNeighbors();
  void setNeighbors(std::vector<unsigned int> neighbors);

private:
  // private member variables
  bool m_explored;
  unsigned int m_layer;
  std::vector<unsigned int> m_neighbors;
  // private member functions
};
