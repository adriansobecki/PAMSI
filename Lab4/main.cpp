
#include <iostream>
#include <string>
#include "kolko_krzyzyk.hh"

int main()
{
    int i = 1;
    while (i)
    {
        int rozmiar, zasady;
        std::cout << "GRA KOLKO I KRZYZYK" << std::endl;
        std::cout << "WYBIERZ ROZMIAR PLANSZY [3-7]: " << std::endl;
        while (!(std::cin >> rozmiar))
        {
            std::cin.clear();
            std::cin.ignore();
        }
        std::cout << "WYBIERZ ILOSC W RZEDZIE DO WYGRANEJ: " << std::endl;
        while (!(std::cin >> zasady))
        {
            std::cin.clear();
            std::cin.ignore();
        }
        kolko_krzyzyk gra(rozmiar, zasady);
        gra.gra_mini_max();
        std::cout << std::endl << "JESZCZE RAZ?" << std::endl;
        std::cout << "'1' - TAK" << std::endl;
        std::cout << "'0' - NIE" << std::endl;
        while (!(std::cin >> i))
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }
}
