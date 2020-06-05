#include "kolko_krzyzyk.hh"


kolko_krzyzyk::kolko_krzyzyk(int rozmiar, int zasady)
{
    rozmiar_planszy = rozmiar;
    zasady_gry = zasady;
    plansza = new char[rozmiar * rozmiar + 1];
    for (int i = 0;i < rozmiar * rozmiar;i++)
        plansza[i] = ' ';
}


void kolko_krzyzyk::print()
{
    std::string czesc = "+---";
    std::string calosc = "---";
    for (int k = 1;k < rozmiar_planszy;k++)
    {
        calosc = calosc + czesc;
    }
    for (int i = 1; i < rozmiar_planszy * rozmiar_planszy + 1; i++)
    {
        std::cout << " " << plansza[i - 1] << " ";
        if (i % rozmiar_planszy)
            std::cout << "|";
        else if (i != rozmiar_planszy * rozmiar_planszy)
            std::cout << std::endl << calosc << std::endl;
        else
            std::cout << std::endl;
    }
}

bool kolko_krzyzyk::ruch(char znak)
{
    int index;
    std::cout << std::endl << "Podaj nr. pola" << std::endl;
    while (!(std::cin >> index))
    {
        std::cin.clear();
        std::cin.ignore();
    }
    if (plansza[index] == ' ')
    {
        plansza[index] = znak;
        return true;
    }
    return false;
}

bool kolko_krzyzyk::czy_wygrana(char znak)
{
    int rzad;
    int kolumna;

    for (int i = 0;i < rozmiar_planszy * rozmiar_planszy - (zasady_gry - 1);i++)
    {
        rzad = i / rozmiar_planszy;
        if ((i + zasady_gry - 1) / rozmiar_planszy == rzad)
        {
            int sprawdzenie = 0;
            for (int k = i; k < i + zasady_gry; k++)
            {
                if (plansza[k] == znak)
                    sprawdzenie++;
            }
            if (sprawdzenie == zasady_gry)
                return true;
        }

    }
    for (int i = 0;i < rozmiar_planszy * rozmiar_planszy - (zasady_gry - 1) * rozmiar_planszy;i++)
    {

        int sprawdzenie = 0;
        for (int k = i; k < i + zasady_gry * rozmiar_planszy; k += rozmiar_planszy)
        {
            if (plansza[k] == znak)
                sprawdzenie++;
        }
        if (sprawdzenie == zasady_gry)
            return true;
    }

    for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
    {
        rzad = i / rozmiar_planszy;
        kolumna = i % rozmiar_planszy;
        if (rzad + (zasady_gry - 1) < rozmiar_planszy && kolumna + (zasady_gry - 1) < rozmiar_planszy)
        {
            int sprawdzenie = 0;
            for (int k = i; k < i + zasady_gry * (rozmiar_planszy + 1); k += rozmiar_planszy + 1)
            {
                if (plansza[k] == znak)
                    sprawdzenie++;
            }
            if (sprawdzenie == zasady_gry)
                return true;
        }
    }

    for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
    {
        rzad = i / rozmiar_planszy;
        kolumna = i % rozmiar_planszy;
        if (rzad + (zasady_gry - 1) < rozmiar_planszy && kolumna - (zasady_gry - 1) >= 0)
        {
            int sprawdzenie = 0;
            for (int k = i; k < i + (zasady_gry) * (rozmiar_planszy - 1); k += rozmiar_planszy - 1)
            {
                if (plansza[k] == znak)
                    sprawdzenie++;
            }
            if (sprawdzenie == zasady_gry)
                return true;
        }
    }

    return false;
}

bool kolko_krzyzyk::ruch_komp(char znak)
{
    int index;
    if (znak == 'X')
        index = najlepszy_ruch_ab(znak, false);
    else
        index = najlepszy_ruch_ab(znak, true);
    std::cout << std::endl << index << std::endl;
    if (plansza[index] == ' ')
    {
        plansza[index] = znak;
        return true;
    }
    return false;
}

bool kolko_krzyzyk::czy_remis()
{
    for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
    {
        if (plansza[i] == ' ')
            return false;
    }
    return true;
}



int kolko_krzyzyk::stan(bool czy_max)
{
    if (czy_max)
    {
        for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
        {
            if (plansza[i] == ' ')
            {
                plansza[i] = 'X';
                if (czy_wygrana('X'))
                {
                    plansza[i] = ' ';
                    return 50;
                }
                plansza[i] = ' ';

            }
        }
    }

    else
    {
        for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
        {
            if (plansza[i] == ' ')
            {
                plansza[i] = 'O';
                if (czy_wygrana('O'))
                {
                    plansza[i] = ' ';
                    return -50;
                }
                plansza[i] = ' ';

            }
        }
    }
    return 0;
}





void kolko_krzyzyk::gra()
{
    char znaki[3] = { 'O','X' };
    int i = 2;

    print();
    std::cout << std::endl << "Tura gracza 'O'";


    while (!czy_wygrana(znaki[i - 1]) && !czy_remis())
    {
        if (i == 2)
            i = 0;

        while (!ruch(znaki[i]));
        print();
        i++;
    }
    if (czy_remis())
        std::cout << std::endl << "REMIS" << std::endl;
    else
    {
        std::cout << std::endl << "WYGRAL GRACZ: " << znaki[i - 1] << std::endl;
    }
}



void kolko_krzyzyk::gra_mini_max()
{
    char znaki[3] = { 'O','X' };
    int i = 2;
    int wybor;
    std::cout << "KTO ZACZYNA? " << std::endl << "'1' - GRACZ" << std::endl << "'2' - KOMPUTER" << std::endl;
    while (!(std::cin >> wybor))
    {
        std::cin.clear();
        std::cin.ignore();
    }
    if (wybor == 1)
        i = 2;
    else
        i = 1;
    print();
    // std::cout << std::endl << "Tura gracza 'O'";


    while (!czy_wygrana(znaki[i - 1]) && !czy_remis())
    {
        if (i == 2)
            i = 0;
        if (i == 0)
        {
            while (!ruch(znaki[i]));
        }
        else
        {
            ruch_komp(znaki[i]);
        }
        print();
        i++;
    }

    if (czy_remis())
        std::cout << std::endl << "REMIS" << std::endl;
    else
    {
        std::cout << std::endl << "WYGRAL GRACZ: " << znaki[i - 1] << std::endl;
    }
}







int kolko_krzyzyk::najlepszy_ruch_ab(char kogo_ruch, bool czy_max)
{
    int najlepszy_wynik = -infinity;
    int ruch = -1;

    for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
    {
        if (plansza[i] == ' ')
        {
            plansza[i] = kogo_ruch;
            int wynik = minimax_ab(0, czy_max, -1000000, 1000000);
            plansza[i] = ' ';
            if (wynik > najlepszy_wynik)
            {
                najlepszy_wynik = wynik;
                ruch = i;
            }
        }
    }
    return ruch;
}
int kolko_krzyzyk::minimax_ab(int glebokosc, bool czy_max, int alfa, int beta)
{
    if (czy_max)
    {
        if (czy_wygrana('O') == true)
            return -200 + glebokosc * 10;
    }
    else
    {
        if (czy_wygrana('X') == true)
            return 200 - glebokosc * 10;
    }

    if (czy_remis() == true)
        return 0;

    if (rozmiar_planszy <= 4)
    {
        if (glebokosc > 4)
            return stan(czy_max);
    }
    else if(rozmiar_planszy==5)
    {
        if (glebokosc > 3)
            return stan(czy_max);
    }
    else if(rozmiar_planszy<=7)
    {
        if (glebokosc > 2)
            return stan(czy_max);
    }
    else
    {
        if (glebokosc > 1)
            return stan(czy_max);
    }


    if (czy_max)
    {
        int najlepszy_wynik = -infinity;
        for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
        {
            if (plansza[i] == ' ')
            {
                plansza[i] = 'X';
                int wynik = minimax_ab(glebokosc + 1, false, alfa, beta);
                plansza[i] = ' ';
                najlepszy_wynik = std::max(wynik, najlepszy_wynik);
                alfa = std::max(wynik, alfa);
                if (alfa >= beta)
                    return najlepszy_wynik;
            }
        }
        return najlepszy_wynik;
    }
    else
    {
        int najlepszy_wynik = infinity;
        for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
        {
            if (plansza[i] == ' ')
            {
                plansza[i] = 'O';
                int wynik = minimax_ab(glebokosc + 1, true, alfa, beta);
                plansza[i] = ' ';
                najlepszy_wynik = std::min(wynik, najlepszy_wynik);
                beta = std::min(wynik, beta);
                if (alfa >= beta)
                    return najlepszy_wynik;
            }
        }
        return najlepszy_wynik;
    }
}





/*


int kolko_krzyzyk::najlepszy_ruch(char kogo_ruch, bool czy_max)
{
    int najlepszy_wynik = -infinity;
    int ruch = -1;

    for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
    {
        if (plansza[i] == ' ')
        {
            plansza[i] = kogo_ruch;
            int wynik = minimax(0, czy_max);
            plansza[i] = ' ';
            if (wynik > najlepszy_wynik)
            {
                najlepszy_wynik = wynik;
                ruch = i;
            }
        }
    }
    return ruch;
}
int kolko_krzyzyk::minimax(int glebokosc, bool czy_max)
{
    if (czy_wygrana('X') == true)
        return 200 - glebokosc * 10;
    if (czy_wygrana('O') == true)
        return -200 + glebokosc * 10;

    if (czy_remis() == true)
        return 0;

    if (rozmiar_planszy <= 4)
    {
        if (glebokosc > 4)
            return stan(czy_max);
    }
    else
    {
        if (glebokosc > 2)
            return stan(czy_max);
    }

    if (czy_max)
    {
        int najlepszy_wynik = -infinity;
        for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
        {
            if (plansza[i] == ' ')
            {
                plansza[i] = 'X';
                int wynik = minimax(glebokosc + 1, !czy_max);
                plansza[i] = ' ';
                najlepszy_wynik = std::max(wynik, najlepszy_wynik);
            }
        }
        return najlepszy_wynik;
    }
    else
    {
        int najlepszy_wynik = infinity;
        for (int i = 0;i < rozmiar_planszy * rozmiar_planszy;i++)
        {
            if (plansza[i] == ' ')
            {
                plansza[i] = 'O';
                int wynik = minimax(glebokosc + 1, !czy_max);
                plansza[i] = ' ';
                najlepszy_wynik = std::min(wynik, najlepszy_wynik);
            }
        }
        return najlepszy_wynik;
    }
}

*/