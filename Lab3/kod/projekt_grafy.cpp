
#include <iostream>
#include "list_graph.hh"
#include "matrix_graph.hh"
#include "dijkstra_algorithm.hh"
#include <chrono>

void test_list(int vertices, int ro, unsigned long int* seed);
void test_matrix(int vertices, int ro, unsigned long int* seed);
void test(int vertices, int ro, unsigned long int* seed);

int main()
{
    unsigned long int seed = 0;
    
    int vertices[] = { 10,50,100,500,1000 };
    int ro[] = { 25,50,75,100 };

    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 4; k++)
        {
           // test_list(vertices[i], ro[k], &seed);
           // test_matrix(vertices[i], ro[k], &seed);
            test(vertices[i], ro[k], &seed);
        }
    }
    std::cout << "END" << std::endl;

}


void test_list(int vertices,int ro, unsigned long int* seed)
{
    list_graph* list[100];

    std::cout << "Generowanie grafow dla " << vertices << " wierzcholkow oraz gestosci wynoszacej " << ro << "%..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        list[i] = new list_graph(vertices);
        list[i]->generate(ro, seed);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas generowania grafow: " << elapsed_seconds.count() << std::endl << std::endl;


    std::cout << "Algorytm dijkstry dla reprezentacji grafu w postaci listy... " << std::endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        dijkstra_algorithm(list[i], 0);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
    std::cout << "Dijkstra (list graph): " << elapsed_seconds1.count() << std::endl << std::endl;


    for (int i = 0; i < 100; i++)
    {
        delete(list[i]);
    }
}

void test_matrix(int vertices, int ro, unsigned long int* seed)
{
    matrix_graph* matrix[100];
    std::cout << "Generowanie grafow dla " << vertices << " wierzcholkow oraz gestosci wynoszacej " << ro << "%..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        matrix[i] = new matrix_graph(vertices);
        matrix[i]->generate(ro, seed);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas generowania grafow: " << elapsed_seconds.count() << std::endl << std::endl;



    std::cout << "Algorytm dijkstry dla reprezentacji grafu w postaci macierzy... " << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        dijkstra_algorithm(matrix[i], 0);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    std::cout << "Dijkstra (matrix graph): " << elapsed_seconds2.count() << std::endl << std::endl;



    for (int i = 0; i < 100; i++)
    {
        delete(matrix[i]);
    }
}


void test(int vertices, int ro, unsigned long int* seed)
{
    list_graph* list[100];
    matrix_graph* matrix[100];

    std::cout << "Generowanie grafow dla " << vertices << " wierzcholkow oraz gestosci wynoszacej " << ro << "%..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        list[i] = new list_graph(vertices);
        matrix[i] = new matrix_graph(vertices);
        list[i]->generate(ro, seed);
        matrix[i]->generate(ro, seed);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas generowania grafow: " << elapsed_seconds.count() << std::endl << std::endl;


    std::cout << "Algorytm dijkstry dla reprezentacji grafu w postaci listy... " << std::endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        dijkstra_algorithm(list[i], 0);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
    std::cout << "Dijkstra (list graph): " << elapsed_seconds1.count() << std::endl << std::endl;


    std::cout << "Algorytm dijkstry dla reprezentacji grafu w postaci macierzy... " << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        dijkstra_algorithm(matrix[i], 0);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    std::cout << "Dijkstra (matrix graph): " << elapsed_seconds2.count() << std::endl << std::endl;



    for (int i = 0; i < 100; i++)
    {
        delete(list[i]);
        delete(matrix[i]);
    }
}