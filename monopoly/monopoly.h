#include <iostream>
#include <vector>

#include "gracz.h"
#include "pole.h"
using namespace std;
#ifndef MONOPOLY_H
#define MONOPOLY_H
/*vector<Gracz> gracze;
vector<shared_ptr<Pole>> pola;
vector <sf::Sprite> pionki;
bool koniec=false;
bool menu = true;
int ilosc =2;*/
int test();
void nowa_gra(vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola,int &ilosc);
void nowa_plansza(vector<shared_ptr<Pole>> &pola);
int czyja_tura(vector<Gracz> &gracze);
void ustaw_ture(vector<Gracz> &gracze, bool &koniec);
void debug_wyswietl_graczy(vector<Gracz> &gracze);
void debug_wyswietl_pola(vector<shared_ptr<Pole>> &pola);
void wyswietl_wlascicieli(vector<shared_ptr<Pole>> &pola,vector<Gracz> &gracze,sf::RenderWindow &window);
void wyswietl_statystyki(vector<Gracz> &gracze,sf::Text &tekst);
void ruch(Gracz &gracz,vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola,sf::Text &tekst);
void kup_lub_ulepsz_pole(Gracz &gracz,vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola,sf::Text &tekst);
#endif // MONOPOLY_H
