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
 * @brief Klasa Gracz, jest to klasa przechowująca zmienne i metody każdego gracza.
 */

class Gracz{
    int saldo =0;/** - stan konta gracza*/
    bool bankrut = false;/** - czy gracz jest bankrutem*/
    int pozycja = 0;/** - pozycja gracza na planszy*/
    int id_;/** - identyfikator gracza*/

    public:
    sf::CircleShape pionek; /** - pionek odpowiadajacy graczu*/
    sf::Color kolor;/** - kolor odpowiadajacy graczu*/
    string nazwa = "nazwa_gracza";/** - nazwa gracza*/
    vector<int> posiadane_pola;/** - identyfikatory pol posiadanych przez gracza*/
    bool tura = false;/** - czy gracz ma ture*/

    /**
     * @brief Konstruktor domyslny, bez parametrow
     */
    Gracz();
    /**
     * @brief Konsturktor z parametrami
     * @param nazwa gracza
     * @param czy gracz jest bankrutem
     * @param poczatkowy stan konta gracza
     * @param poczatkowa pozycja na ktorej znajduje sie gracz
     * @param czy gracz ma ture
     */
    Gracz(string arg_nazwa, bool arg_bankrut, int arg_saldo, int arg_pozycja, bool arg_tura);
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
     * @param odleglosc - podana odleglosc
     */
    void zmien_pozycje(int odleglosc);
    /**
     * @brief zwraca pozycje na ktorej znajduje sie gracz
     * @return
     */
    int gdzie_jest();
    /**
     * @brief gracz placi podana kwote do banku
     * @param kwota, którą gracz ma zapłacić
     */
    void zaplac(int kwota);
    /**
     * @brief gracz placi podana kwote do innego graca
     * @param kwota, którą gracz ma zapłacić
     * @param gracz, który ma otrzymać kwotę
     */
    void zaplac(int kwota, Gracz &gracz);
    /**
     * @brief gracz otrzymuje podana kwote od banku
     * @param kwota, którą gracz ma otrzymać
     */
    void otrzymaj(int kwota);
    /**
     * @brief gracz otrzymuje podana kwote od innego graca
     * @param kwota, którą gracz ma otrzymać
     * @param gracz, który ma zapłacić kwotę
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
     * @param pole, które sprawdzamy
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
     * @param pierwszy gracz
     * @param drugi gracz
     * @return
     */
    friend bool operator==(const Gracz gracz1,const Gracz &gracz2) {return gracz1.nazwa==gracz2.nazwa;};

};
#endif // GRACZ_H
