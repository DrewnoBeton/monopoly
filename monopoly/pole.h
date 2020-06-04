#include <iostream>
#include "gracz.h"
using namespace std;
#ifndef POLE_H
#define POLE_H
class Pole{
    protected:
    int id_wlasciciela_ =-1; //-1 to bank
    string nazwa = "nazwa_pola";
    int koszt;

    public:
    Pole(int arg_wlasciciel,string arg_nazwa,int arg_koszt);
    virtual int id_wlasciciela();
    virtual void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola) =0;
    //virtual void kup_pole(Gracz &gracz);
    //virtual void sprzedaj_pole(Gracz &gracz);

};
class Neutralne : public Pole
{
    public:
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola) override;
    Neutralne(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
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
    void kup_pole(Gracz &gracz);
    void sprzedaj_pole(Gracz &gracz);
    void kup_domek(Gracz &gracz);
    void sprzedaj_domek(Gracz &gracz);
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola) override;
    //tu efekt na graczu bedzie pobieral czynsz
};
class Specjalna : public Pole
{
    public:
    Specjalna(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
    void kup_pole(Gracz &gracz);
    void sprzedaj_pole(Gracz &gracz);
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola) override;
    //tu efekt na graczu bedzie pobieral czynsz w zaleznosci od ilosci posiadanych w grupie
};

#endif // POLE_H
