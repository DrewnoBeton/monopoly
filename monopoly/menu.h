#include <iostream>
#include "monopoly.h"
#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu{
    vector<Gracz> gracze;
    vector<shared_ptr<Pole>> pola;
    vector <sf::Sprite> pionki;
    bool koniec=false;
    bool menu = true;
    int ilosc =2;
    int wybor;
    bool ruszono = false;
    sf::Font font;
    sf::Text tekst;
    sf::Text tekst_wygrana;
    string wygrana_string = "WYGRYWA GRACZ ";
    sf::Text tekst_tura;
    string tura_string = "TURA GRACZA ";
    sf::Text tekst_sterowanie;
    string sterowanie_string = "MOZLIWE AKCJE:\nT - zakoncz ture\n";
    sf::Text tekst_statystyki;
    sf::Music music;
    sf::Clock clock;
    sf::Texture texture;
    sf::Sprite tlo;
    sf::Event event;
public:
    void przygotuj_okno(sf::RenderWindow &window);
    void sterowanie(sf::RenderWindow &window);
    void wyswietl(sf::RenderWindow &window);
};

#endif // MENU_H
