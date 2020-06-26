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
 * @brief Jest to klasa przechowująca zmienne i metody każdego gracza.
 */

class Gracz{
    /** - stan konta gracza*/
    int saldo =0;
    /** - czy gracz jest bankrutem*/
    bool bankrut = false;
    /** - pozycja gracza na planszy*/
    int pozycja = 0;
    /** - identyfikator gracza*/
    int id_;

    public:
    /** - pionek odpowiadajacy graczu*/
    sf::CircleShape pionek;
    /** - kolor odpowiadajacy graczu*/
    sf::Color kolor;
    /** - nazwa gracza*/
    string nazwa = "nazwa_gracza";
    /** - identyfikatory pol posiadanych przez gracza*/
    vector<int> posiadane_pola;
    /** - czy gracz ma ture*/
    bool tura = false;

    /**
     * @brief Konstruktor domyslny, bez parametrow
     */
    Gracz();
    /**
     * @brief Konsturktor z parametrami
     * @param arg_nazwa nazwa gracza
     * @param arg_bankrut czy gracz jest bankrutem
     * @param arg_saldo poczatkowy stan konta gracza
     * @param arg_pozycja poczatkowa pozycja na ktorej znajduje sie gracz
     * @param arg_tura czy gracz ma ture
     */
    Gracz(string arg_nazwa, bool arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura);
    /**
     * @brief Destruktor, w ramach zabezpieczenia ustawia stan konta na 0 i status bankruta
     */
    ~Gracz();

    /**
     * @brief zwraca identyfikator gracza
     * @return
     */
    int id();
    /**
     * @brief zwraca liczbe wyrzucona przez gracza(2-12)
     * @return
     */
    int rzuc_kostkami();
    /**
     * @brief zmienia pozycje gracza o podana odleglosc
     * @param odleglosc podana odleglosc
     */
    void zmien_pozycje(int odleglosc);
    /**
     * @brief zwraca pozycje na ktorej znajduje sie gracz
     * @return
     */
    int gdzie_jest();
    /**
     * @brief gracz placi podana kwote do banku
     * @param kwota kwota, którą gracz ma zapłacić
     */
    void zaplac(int kwota);
    /**
     * @brief gracz placi podana kwote do innego graca
     * @param kwota kwota, którą gracz ma zapłacić
     * @param gracz gracz, który ma otrzymać kwotę
     */
    void zaplac(int kwota, Gracz &gracz);
    /**
     * @brief gracz otrzymuje podana kwote od banku
     * @param kwota kwota, którą gracz ma otrzymać
     */
    void otrzymaj(int kwota);
    /**
     * @brief gracz otrzymuje podana kwote od innego graca
     * @param kwota kwota, którą gracz ma otrzymać
     * @param gracz gracz, który ma zapłacić kwotę
     */
    void otrzymaj(int kwota, Gracz &gracz);
    /**
     * @brief zwraca stan konta gracza
     * @return
     */
    int stan_konta();
    /**
     * @brief zwraca informacje czy gracz zbankrutowal
     * @return
     */
    bool czy_bankrut();
    /**
     * @brief sprawdza czy gracz jest wlascicielem podanego pola
     * @param id_pola pole, które sprawdzamy
     * @return
     */
    bool czy_wlasciciel(int id_pola);
    /**
     * @brief wyswietl_gracza
     * @param window
     */
    void wyswietl_gracza(sf::RenderWindow &window);
    /**
     * @brief operator ==
     * @param gracz1 pierwszy gracz
     * @param gracz1 drugi gracz
     * @return
     */
    friend bool operator==(const Gracz gracz1,const Gracz &gracz2) {return gracz1.nazwa==gracz2.nazwa;};

};
#endif // GRACZ_H
