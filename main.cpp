#include "SearchAndSorting/BinarySearch.h"
#include "Graph/Graph.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

/*
* The first parameter must be the algorithm name in Pascal notation style,
* and the rest of the parameters are algorithm-dependent.
* argc represents the number of input parameters stored in the array argv.
* argv[0] contains the name of the current program.
* argv[1] must contain the name of the algorithm to be executed.
* argv[n], being 2 < n < inf, contains the list of input parameters necessary for the chosen algorithm.
*/
int main(int argc, char *argv[])
{
  std::cout << "Running the program " << argv[0] << ", to use the algorithm " << argv[1] << " passing it " << (argc - 2) << " parameters." << std::endl;
  Graph graph;
  std::string algorithmCathegory(argv[1]);
  std::string algorithmName(argv[2]);
  // Add any algorithm to the following chain of if-else blocks.
  if (algorithmCathegory == "SearchAndSort") {
    if ((algorithmName == "BinarySearch") && (argc == 6)) {
      int target = atoi(argv[3]);
      int lower_boundary = atoi(argv[4]);
      int upper_boundary = atoi(argv[5]);
      BinarySearch binarySearch(lower_boundary, upper_boundary);
      int index = binarySearch.getIndexOf(target);
      std::cout << "index: " << index << std::endl;
    }
  } else if (algorithmCathegory == "Graph") {
    if ((algorithmName == "GraphInfo") || (algorithmName == "Info")) {
      if (argv[3]) {
        int selectedGraph = atoi(argv[3]);
        Graph graph;
        graph.setGraph(selectedGraph);
        graph.printGraphConnections();
        graph.printGraphConnectionsIds();
      } else {
        std::cout << "Please select the graph ID to show the information." << std::endl;
      }
    } else if ((algorithmName == "BFS") || (algorithmName == "BreadthFirstSearch")) {
      std::cout << "BFS" << std::endl;
      // bool theInputsAreValid = argv[3] && argv[4] && argv[5];
      // theInputsAreValid &= true;
      if (argv[3] && argv[4] && argv[5]) {
        int selectedGraph = atoi(argv[3]);
        graph.setGraph(selectedGraph);
        int startingNode = atoi(argv[4]);
        int targetNode = atoi(argv[5]);
        graph.printNeighborIdsOfNode(startingNode);
        graph.printNeighborIdsOfNode(targetNode);
        std::vector<unsigned int> shortestPath = graph.getShortestPath(BREADTH_FIRST_SEARCH, startingNode, targetNode);
        std::cout << "Shortest path (dummy path data): ";
        for (unsigned int i = 0; i < shortestPath.size(); i++) {
          std::cout << shortestPath[i] << " ";
        }
        std::cout << std::endl;
      } else {
        std::cout << "Please give the right inputs: $ ./bin/main Graph BFS <graphId> <startNodeId> <targetNodeId>\n";
      }
    }
  } else {
    std::cout << "Wrong or not enough input parameters.\nThe first parameter must be the algorithm name in Pascal notation style, and the rest of the parameters are algorithm-dependent." << std::endl;
  }

  return 0;
}
