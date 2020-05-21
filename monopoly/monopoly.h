#include <iostream>
#include <vector>
using namespace std;
#ifndef MONOPOLY_H
#define MONOPOLY_H
class Gracz{
    int saldo =0;
    bool bankrut = false;
    string nazwa = "nazwa_gracza";
    int poprzednia_pozycja = 0;
    int pozycja = 0;
    vector<int> posiadane_pola;

    public:
    bool tura = false;

    Gracz();
    Gracz(string arg_nazwa, bool arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura);
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
    bool czy_wlasciciel(int id_pola);
    //void kup_pole(Pole pole);

};
class Pole{ //nie dalem jako abstrakcyjna, opiekt Pole ma pelnic funkcje pola neutralnego
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

#endif // MONOPOLY_H
