struct Inputs_t
{
  unsigned int startNode;
  unsigned int targetNode;
  std::vector<std::vector<unsigned int>>connectionsIdsMatrix;
};

struct Outputs_t
{
  std::vector<std::vector<unsigned int>>pathsToTarget;
  std::vector<unsigned int>shortestPathToTarget;
};

struct CurrentState_t
{
  unsigned int nodeIndex;
  unsigned int nodeValue;
  std::vector<unsigned int>exploredNodesTree;
};
