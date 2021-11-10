#include <queue>
/*
* Implementation of the Breadth First Search algorithm.
*/
class BreadthFirstSearch {
public:
  // constructor
  BreadthFirstSearch();
  // destructor
  ~BreadthFirstSearch();

  // member functions

private:
  // member variables
  std::queue<int>m_nodes;
};
