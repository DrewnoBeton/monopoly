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
    virtual void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) =0;
    friend void ruch(Gracz &gracz,vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola,sf::Text &tekst);
    string nazwap();

};
class Neutralne : public Pole
{
    public:
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) override;
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
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) override;
    //tu efekt na graczu bedzie pobieral czynsz
};
class Specjalna : public Pole
{
    public:
    Specjalna(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
    void kup_pole(Gracz &gracz);
    void sprzedaj_pole(Gracz &gracz);
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) override;
    //tu efekt na graczu bedzie pobieral czynsz w zaleznosci od ilosci posiadanych w grupie
};

#endif // POLE_H
