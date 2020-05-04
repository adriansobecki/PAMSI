#include "base_graph.hh"


void b_graph::generate(int ro, unsigned long int* seed)
{
    int vertices = this->vertices_amount();
    srand((*seed)*2);
    (*seed)++;
    int index1, index2;
    int* tab;

    int edge_amount = vertices * (vertices - 1) * ro / 200;
   // std::cout << edge_amount;
    int currently_amount = vertices - 1;
    std::vector<int> available_vertices;
    std::vector<int> available_vertices2;
    std::vector<std::vector<int>> available_edges;
    std::vector<int>::iterator it, it2;
    available_vertices.reserve(vertices);
    available_vertices2.reserve(vertices);
    available_edges.reserve(vertices);


    for (int i = 0; i < vertices; i++)
    {
        available_vertices.push_back(i);
    }
    for (int i = 0; i < vertices; i++)
    {
        std::vector<int> element;
        available_edges.push_back(element);
        for (int k = 0; k < vertices; k++)
        {
            available_edges[i].push_back(k);
        }
        it = std::find(available_edges[i].begin(), available_edges[i].end(), i);
        available_edges[i].erase(it);
    }


    tab = (int*)malloc(sizeof(int) * vertices);
    for (int i = 0; i < vertices; i++)
        tab[i] = i;
    for (int i = 0; i < vertices; i++)
    {
        index1 = rand() % vertices;
        index2 = rand() % vertices;
        std::swap(tab[index1], tab[index2]);
    }

    this->add_edge(tab[0], tab[1], rand() % max_weight + 1);
    available_vertices2.push_back(tab[0]);
    available_vertices2.push_back(tab[1]);
    it = std::find(available_edges[tab[0]].begin(), available_edges[tab[0]].end(), tab[1]);
    available_edges[tab[0]].erase(it);
    it = std::find(available_edges[tab[1]].begin(), available_edges[tab[1]].end(), tab[0]);
    available_edges[tab[1]].erase(it);

    for (int i = 1; i < vertices - 1;i++)
    {
        index1 = rand() % available_vertices2.size();
        it = available_vertices2.begin();
        advance(it, index1);
        index1 = *it;
        index2 = rand() % 2;
        if (index2 == 0)
        {
            this->add_edge(tab[i + 1], index1, rand() % max_weight + 1);
        }
        else
        {
            this->add_edge(index1, tab[i + 1], rand() % max_weight + 1);
        }
        it = std::find(available_edges[tab[i + 1]].begin(), available_edges[tab[i + 1]].end(), index1);
        available_edges[tab[i + 1]].erase(it);
        it = std::find(available_edges[index1].begin(), available_edges[index1].end(), tab[i + 1]);
        available_edges[index1].erase(it);
        available_vertices2.push_back(tab[i + 1]);
    }
    for (int i = 0;i < vertices;i++)
    {
        if (available_edges[i].size() == 0)
        {
            it = std::find(available_vertices.begin(), available_vertices.end(), i);
            available_vertices.erase(it);
        }
    }

    while (currently_amount < edge_amount)
    {
        index1 = rand() % available_vertices.size();
        it = available_vertices.begin();
        advance(it, index1);
        index1 = *it;
        index2 = rand() % available_edges[index1].size();
        it2 = available_edges[index1].begin();
        advance(it2, index2);
        index2 = *it2;
        this->add_edge(index1, index2, rand() % max_weight + 1);
        available_edges[index1].erase(it2);
        it2 = std::find(available_edges[index2].begin(), available_edges[index2].end(), index1);
        available_edges[index2].erase(it2);

        if (available_edges[index1].size() == 0)
        {
            it2 = std::find(available_vertices.begin(), available_vertices.end(), index1);
            available_vertices.erase(it2);
        }
        if (available_edges[index2].size() == 0)
        {
            it2 = std::find(available_vertices.begin(), available_vertices.end(), index2);
            available_vertices.erase(it2);
        }

        currently_amount++;

    }

    free(tab);


}
