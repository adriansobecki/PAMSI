#include "base_graph.hh"

class matrix
{
    std::vector<int> vec;
    int n;

public:
    matrix(int vertices) { n = vertices; vec.resize(n * n, no_connection); };
    int& operator()(int x, int y) { return vec[x * n + y]; };
    const int& operator()(int x, int y)const { return vec[x * n + y]; };
};


class matrix_graph : public b_graph
{
    matrix adjacency_matrix;

public:
    virtual void add_edge(int a, int b, int weight);
    virtual void delete_edge(int a, int b);
    virtual std::vector<int> vertices(int a);
    virtual int weight(int a, int b);
    matrix_graph(int vertices) : adjacency_matrix(vertices) { vertices_amount() = vertices; }
    void print();

};
