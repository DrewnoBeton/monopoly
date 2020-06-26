#include <iostream>
#include "gracz.h"
using namespace std;
#ifndef POLE_H
#define POLE_H
class Pole{
    protected:
    int id_wlasciciela_ =-1;/** - identyfikator wlasciciela pola, -1 to bank*/
    string nazwa = "nazwa_pola";/** - nazwa pola*/
    int koszt;/** - koszt pola*/

    public:
    /**
     * @brief Kostruktor pola
     * @param własciciel pola
     * @param nazwa pola
     * @param koszt pola
     */
    Pole(int arg_wlasciciel,string arg_nazwa,int arg_koszt);
    /**
     * @brief zwraca identyfikator właściciela
     * @return
     */
    virtual int id_wlasciciela();
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz, który wszedł na pole
     * @param wektor graczy
     * @param wektor pól
     * @param tekst w sfml, w którym wyświetlamy
     */
    virtual void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) =0;
    friend void ruch(Gracz &gracz,vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola,sf::Text &tekst);
    /**
     * @brief zwraca nazwę pola
     * @return
     */
    string nazwap();

};
class Neutralne : public Pole
{
    public:
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz, który wszedł na pole
     * @param wektor graczy
     * @param wektor pól
     * @param tekst w sfml, w którym wyświetlamy
     */
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) override;
    /**
     * @brief Kostruktor pola
     * @param własciciel pola
     * @param nazwa pola
     * @param koszt pola
     */
    Neutralne(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
};
class Posiadlosc : public Pole
{
    int domki = 0;/** - ilość domków w polu(0-4)*/
    int koszt_domku = koszt*0.2;/** - kwota potrzebna do zakupu domku*/
    public:
    /**
     * @brief Kostruktor pola
     * @param własciciel pola
     * @param nazwa pola
     * @param koszt pola
     */
    Posiadlosc(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
    /**
     * @brief kupuje pole graczowi
     * @param gracz, który będzie właścicielem pola
     */
    void kup_pole(Gracz &gracz);
    /**
     * @brief sprzedaje pole graczowi
     * @param gracz, który był właścicielem pola
     */
    void sprzedaj_pole(Gracz &gracz);
    /**
     * @brief kupuje domek na polu
     * @param gracz, który jest właścicielem
     */
    void kup_domek(Gracz &gracz);
    /**
     * @brief sprzedaje domek na polu
     * @param gracz, który jest właścicielem
     */
    void sprzedaj_domek(Gracz &gracz);
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz, który wszedł na pole
     * @param wektor graczy
     * @param wektor pól
     * @param tekst w sfml, w którym wyświetlamy
     */
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) override;
};
class Specjalna : public Pole
{
    public:
    /**
     * @brief Kostruktor pola
     * @param własciciel pola
     * @param nazwa pola
     * @param koszt pola
     */
    Specjalna(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
    /**
     * @brief sprzedaje pole graczowi
     * @param gracz, który był właścicielem pola
     */
    void kup_pole(Gracz &gracz);
    /**
     * @brief kupuje domek na polu
     * @param gracz, który jest właścicielem
     */
    void sprzedaj_pole(Gracz &gracz);
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz, który wszedł na pole
     * @param wektor graczy
     * @param wektor pól
     * @param tekst w sfml, w którym wyświetlamy
     */
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<shared_ptr<Pole>> &pola,sf::Text &tekst) override;
};

#endif // POLE_H
