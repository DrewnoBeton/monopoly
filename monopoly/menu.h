#include <iostream>
#include "monopoly.h"
#ifndef MENU_H
#define MENU_H

using namespace std;
/**
 * @brief Klasa obsługująca wyświetlanie i sterowanie grą
 */
class Menu{
    /** - wektor przechowujący graczy*/
    vector<Gracz> gracze;
    /** - wektor przechowujący pola*/
    vector<unique_ptr<Pole>> pola;
    /** - wektor przechowujący pionki*/
    vector <sf::Sprite> pionki;
    /** - czy gra dobiegła końca*/
    bool koniec=false;
    /** - czy znajdujemy sie w menu, czy juz w grze*/
    bool menu = true;
    /** - ilosc graczy, domyslnie 2*/
    int ilosc =2;
    /** - (DEBUG)wybor funkcji*/
    int wybor;
    /** - sprawdza czy gracz sie juz poruszyl*/
    bool ruszono = false;
    /** - ikona gry*/
    sf::Image icon;
    /** - czcionka używana do wyświetlania przez grę*/
    sf::Font font;
    /** - tekst środkowy, odpowiada za monity*/
    sf::Text tekst;
    /** - tekst pojawiający się po wygranej jednego z graczy*/
    sf::Text tekst_wygrana;
    /** - tekst początkowy do tekst_wygrana*/
    string wygrana_string = "WYGRYWA GRACZ ";
    /** - tekst wyświetlający, czyja jest tura*/
    sf::Text tekst_tura;
    /** - tekst początkowy do tekst_tura*/
    string tura_string = "TURA GRACZA ";
    /** - tekst wyświetlający możliwe akcje*/
    sf::Text tekst_sterowanie;
    /** - tekst początkowy do teskt_sterowanie*/
    string sterowanie_string = "MOZLIWE AKCJE:\nT - zakoncz ture\n";
    /** - tabela pokazująca graczy oraz ich stany konta*/
    sf::Text tekst_statystyki;
    /** - muzyka gry*/
    sf::Music music;
    /** - zegar*/
    sf::Clock clock;
    /** - tekstura potrzebna do tła*/
    sf::Texture texture;
    /** - tło gry, czyli plansza*/
    sf::Sprite tlo;
    /** - zmienna przechowująca event, który się wydarzył*/
    sf::Event event;
public:
    /**
     * @brief przygtowuje okno gry do wyświetlenia
     * @param window okno sfml, w którym działamy
     */
    void przygotuj_okno(sf::RenderWindow &window);
    /**
     * @brief obsluguje sterowanie grą
     * @param window okno sfml, w którym działamy
     */
    void sterowanie(sf::RenderWindow &window);
    /**
     * @brief wyświetla grę
     * @param window okno sfml, w którym działamy
     */
    void wyswietl(sf::RenderWindow &window);
};

#endif // MENU_H
