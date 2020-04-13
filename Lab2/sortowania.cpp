
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include "merge_sort.hh"
#include "quick_sort.hh"
#include "introsort.hh"



using namespace std;
void sortowanie(int N, int algorytm, double procent, int odwrotnie);

int main()
{
    int odwrotnie = 0;
    double procent[] = { 0,25,50,75,95,99,99.7 };
    int elementy = 0;     //   0->10 000, 1->50 000, 2-> 100 000, 3-> 500 000, 4-> 1 000 000
    int k = 5;            //   0->0    1->25   2->50   3->75   4->95    5->99   6->99.7 
    for (elementy = 0;elementy < 5;elementy++)
    {
        sortowanie(elementy, 1, procent[k], odwrotnie);    
        sortowanie(elementy, 2, procent[k], odwrotnie);
        sortowanie(elementy, 3, procent[k], odwrotnie);
        cout << endl << endl << endl;
    }
}

void sortowanie(int N, int algorytm, double procent, int odwrotnie)
{
    procent = procent / 100;
    srand((unsigned int)time(NULL));
    int tab_size[] = { 10000,50000,100000,500000,1000000 };
    int* tab100[100];

    if (odwrotnie == 1)
        procent = 1;

    if (procent == 0)
    {
        for (int i = 0; i < 100; i++)
        {
            tab100[i] = (int*)malloc(sizeof(int) * tab_size[N]);
            for (int k = 0; k < tab_size[N]; k++)
            {
                tab100[i][k] = rand();
            }
        }
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            tab100[i] = (int*)malloc(sizeof(int) * tab_size[N]);
            for (int k = 0; k < tab_size[N]; k++)
            {
                tab100[i][k] = rand();
            }
            std::sort(tab100[i], tab100[i] + (int)(procent * tab_size[N]));
            
            if (odwrotnie == 1)
            {
                for (int j = 0; j < tab_size[N]/2; j++)
                {
                    int element = tab100[i][j];
                    tab100[i][j] = tab100[i][tab_size[N]-1 - j];
                    tab100[i][tab_size[N]-1 - j] = element;
                }
            }
            
        }
    }
    /*
    for (int i = 0; i < tab_size[N];i++)
    {
        cout << tab100[0][i] << endl;
    }
    cin.get();
    cin.ignore();
    */

    switch (algorytm)
    {
    case 1:
    {
        auto start1 = std::chrono::high_resolution_clock::now();
        for (int l = 0;l < 100;l++)
        {
            merge_sort(tab100[l], 0, tab_size[N] - 1);
        }
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
        std::cout << "merge time: " << elapsed_seconds1.count() << "s\n";
        break;
    }
    case 2:
    {
        auto start2 = std::chrono::high_resolution_clock::now();
        for (int l = 0;l < 100;l++)
        {
            quick_sort(tab100[l], 0, tab_size[N] - 1);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
        std::cout << "quick time: " << elapsed_seconds2.count() << "s\n";
        break;
    }
    case 3:
    {
        auto start3 = std::chrono::high_resolution_clock::now();
        for (int l = 0;l < 100;l++)
        {
            introspective_sort(tab100[l], 0, tab_size[N] - 1);
        }
        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
        std::cout << "introspective time: " << elapsed_seconds3.count() << "s\n";
        break;
    }
    default:
    {
        cout << "1-3" << endl;
        break;
    }
    }
    /*
    for (int i = 0; i < tab_size[N];i++)
    {
        cout << tab100[0][i] << endl;
    }
    cin.get();
    cin.ignore();
    */
    for (int i = 0; i < 100; i++)
        free(tab100[i]);
}
