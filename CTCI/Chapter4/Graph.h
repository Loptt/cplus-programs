#include <vector>
#include "GraphNode.h"

class Graph
{
  private:
    std::vector<GraphNode *> nodes;
    int size;

  public:
    Graph();
    ~Graph();

    void addEdge(GraphNode *a, GraphNode *b);
};

Graph::Graph() : size(0)
{
}

Graph::~Graph()
{
}
