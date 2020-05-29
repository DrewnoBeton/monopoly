#include "gracz.h"
#include "pole.h"
int test(){
    return 887;
}
void nowa_plansza(vector<Pole> &pola)
{
    if(!pola.empty()) pola.clear();
    //grupy 1-zadupie, 2-wioska, 3-wies, 4-duza wies, 5-miasteczko, 6-male miasto, 7-miasto, 8-metropolia
    pola.emplace_back(Pole(-1,"start",9999999));
    pola.emplace_back(Posiadlosc(-1,"zadupie1",200,1));
    pola.emplace_back(Posiadlosc(-1,"zadupie2",200,1));
    pola.emplace_back(Posiadlosc(-1,"zadupie3",200,1));
    pola.emplace_back(Posiadlosc(-1,"zadupie4",200,1));
    pola.emplace_back(Specjalna(-1,"dworzec1",1000));
    pola.emplace_back(Posiadlosc(-1,"wioska1",400,2));
    pola.emplace_back(Posiadlosc(-1,"wioska2",400,2));
    pola.emplace_back(Posiadlosc(-1,"wioska3",400,2));
    pola.emplace_back(Posiadlosc(-1,"wioska4",400,2));
    pola.emplace_back(Pole(-1,"parking1",9999999)); //10
    pola.emplace_back(Posiadlosc(-1,"wies1",600,3));
    pola.emplace_back(Posiadlosc(-1,"wies2",600,3));
    pola.emplace_back(Posiadlosc(-1,"wies3",600,3));
    pola.emplace_back(Posiadlosc(-1,"wies4",600,3));
    pola.emplace_back(Specjalna(-1,"dworzec2",1000));
    pola.emplace_back(Posiadlosc(-1,"duza_wies1",800,4));
    pola.emplace_back(Posiadlosc(-1,"duza_wies2",800,4));
    pola.emplace_back(Posiadlosc(-1,"duza_wies3",800,4));
    pola.emplace_back(Posiadlosc(-1,"duza_wies4",800,4));
    pola.emplace_back(Pole(-1,"parking2",9999999)); //20
    pola.emplace_back(Posiadlosc(-1,"miasteczko1",1000,5));
    pola.emplace_back(Posiadlosc(-1,"miasteczko2",1000,5));
    pola.emplace_back(Posiadlosc(-1,"miasteczko3",1000,5));
    pola.emplace_back(Posiadlosc(-1,"miasteczko4",1000,5));
    pola.emplace_back(Specjalna(-1,"dworzec3",1000));
    pola.emplace_back(Posiadlosc(-1,"male_miasto1",1200,6));
    pola.emplace_back(Posiadlosc(-1,"male_miasto2",1200,6));
    pola.emplace_back(Posiadlosc(-1,"male_miasto3",1200,6));
    pola.emplace_back(Posiadlosc(-1,"male_miasto4",1200,6));
    pola.emplace_back(Pole(-1,"parking3",9999999)); //30
    pola.emplace_back(Posiadlosc(-1,"miasto1",1400,7));
    pola.emplace_back(Posiadlosc(-1,"miasto2",1400,7));
    pola.emplace_back(Posiadlosc(-1,"miasto3",1400,7));
    pola.emplace_back(Posiadlosc(-1,"miasto4",1400,7));
    pola.emplace_back(Specjalna(-1,"dworzec4",1000));
    pola.emplace_back(Posiadlosc(-1,"metropolia1",1600,8));
    pola.emplace_back(Posiadlosc(-1,"metropolia2",1600,8));
    pola.emplace_back(Posiadlosc(-1,"metropolia3",1600,8));
    pola.emplace_back(Posiadlosc(-1,"metropolia4",1600,8));
    cout << "Utworzono nowa plansze!" <<endl;
}
void nowa_gra(vector<Gracz> &gracze,vector<Pole> &pola)
{
    int ilu_graczy = 2;
    int kwota_start = 5000;
    string nazwa = "nazwa_gracza";
    for(int i=0; i<ilu_graczy;i++)
    {
        Gracz g(nazwa,false,kwota_start,0,false);
        gracze.emplace_back(g);
    }
    nowa_plansza(pola);
}
