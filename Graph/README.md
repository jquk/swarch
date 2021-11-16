# Graph Algorithms

## Graph class
The Graph class inherits from multiple algorithm-specific classes.
An instance of the Graph class will load the adjacentMatrix_Cfg by default, unless other from the _Cfg list is specified with Graph::setGraph(int).
In the Graph_Cfg.h file you can create new connection matrix (adjacentMatrix), and assign it to adjacentMatrix_Cfg, to be loaded by any Graph instance.

## Breadth First Search (BFS)
Used to explore nodes and edges on a graph.
Runs in time complexity O(NoVertices + NoEdges).
Often used as a building block in other algorithms.
Particularly useful for **finding the shortest path on unweighted graphs**.

*Explore by Layers:* Starts at some arbitrary node in the graph (user chosen), and explores the neighbor nodes first, before moving to the next level neighbors.

Needs to maintain a queue of which nodes it should visit next.
When it jumps to the next node in the queue, repeats the process, adding its neighbors on top of the stack (queue).

### Breadth First Search (BFS) CLI usage
Show general information of the Nth graph:
```
./bin/main Graph Info <graphId>
./bin/main Graph Info 2
```
Show the shortest path between a starting node and a target node, for a given graph:
```
./bin/main Graph BFS <graphId> <startingNodeId> <targetNodeId>
./bin/main Graph BFS 2 0 4
```
