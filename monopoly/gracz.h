#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
#ifndef GRACZ_H
#define GRACZ_H

/**
 * @brief The Gracz class
 */

class Gracz{
    int saldo =0;
    bool bankrut = false;

    int poprzednia_pozycja = 0;
    int pozycja = 0;
    int id_;

    public:
    sf::CircleShape pionek;
    sf::Color kolor;
    string nazwa = "nazwa_gracza";
    vector<int> posiadane_pola;
    bool tura = false;

    Gracz();
    Gracz(string arg_nazwa, bool arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura);
    ~Gracz();

    int id();
    int rzuc_kostkami();
    /**
     * @brief zmienia pozycje gracza o podana odleglosc
     * @param odleglosc - podana odleglosc
     */
    void zmien_pozycje(int odleglosc);
    int gdzie_jest();
    void zaplac(int kwota);
    void zaplac(int kwota, Gracz &gracz);
    void otrzymaj(int kwota);
    void otrzymaj(int kwota, Gracz &gracz);
    /**
     * @brief stan_konta
     * @return
     */
    int stan_konta();
    bool czy_bankrut();
    bool czy_wlasciciel(int id_pola);
    void wyswietl_gracza(sf::RenderWindow &window);
    friend bool operator==(const Gracz gracz1,const Gracz &gracz2) {return gracz1.nazwa==gracz2.nazwa;};

};
#endif // GRACZ_H
