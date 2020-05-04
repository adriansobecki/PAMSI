#include "list_graph.hh"

list_graph::list_graph(int amount)
{
    adjacency_list.reserve(amount);
    std::vector<pair> element;
    for (int i = 0;i < amount;i++)
    {
        adjacency_list.push_back(element);
    }
    vertices_amount() = amount;
}


void list_graph::add_edge(int a, int b, int weight)
{
    pair element(b, weight);
    adjacency_list[a].push_back(element);
}

void list_graph::delete_edge(int a, int b)
{
    auto it = std::find_if(adjacency_list[a].begin(), adjacency_list[a].end(), [b](const pair& it2) { return b == it2.index; });
    adjacency_list[a].erase(it);
}

std::vector<int> list_graph::vertices(int a)
{
    std::vector<int> neighbors;
    for (pair vertex : adjacency_list[a])
        neighbors.push_back(vertex.index);
    return neighbors;
}

int list_graph::weight(int a, int b)
{
    auto it = std::find_if(adjacency_list[a].begin(), adjacency_list[a].end(), [b](const pair& it2) { return b == it2.index; });
    return it->weight;
}


void list_graph::print()
{
    for (int i = 0; i < this->vertices_amount(); i++)
    {
        std::vector<int> x;
        x = this->vertices(i);
        std::cout << "wierzcholek nr: " << i << std::endl;
        for (int k : x)
        {
            std::cout << k << "  waga-> " << this->weight(i, k) << std::endl;
        }
        std::cout << std::endl;
    }
}

