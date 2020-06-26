#include <iostream>
#include "gracz.h"
using namespace std;
#ifndef POLE_H
#define POLE_H
/**
 * @brief Klasa abstrakcyjna, sluzy do dziedziczenia przez inne rodzaje pol
 */
class Pole{
    protected:
    /** - identyfikator wlasciciela pola, -1 to bank*/
    int id_wlasciciela_ =-1;
    /** - nazwa pola*/
    string nazwa = "nazwa_pola";
    /** - koszt pola*/
    int koszt;

    public:
    /**
     * @brief Kostruktor pola
     * @param arg_wlasciciel własciciel pola
     * @param arg_nazwa nazwa pola
     * @param arg_koszt koszt pola
     */
    Pole(int arg_wlasciciel,string arg_nazwa,int arg_koszt);
    /**
     * @brief zwraca identyfikator właściciela
     * @return
     */
    virtual int id_wlasciciela();
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz gracz, który wszedł na pole
     * @param arg_gracze wektor graczy
     * @param pola wektor pól
     * @param tekst tekst w sfml, w którym wyświetlamy
     */
    virtual void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola,sf::Text &tekst) =0;
    friend void ruch(Gracz &gracz,vector<Gracz> &gracze,vector<unique_ptr<Pole>> &pola,sf::Text &tekst);
    /**
     * @brief zwraca nazwę pola
     * @return
     */
    string nazwap();

};
/**
 * @brief Pole neutralne
 */
class Neutralne : public Pole
{
    public:
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz gracz, który wszedł na pole
     * @param arg_gracze wektor graczy
     * @param pola wektor pól
     * @param tekst tekst w sfml, w którym wyświetlamy
     */
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola,sf::Text &tekst) override;
    /**
     * @brief Kostruktor pola
     * @param arg_wlasciciel własciciel pola
     * @param arg_nazwa nazwa pola
     * @param arg_koszt koszt pola
     */
    Neutralne(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
};
/**
 * @brief Pole typu posiadlosc
 */
class Posiadlosc : public Pole
{
    /** - ilość domków w polu(0-4)*/
    int domki = 0;
    /** - kwota potrzebna do zakupu domku*/
    int koszt_domku = koszt*0.2;
    public:
    /**
     * @brief Kostruktor pola
     * @param arg_wlasciciel własciciel pola
     * @param arg_nazwa nazwa pola
     * @param arg_koszt koszt pola
     */
    Posiadlosc(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
    /**
     * @brief kupuje pole graczowi
     * @param gracz gracz, który będzie właścicielem pola
     */
    void kup_pole(Gracz &gracz);
    /**
     * @brief sprzedaje pole graczowi
     * @param gracz gracz, który był właścicielem pola
     */
    void sprzedaj_pole(Gracz &gracz);
    /**
     * @brief kupuje domek na polu
     * @param gracz gracz, który jest właścicielem
     */
    void kup_domek(Gracz &gracz);
    /**
     * @brief sprzedaje domek na polu
     * @param gracz gracz, który jest właścicielem
     */
    void sprzedaj_domek(Gracz &gracz);
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz gracz, który wszedł na pole
     * @param arg_gracze wektor graczy
     * @param pola wektor pól
     * @param tekst tekst w sfml, w którym wyświetlamy
     */
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola,sf::Text &tekst) override;
};
/**
 * @brief Pole specjalne(dworce)
 */
class Specjalna : public Pole
{
    public:
    /**
     * @brief Kostruktor pola
     * @param arg_wlasciciel własciciel pola
     * @param arg_nazwa nazwa pola
     * @param arg_koszt koszt pola
     */
    Specjalna(int arg_wlasciciel,string arg_nazwa,int arg_koszt) : Pole(arg_wlasciciel,arg_nazwa,arg_koszt){}
    /**
     * @brief sprzedaje pole graczowi
     * @param gracz gracz, który był właścicielem pola
     */
    void kup_pole(Gracz &gracz);
    /**
     * @brief kupuje domek na polu
     * @param gracz gracz, który jest właścicielem
     */
    void sprzedaj_pole(Gracz &gracz);
    /**
     * @brief wykonuje czynności po najechaniu gracza na pole
     * @param gracz gracz, który wszedł na pole
     * @param arg_gracze wektor graczy
     * @param pola wektor pól
     * @param tekst tekst w sfml, w którym wyświetlamy
     */
    void efekt_na_graczu(Gracz &gracz, vector<Gracz> &arg_gracze, vector<unique_ptr<Pole>> &pola,sf::Text &tekst) override;
};

#endif // POLE_H
