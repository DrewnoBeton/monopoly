#include "pole.h"
#include <typeinfo>
//Pole
Pole::Pole(int arg_wlasciciel,string arg_nazwa,int arg_koszt)
{
   id_wlasciciela_ = arg_wlasciciel;
   nazwa=arg_nazwa;
   koszt=arg_koszt;
}
int Pole::id_wlasciciela()
{
    return id_wlasciciela_;
}

string Pole::nazwap()
{
    return nazwa;
}

//Neutralne
void Neutralne::efekt_na_graczu(Gracz &gracz, vector<Gracz> &gracze, vector<unique_ptr<Pole>> &pola,sf::Text &tekst)
{
    cout << "pole neutralne";
    //pole neutralne, tu bedzie wialo nuda
}

//Posiadlosc
void Posiadlosc::kup_domek(Gracz &gracz)
{
    if(domki+1>4) return;
    else
    {
        domki++;
        gracz.zaplac(koszt_domku);
    }
}
void Posiadlosc::sprzedaj_domek(Gracz &gracz)
{
    if(domki-1<0) return;
    else
    {
        domki--;
        gracz.otrzymaj(koszt_domku);
    }
}
void Posiadlosc::efekt_na_graczu(Gracz &gracz, vector<Gracz> &gracze, vector<unique_ptr<Pole>> &pola,sf::Text &tekst)
{
    if(id_wlasciciela_==-1)
    {
        cout << "To pole banku, mozesz je kupic." <<endl;
    }
    else if(id_wlasciciela_==gracz.id())
    {
        cout << "To twoje pole!" <<endl;
        return;
    }
    if(id_wlasciciela_ != -1)
    {
        cout << "Zaplaciles graczowi: " << id_wlasciciela_ << " kwote " << koszt*(0.1*(domki+1)) << "$" <<endl;
        gracz.zaplac(koszt*(0.1*(domki+1)),gracze[id_wlasciciela_]);
        tekst.setString("Zaplaciles graczowi: " + to_string(id_wlasciciela_) + " kwote " + to_string(int(koszt*(0.1*(domki+1)))) + "$");
    }

}
void Posiadlosc::kup_pole(Gracz &gracz)
{
    if(id_wlasciciela_==-1)
    {
        gracz.zaplac(koszt);
        id_wlasciciela_ = gracz.id();
        cout << "Kupiles pole"  << nazwa << " za kwote" << koszt << "$" <<endl;
    }
    else if(id_wlasciciela_==gracz.id())
    {
        cout << "Juz kupiles to pole!" <<endl;
        return;
    }
    else
    {
        cout << "To juz czyjes pole, nie mozesz go kupic." <<endl;
        return;
    }
}
void Posiadlosc::sprzedaj_pole(Gracz &gracz)
{
    if(id_wlasciciela_==gracz.id())
    {
        id_wlasciciela_ = -1;
        gracz.otrzymaj(koszt);
        domki = 0;
        cout << "Sprzedales pole"  << nazwa << " za kwote" << koszt << "$" <<endl;
        return;
    }
}

//Specjalna
void Specjalna::kup_pole(Gracz &gracz)
{
    if(id_wlasciciela_==-1)
    {
        gracz.zaplac(koszt);
        id_wlasciciela_ = gracz.id();
        cout << "Kupiles pole"  << nazwa << " za kwote" << koszt << "$" <<endl;
    }
    else if(id_wlasciciela_==gracz.id())
    {
        cout << "Juz kupiles to pole!" <<endl;
        return;
    }
    else
    {
        cout << "To juz czyjes pole, nie mozesz go kupic." <<endl;
        return;
    }
}
void Specjalna::sprzedaj_pole(Gracz &gracz)
{
    if(id_wlasciciela_==gracz.id())
    {
        id_wlasciciela_ = -1;
        gracz.otrzymaj(koszt);
        cout << "Sprzedales pole"  << nazwa << " za kwote" << koszt << "$" <<endl;
        return;
    }
}
void Specjalna::efekt_na_graczu(Gracz &gracz, vector<Gracz> &gracze, vector<unique_ptr<Pole>> &pola,sf::Text &tekst)//do naprawy
{

    if(id_wlasciciela_==-1)
    {
        cout << "To pole banku, mozesz je kupic." <<endl;
    }
    else if(id_wlasciciela_==gracz.id())
    {
        cout << "To twoje pole!" <<endl;
        return;
    }
    else
    {
        int wielokrotnosc = 1;
        for(int el:gracze[id_wlasciciela()].posiadane_pola)
        {
            if(pola[el]->id_wlasciciela() == gracze[id_wlasciciela()].id())
            {
                if(typeid(pola[el]).name() == typeid(Specjalna).name())
                wielokrotnosc++;
            }
        }
        cout << "Wlasciciel pola ma "<< wielokrotnosc << " pol tego rodzaju." <<endl;
        cout << "Zaplaciles graczowi: " << id_wlasciciela_ << " kwote " << koszt*wielokrotnosc << "$" <<endl;
        gracz.zaplac(koszt*wielokrotnosc,gracze[id_wlasciciela_]);
        tekst.setString("Zaplaciles graczowi: " + to_string(id_wlasciciela_) + " kwote " + to_string(koszt*wielokrotnosc) + "$");
    }
}
