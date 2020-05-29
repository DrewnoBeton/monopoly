#include "monopoly.h"
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
void Pole::efekt_na_graczu(Gracz &gracz, vector<Gracz> &gracze)
{
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
void Posiadlosc::efekt_na_graczu(Gracz &gracz, vector<Gracz> &gracze)//do naprawy
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
    cout << "Zaplaciles graczowi: " << id_wlasciciela_ << " kwote " << koszt*(0.1*domki) << "$" <<endl;
    gracz.zaplac(koszt*(0.1*domki),gracze[id_wlasciciela_]);

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
