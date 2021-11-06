#include <vector>

/*
* At the end of this file, assign the preferred adjacentMatrix_Cfg_<N> to adjacentMatrix_Cfg,
* being adjacentMatrix_Cfg the one that will be used in the algorithms.
*
* 2D matrix representing the connections
* between the graph's nodes (A to E).
* In undirected graphs, the connections don't mean direction, so the matrix must be simetric.
* In directed graphs, the connections indicate the direction, so the matrix could not be simmetric.
* In unweighted graphs, every connection has the same cost, so they are represented with the same value, e.g. 1.
* In weighted graphs, every connection may have a different cost, so they would be represented with different values.
* A graph can be: undirected & unweighted, undirected & weighted, directed & unweighted, directed & weighted.
* Note that in a directed weighted graph, the connection matrix could be filled simmetrically but with different values,
* thus being non-simmetric, meaning that every connection has its opposite, but could have different costs in each direction.
*/

// Take the reference from the picture 'AdjacentMatrix-ex1.png'
// but making it unweighted.
std::vector<std::vector<unsigned int>>adjacentMatrix_Cfg_1 {
     /*{A, B, C, D, E}*/
  /*A*/{0, 1, 0, 1, 0},//A is connected to B, D.
  /*B*/{1, 0, 1, 0, 0},//B is connected to A, C.
  /*C*/{0, 1, 0, 1, 0},//C is connected to B, D.
  /*D*/{1, 0, 1, 0, 0},//D is connected to A, C.
  /*E*/{0, 0, 0, 1, 0}//E is connected to D.
};

std::vector<std::vector<unsigned int>>adjacentMatrix_Cfg = adjacentMatrix_Cfg_1;
