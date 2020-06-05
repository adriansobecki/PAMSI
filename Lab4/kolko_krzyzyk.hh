#include <algorithm>
#include <iostream>
#define infinity 1000000;

class kolko_krzyzyk
{
    int rozmiar_planszy;
    int zasady_gry;
    char* plansza;

public:
    kolko_krzyzyk(int rozmiar, int zasady);
    ~kolko_krzyzyk() { delete[] plansza; }
    void gra();
    void gra_mini_max();
    bool ruch(char znak);
    bool ruch_komp(char znak);
    bool czy_wygrana(char znak);
    bool czy_remis();
    void print();
    //int minimax(int glebokosc, bool czy_max);
    int minimax_ab(int glebokosc, bool czy_max, int alfa, int beta);
    //int najlepszy_ruch(char kogo_ruch,bool czy_max);
    int najlepszy_ruch_ab(char kogo_ruch,bool czy_max);
    int stan(bool czy_max);
    
};

