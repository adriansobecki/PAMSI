#include <queue>
#include <utility>
#include "base_graph.hh"

#define infinity 2147483647


std::vector<long int> dijkstra_algorithm(b_graph* graph,int vertex)
{
    std::vector<long int> wages;
    wages.resize(graph->vertices_amount(), infinity);
    std::vector<int> predecessors;
    predecessors.resize(graph->vertices_amount(), no_connection);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> x;
    std::vector<int> available;
    available.resize(graph->vertices_amount(), 1);
    std::vector<int> checked;
    checked.resize(graph->vertices_amount(), 0);
    
    wages[vertex] = 0;
    x.push(std::make_pair(0, vertex));
    available[vertex] = 0;
    std::vector<int> adjacency_vertex;
    while(1)
    {
        if (x.size() == 0)
            break;

        int index1 = x.top().second;
        x.pop();
        adjacency_vertex = graph->vertices(index1);

        checked[index1] = 1;
        for (int index2 : adjacency_vertex)
        {
            if (checked[index2] == 0)
            {
                if (wages[index2] > wages[index1] + graph->weight(index1, index2))
                {
                    wages[index2] = wages[index1] + graph->weight(index1, index2);
                    predecessors[index2] = index1;
                }

                if (available[index2] == 1)
                {
                    x.push(std::make_pair(wages[index2], index2));
                    available[index2] = 0;
                }
            }
        }
    }
    return wages;
}