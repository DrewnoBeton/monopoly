#include <iostream>
#include "gracz.h"
using namespace std;
#ifndef POLE_H
#define POLE_H
class Pole{ //nie dalem jako abstrakcyjna, opiekt Pole ma pelnic funkcje pola neutralnego
    protected:
    int id_wlasciciel =-1; //-1 to bank
    string nazwa = "nazwa_pola";
    int koszt;

    public:
    Pole(int arg_wlasciciel,string arg_nazwa,int arg_koszt);
    int id_wlasciciela();
    virtual void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze);

};
class Posiadlosc : public Pole
{
    int grupa;
    int domki = 0;
    int koszt_domku = koszt*0.2;
    public:
    Posiadlosc(int arg_wlasciciel,string arg_nazwa,int arg_koszt,int arg_grupa) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt)
    {
        grupa = arg_grupa;
    }
    void kup_domek(Gracz &gracz);
    void sprzedaj_domek(Gracz &gracz);
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze);
    //tu efekt na graczu bedzie pobieral czynsz
};
class Start : public Pole
{
   bool czy_przeszedl(Gracz &gracz);
   //tu efekt na graczu bedzie dawal za start
};
class Specjalna : public Pole
{
    int grupa;

    public:
    Specjalna(int grupa);
    int ile_z_grupy(Gracz gracz);
    //tu efekt na graczu bedzie pobieral czynsz w zaleznosci od ilosci posiadanych w grupie
};

#endif // POLE_H
