#include "matrix_graph.hh"

void matrix_graph::add_edge(int a, int b, int weight)
{
    adjacency_matrix(a, b) = weight;
}

void matrix_graph::delete_edge(int a, int b)
{
    adjacency_matrix(a, b) = no_connection;
}

std::vector<int> matrix_graph::vertices(int a)
{
    std::vector<int> neighbors;
    for (int i = 0; i < this->vertices_amount();i++)
        if (adjacency_matrix(a, i) > 0)
            neighbors.push_back(i);
    return neighbors;
}

int matrix_graph::weight(int a, int b)
{
    return adjacency_matrix(a, b);
}

void matrix_graph::print()
{
    for (int i = 0; i < this->vertices_amount(); i++)
    {
        std::cout << "wierzcholek nr: " << i << std::endl;
        for (int k = 0; k < this->vertices_amount(); k++)
        {
            if (adjacency_matrix(i, k) > 0)
                std::cout << k << "  waga-> " << this->weight(i, k) << std::endl;
        }
        std::cout << std::endl;
    }
}


