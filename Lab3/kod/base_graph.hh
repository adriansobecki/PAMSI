#pragma once
#include <vector>
#include <stdlib.h>     
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <ctime>

#define no_connection -1
#define max_weight 1000

class b_graph
{
    int n=0;
public:
    virtual void add_edge(int a, int b, int weight) = 0;
    virtual void delete_edge(int a, int b) = 0;
    virtual std::vector<int> vertices(int a) = 0;
    virtual int weight(int a, int b) = 0;
    int& vertices_amount() { return n; };
    const int& vertices_amount()const { return n; };
    void generate(int ro, unsigned long int* seed);
};
