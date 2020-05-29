#include <iostream>
#include <vector>
#include "gracz.h"
#include "pole.h"
using namespace std;
#ifndef MONOPOLY_H
#define MONOPOLY_H
vector<Gracz> gracze;
vector<Pole> pola;
int test();
void nowa_gra(vector<Gracz> &gracze,vector<Pole> &pola);
void nowa_plansza(vector<Pole> &pola);
#endif // MONOPOLY_H
