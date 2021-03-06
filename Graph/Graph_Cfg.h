#include <vector>

/*
* How to add and use a new "adjacency matrix":
* 1. Create a new two dimensional array (using the std::vector template), that represents the connections between nodes.
* 2. Add the new adjacency matrix into the 3D array named connectionsMatrix_Cfg at the end of this file.
* 3. Go to Graph.cpp and in the function Graph::setGraph() add a new case to the switch,
*    noticing that the corresponding switch value shall be used as index for the 3D adjacency matrix.
*    When calling the program with the command line interface, the parameter passed for the Graph Id,
*    will select the corresponding case of the switch block. 
* being connectionsMatrix_Cfg the one that will be used in the algorithms.
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

std::vector<std::vector<unsigned int>>connectionsMatrix_Cfg_default {
      /*A, B, C*/
  /*A*/{0, 1, 1},//A is connected to B, C.
  /*B*/{1, 0, 0},//B is connected to A.
  /*C*/{1, 0, 0}//C is connected to A.
};

// Take the reference from the picture 'ex1-AdjacencyMatrix.png'
// but making it unweighted.
std::vector<std::vector<unsigned int>>connectionsMatrix_Cfg_1 {
     /*{A, B, C, D, E}*/
  /*A*/{0, 1, 0, 1, 0},//A is connected to B, D.
  /*B*/{1, 0, 1, 0, 0},//B is connected to A, C.
  /*C*/{0, 1, 0, 1, 0},//C is connected to B, D.
  /*D*/{1, 0, 1, 0, 0},//D is connected to A, C.
  /*E*/{0, 0, 0, 1, 0}//E is connected to D.
};

// Take the reference from the picture 'ex2-BFS_graph_queue.png'
std::vector<std::vector<unsigned int>>connectionsMatrix_Cfg_2 {
      /*{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}*/
  /*00*/{0, 0, 0, 0, 0, 0, 0, 1, 0, 1,  0,  1,  0},//0 is connected to 7, 9, 11.
  /*01*/{0, 0, 0, 0, 0, 0, 0, 0, 1, 0,  1,  0,  0},//1 is connected to 8, 10.
  /*02*/{0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0,  0,  1},//2 is connected to 3, 12.
  /*03*/{0, 0, 1, 0, 1, 0, 0, 1, 0, 0,  0,  0,  0},//3 is connected to 2, 4, 7.
  /*04*/{0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0,  0,  0},//4 is connected to 3.
  /*05*/{0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  0,  0,  0},//5 is connected to 6.
  /*06*/{0, 0, 0, 0, 0, 1, 0, 1, 0, 0,  0,  0,  0},//6 is connected to 5, 7.
  /*07*/{1, 0, 0, 1, 0, 0, 1, 0, 0, 0,  0,  1,  0},//7 is connected to 0, 3, 6, 11.
  /*08*/{0, 1, 0, 0, 0, 0, 0, 0, 0, 1,  0,  0,  1},//8 is connected to 1, 9, 12.
  /*09*/{1, 0, 0, 0, 0, 0, 0, 0, 1, 0,  1,  0,  0},//9 is connected to 0, 8, 10.
  /*10*/{0, 1, 0, 0, 0, 0, 0, 0, 0, 1,  0,  0,  0},//10 is connected to 1, 9.
  /*11*/{1, 0, 0, 0, 0, 0, 0, 1, 0, 0,  0,  0,  0},//11 is connected to 0, 7.
  /*12*/{0, 0, 1, 0, 0, 0, 0, 0, 1, 0,  0,  0,  0}//12 is connected to 2, 8.
};

std::vector<std::vector<std::vector<unsigned int>>>connectionsMatrix_Cfg = {connectionsMatrix_Cfg_default, connectionsMatrix_Cfg_1, connectionsMatrix_Cfg_2};
