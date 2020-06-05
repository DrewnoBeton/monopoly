#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gracz.h"
#include "pole.h"
using namespace std;
#ifndef MONOPOLY_H
#define MONOPOLY_H
vector<Gracz> gracze;
vector<shared_ptr<Pole>> pola;
bool koniec=false;
int test();
void nowa_gra(vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola);
void nowa_plansza(vector<shared_ptr<Pole>> &pola);
int czyja_tura(vector<Gracz> &gracze);
void ustaw_ture(vector<Gracz> &gracze, bool &koniec);
void wyswietl_graczy(vector<Gracz> &gracze);
void ruch(Gracz &gracz,vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola);

#endif // MONOPOLY_H
