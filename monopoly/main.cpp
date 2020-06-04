#include <iostream>
#include "monopoly.h"
using namespace std;

int wybor;

int main()
{
    //todo przerob wektor na set, zeby nie miec duplikatow bo id sie powtarzaja
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
    //cout << gracze[3].id();
    nowa_gra(gracze,pola);
    wyswietl_graczy(gracze);
    Posiadlosc test(-1,"b",123,1);
    test.efekt_na_graczu(gracz1,gracze,pola);

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
            case 2:
            {
                ruch(gracze[czyja_tura(gracze)],gracze,pola);
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
