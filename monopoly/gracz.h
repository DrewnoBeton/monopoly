#include <iostream>
#include <vector>
using namespace std;
#ifndef GRACZ_H
#define GRACZ_H

class Gracz{
    int saldo =0;
    bool bankrut = false;
    string nazwa = "nazwa_gracza";
    int poprzednia_pozycja = 0;
    int pozycja = 0;
    int id_;

    public:
    vector<int> posiadane_pola;
    bool tura = false;

    Gracz();
    Gracz(string arg_nazwa, bool arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura);
    ~Gracz();

    int id();
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
    friend bool operator==(const Gracz gracz1,const Gracz &gracz2) {return gracz1.nazwa==gracz2.nazwa;};

};
#endif // GRACZ_H
