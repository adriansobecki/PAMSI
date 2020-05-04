#include "base_graph.hh"

class list_graph : public b_graph
{
    struct pair
    {
        int index;
        int weight;
        pair(int a, int b) { index = a; weight = b; };
    };

    std::vector<std::vector<pair>> adjacency_list;

public:
    virtual void add_edge(int a, int b, int weight);
    virtual void delete_edge(int a, int b);
    virtual std::vector<int> vertices(int a);
    virtual int weight(int a, int b);
    list_graph(int amount);
    void print();
};

