#include <iostream>
#include "monopoly.h"
using namespace std;

int wybor;

int main()
{
    //debug
    Gracz gracz1 = Gracz("a",false,0,0,true);
    Gracz gracz2 = Gracz("a",true,0,0,false);
    Gracz gracz3 = Gracz("a",false,0,0,false);
    gracze.emplace_back(gracz1);
    gracze.emplace_back(gracz2);
    gracze.emplace_back(gracz2);
    //gracze.emplace_back(gracz3);
    //gracze.emplace_back(gracz3);
    gracze.emplace_back(gracz3);
    nowa_gra(gracze,pola);
    wyswietl_graczy(gracze);

    do {
        cout << "Wybierz opcje: \n 1-zmien ture" << endl;
        cin >> wybor;
        switch (wybor)
        {
            case 1:
            {
                ustaw_ture(gracze,koniec);
                break;
            }
            default:
            {
               koniec = true;
               break;
            }
        }
        wyswietl_graczy(gracze);

    }while (!koniec);
    return 0;
}
