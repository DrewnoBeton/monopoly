#include "gracz.h"

Gracz::Gracz(string arg_nazwa, bool arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura)
{
    static int id = 0;
    id_= id++;
    nazwa = arg_nazwa;
    bankrut = arg_bankrut;
    saldo = arg_saldo;
    pozycja = arg_pozycja;
    tura = arg_tura;
    switch(id_)
    {
        case 0:
        {
            kolor = sf::Color::Red;
            break;
        }
        case 1:
        {
            kolor = sf::Color::Blue;
            break;
        }
        case 2:
        {
            kolor = sf::Color::Green;
            break;
        }
        case 3:
        {
            kolor = sf::Color::Yellow;
            break;
        }
        case 4:
        {
            kolor = sf::Color::Magenta;
            break;
        }
        case 5:
        {
            kolor = sf::Color::Cyan;
            break;
        }
        case 6:
        {
            kolor = sf::Color(150, 75, 0);
            break;
        }
        case 7:
        {
            kolor = sf::Color(255, 132, 19);
            break;
        }
        default:
        {
            kolor = sf::Color(rand() % 100 + 50, rand() % 100 + 50, rand() % 100 + 50);
            break;
        }
    }
    pionek.setRadius(20);
    pionek.setFillColor(kolor);
}
Gracz::~Gracz()
{
    bankrut = true;
    kolor = sf::Color::Transparent;
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
    if(pozycja+odleglosc<40)
    {
        pozycja += odleglosc;
    }
    else
    {
        otrzymaj(200);
        pozycja = pozycja+odleglosc-40;
    }
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
        kolor = sf::Color::Transparent;
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

void Gracz::wyswietl_gracza(sf::RenderWindow &window)
{
    switch (pozycja)
    {
        case 0:
        {
         pionek.setPosition(910,880);
         break;
        }
        case 1:
        {
            pionek.setPosition(810,880);
            break;
        }
        case 2:
        {
            pionek.setPosition(720,880);
            break;
        }
        case 3:
        {
            pionek.setPosition(640,880);
            break;
        }
        case 4:
        {
            pionek.setPosition(560,880);
            break;
        }
        case 5:
        {
            pionek.setPosition(480,880);
            break;
        }
        case 6:
        {
            pionek.setPosition(400,880);
            break;
        }
        case 7:
        {
            pionek.setPosition(320,880);
            break;
        }
        case 8:
        {
            pionek.setPosition(250,880);
            break;
        }
        case 9:
        {
            pionek.setPosition(170,880);
            break;
        }
        case 10:
        {
            pionek.setPosition(50,880);
            break;
        }
        case 11:
        {
            pionek.setPosition(50,770);
            break;
        }
        case 12:
        {
            pionek.setPosition(50,690);
            break;
        }
        case 13:
        {
            pionek.setPosition(50,610);
            break;
        }
        case 14:
        {
            pionek.setPosition(50,530);
            break;
        }
        case 15:
        {
            pionek.setPosition(50,450);
            break;
        }
        case 16:
        {
            pionek.setPosition(50,370);
            break;
        }
        case 17:
        {
            pionek.setPosition(50,290);
            break;
        }
        case 18:
        {
            pionek.setPosition(50,220);
            break;
        }
        case 19:
        {
            pionek.setPosition(50,140);
            break;
        }
        case 20:
        {
            pionek.setPosition(50,30);
            break;
        }
        case 21:
        {
            pionek.setPosition(170,30);
            break;
        }
        case 22:
        {
            pionek.setPosition(250,30);
            break;
        }
        case 23:
        {
            pionek.setPosition(320,30);
            break;
        }
        case 24:
        {
            pionek.setPosition(400,30);
            break;
        }
        case 25:
        {
            pionek.setPosition(480,30);
            break;
        }
        case 26:
        {
            pionek.setPosition(560,30);
            break;
        }
        case 27:
        {
            pionek.setPosition(640,30);
            break;
        }
        case 28:
        {
            pionek.setPosition(720,30);
            break;
        }
        case 29:
        {
            pionek.setPosition(810,30);
            break;
        }
        case 30:
        {
            pionek.setPosition(910,30);
            break;
        }
        case 31:
        {
            pionek.setPosition(910,30);
            break;
        }
        case 32:
        {
            pionek.setPosition(910,140);
            break;
        }
        case 33:
        {
            pionek.setPosition(910,220);
            break;
        }
        case 34:
        {
            pionek.setPosition(910,290);
            break;
        }
        case 35:
        {
            pionek.setPosition(910,370);
            break;
        }
        case 36:
        {
            pionek.setPosition(910,450);
            break;
        }
        case 37:
        {
            pionek.setPosition(910,530);
            break;
        }
        case 38:
        {
            pionek.setPosition(910,610);
            break;
        }
        case 39:
        {
            pionek.setPosition(910,690);
            break;
        }
        case 40:
        {
            pionek.setPosition(910,770);
            break;
        }
    }
    window.draw(pionek);
}
