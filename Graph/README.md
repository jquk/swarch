# Graph Algorithms

## Breadth First Search (BFS)
Used to explore nodes and edges on a graph.
Runs in time complexity O(NoVertices + NoEdges).
Often used as a building block in other algorithms.
Particularly useful for **finding the shortest path on unweighted graphs**.

*Explore by Layers:* Starts at some arbitrary node in the graph (user chosen), and explores the neighbor nodes first, before moving to the next level neighbors.

Needs to maintain a queue of which nodes it should visit next.
When it jumps to the next node in the queue, repeats the process, adding its neighbors on top of the stack (queue).
