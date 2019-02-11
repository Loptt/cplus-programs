#include <vector>

class GraphNode
{
  public:
    GraphNode();
    ~GraphNode();

  private:
    std::vector<GraphNode *> neighbors;
    int data;
    bool visited;
};

GraphNode::GraphNode() : visited(false)
{
    
}

GraphNode::~GraphNode()
{
}
