#include "monopoly.h"

Gracz::Gracz(string arg_nazwa, bool arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura)
{
    static int id = 0;
    id_= id++;
    nazwa = arg_nazwa;
    bankrut = arg_bankrut;
    saldo = arg_saldo;
    pozycja = arg_pozycja;
    tura = arg_tura;
}
Gracz::~Gracz()
{
    bankrut = true;
    saldo = 0;
}
int Gracz::id()
{
    return id_;
}
int Gracz::rzuc_kostkami()
{
    return rand() % 12 + 2;
}
void Gracz::zmien_pozycje(int odleglosc)
{
    if(pozycja+odleglosc<=40) pozycja += odleglosc;
    else pozycja = pozycja+odleglosc-40;
}
int Gracz::gdzie_jest()
{
    return pozycja;
}
void Gracz::zaplac(int kwota)
{
    if(saldo-kwota>0) saldo=saldo-kwota;
    else
    {
        saldo=-1;
        bankrut=true;
    }
}
void Gracz::otrzymaj(int kwota)
{
    saldo += kwota;
}
void Gracz::zaplac(int kwota, Gracz &gracz)
{
    zaplac(kwota);
    gracz.otrzymaj(kwota);
}
void Gracz::otrzymaj(int kwota, Gracz &gracz)
{
    otrzymaj(kwota);
    gracz.zaplac(kwota);
}
int Gracz::stan_konta()
{
    return saldo;
}
bool Gracz::czy_bankrut()
{
    return bankrut;
}
bool Gracz::czy_wlasciciel(int id_pola)
{
    if(posiadane_pola.empty()) return false;
    else
    {
        for(int pole:posiadane_pola)
        {
            if(pole==id_pola) return true;
        }
    }
    return false;
}
