# Graph Algorithms

## Graph class
An instance of the Graph class will load the adjacentMatrix_Cfg.
In the Graph_Cfg.h file you can create new connection matrix (adjacentMatrix), and assign it to adjacentMatrix_Cfg, to be loaded by any Graph instance.

## Breadth First Search (BFS) CLI usage
Show general information of the Nth graph:
```
./bin/main Graph Info <graphId>
```
Show the shortest path between a starting node and a target node, in the Nth graph:
```
./bin/main Graph BFS <graphId> <startingNodeId> <targetNodeId>
```
## Breadth First Search (BFS)
Used to explore nodes and edges on a graph.
Runs in time complexity O(NoVertices + NoEdges).
Often used as a building block in other algorithms.
Particularly useful for **finding the shortest path on unweighted graphs**.

*Explore by Layers:* Starts at some arbitrary node in the graph (user chosen), and explores the neighbor nodes first, before moving to the next level neighbors.

Needs to maintain a queue of which nodes it should visit next.
When it jumps to the next node in the queue, repeats the process, adding its neighbors on top of the stack (queue).
