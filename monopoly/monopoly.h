#include <iostream>
#include <vector>
#include "gracz.h"
#include "pole.h"
using namespace std;
#ifndef MONOPOLY_H
#define MONOPOLY_H
vector<Gracz> gracze;
vector<Pole> pola;
bool koniec=false;
int test();
void nowa_gra(vector<Gracz> &gracze,vector<Pole> &pola);
void nowa_plansza(vector<Pole> &pola);
void ustaw_ture(vector<Gracz> &gracze, bool &koniec);
void wyswietl_graczy(vector<Gracz> &gracze);
#endif // MONOPOLY_H
