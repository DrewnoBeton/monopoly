#include <iostream>
#include "monopoly.h"
#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu{
    vector<Gracz> gracze;/** - wektor przechowujący graczy*/
    vector<unique_ptr<Pole>> pola;/** - wektor przechowujący pola*/
    vector <sf::Sprite> pionki;/** - wektor przechowujący pionki*/
    bool koniec=false;/** - czy gra dobiegła końca*/
    bool menu = true;/** - czy znajdujemy sie w menu, czy juz w grze*/
    int ilosc =2;/** - ilosc graczy, domyslnie 2*/
    int wybor;/** - (DEBUG)wybor funkcji*/
    bool ruszono = false;/** - sprawdza czy gracz sie juz poruszyl*/
    sf::Font font;/** - czcionka używana do wyświetlania przez grę*/
    sf::Text tekst;/** - tekst środkowy, odpowiada za monity*/
    sf::Text tekst_wygrana;/** - tekst pojawiający się po wygranej jednego z graczy*/
    string wygrana_string = "WYGRYWA GRACZ ";/** - tekst początkowy do tekst_wygrana*/
    sf::Text tekst_tura;/** - tekst wyświetlający, czyja jest tura*/
    string tura_string = "TURA GRACZA ";/** - tekst początkowy do tekst_tura*/
    sf::Text tekst_sterowanie;/** - tekst wyświetlający możliwe akcje*/
    string sterowanie_string = "MOZLIWE AKCJE:\nT - zakoncz ture\n";/** - tekst początkowy do teskt_sterowanie*/
    sf::Text tekst_statystyki;/** - tabela pokazująca graczy oraz ich stany konta*/
    sf::Music music;/** - muzyka gry*/
    sf::Clock clock;/** - zegar*/
    sf::Texture texture;/** - tekstura potrzebna do tła*/
    sf::Sprite tlo;/** - tło gry, czyli plansza*/
    sf::Event event;/** - zmienna przechowująca event, który się wydarzył*/
public:
    /**
     * @brief przygtowuje okno gry do wyświetlenia
     * @param okno sfml, w którym działamy
     */
    void przygotuj_okno(sf::RenderWindow &window);
    /**
     * @brief obsluguje sterowanie grą
     * @param okno sfml, w którym działamy
     */
    void sterowanie(sf::RenderWindow &window);
    /**
     * @brief wyświetla grę
     * @param okno sfml, w którym działamy
     */
    void wyswietl(sf::RenderWindow &window);
};

#endif // MENU_H
