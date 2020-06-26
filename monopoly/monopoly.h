#include <iostream>
#include <vector>

#include "gracz.h"
#include "pole.h"
using namespace std;
#ifndef MONOPOLY_H
#define MONOPOLY_H

/**
 * @brief (DEBUG) funkcja zwracająca 877, używana by sprawdzić czy funkcje poprawnie się wykonują
 * @return
 */
int test();
/**
 * @brief tworzy nową grę
 * @param gracze wektor graczy
 * @param pola wektor pól
 * @param ilosc ilość graczy dla ilu będzie gra
 */
void nowa_gra(vector<Gracz> &gracze,vector<unique_ptr<Pole>> &pola,int &ilosc);
/**
 * @brief tworzy nową planszę, wczytując ją z pliku .txt
 * @param pola wektor pól
 */
void nowa_plansza(vector<unique_ptr<Pole>> &pola);
/**
 * @brief zwraca identyfikator gracza, który ma turę
 * @param gracze wektor graczy
 * @return
 */
int czyja_tura(vector<Gracz> &gracze);
/**
 * @brief ustawia turę kolejnemu graczowi, który nie jest bankrutem
 * przy okazji usuwa ewentualne błędy w systemie tur
 * @param gracze wektor graczy
 * @param koniec warunek na koniec gry
 */
void ustaw_ture(vector<Gracz> &gracze, bool &koniec);
/**
 * @brief (DEBUG) wyświetla statystyki graczy w konsoli
 * @param gracze wektor graczy
 */
void debug_wyswietl_graczy(vector<Gracz> &gracze);
/**
 * @brief (DEBUG) wyświetla parametry pól w konsoli
 * @param pola wektor pól
 */
void debug_wyswietl_pola(vector<unique_ptr<Pole>> &pola);
/**
 * @brief wyświetla prostokąty przy polach w kolorze jego właściciela(w przypadku banku przeźroczyste)
 * @param pola wektor pól
 * @param gracze wektor graczy
 * @param window okno sfml, w którym działamy
 */
void wyswietl_wlascicieli(vector<unique_ptr<Pole>> &pola,vector<Gracz> &gracze,sf::RenderWindow &window);
/**
 * @brief wyświetla statystyki graczy(identyfikator i stan konta)
 * @param gracze wektor graczy
 * @param tekst tekst w sfml, w którym wyświetlamy
 */
void wyswietl_statystyki(vector<Gracz> &gracze,sf::Text &tekst);
/**
 * @brief funkcja odpowiadająca za ruch gracza w jego turze
 * @param gracz gracz, którego jest tura
 * @param gracze wektor graczy
 * @param pola wektor pól
 * @param teskt tekst w sfml, w którym wyświetlamy
 */
void ruch(Gracz &gracz,vector<Gracz> &gracze,vector<unique_ptr<Pole>> &pola,sf::Text &tekst);
/**
 * @brief kupuje lub ulepsza pole
 * @param gracz gracz
 * @param gracze wektor graczy
 * @param pola wektor pól
 * @param tekst tekst, w którym wyświetlimy monity
 */
void kup_lub_ulepsz_pole(Gracz &gracz,vector<Gracz> &gracze,vector<unique_ptr<Pole>> &pola,sf::Text &tekst);
#endif // MONOPOLY_H
