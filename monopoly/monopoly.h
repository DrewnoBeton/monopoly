#include <iostream>
#include <vector>
using namespace std;
#ifndef MONOPOLY_H
#define MONOPOLY_H
class Gracz{
    int saldo =0;
    bool bankrut = false;
    string nazwa = "nazwa_gracza";
    int pozycja = 0;
    vector<int> posiadane_pola;

    public:
    bool tura = false;

    Gracz();
    Gracz(string arg_nazwa, int arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura);
    ~Gracz();

    int rzuc_kostkami();
    void zmien_pozycje(int odleglosc);
    int gdzie_jest();
    void zaplac(int kwota);
    void zaplac(int kwota, Gracz &gracz);
    void otrzymaj(int kwota);
    void otrzymaj(int kwota, Gracz &gracz);
    int stan_konta();
    bool czy_bankrut();
    bool czy_wlasciciel();
    //void kup_pole(Pole pole);

};
class Pole{
    protected:
    int id_wlasciciel =-1; //-1 to bank
    string nazwa = "nazwa_pola";
    int koszt;

    public:
    int id_wlasciciela();
    void efekt_na_graczu(Gracz &gracz);

};
class Posiadlosc : public Pole
{
    int grupa;
    int domki = 0;

    public:
    Posiadlosc(int grupa);
    void kup_domek();
    void sprzedaj_domek();
    //tu efekt na graczu bedzie pobieral czynsz
};
class Wielokrotek : public Pole
{

};
class Dworzec : public Pole
{

};

#endif // MONOPOLY_H
