#include "monopoly.h"
//Pole
Pole::Pole(int arg_wlasciciel,string arg_nazwa,int arg_koszt)
{
   id_wlasciciel = arg_wlasciciel;
   nazwa=arg_nazwa;
   koszt=arg_koszt;
}
int Pole::id_wlasciciela()
{
    return id_wlasciciel;
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

        if(find(gracze.begin(),gracze.end(),gracz))
        {
            cout << "To twoje pole!"<<endl;
            return;
        }

    cout << "Zaplaciles graczowi: " << this->id_wlasciciela() << " kwote " << koszt*(0.1*domki) << "$" <<endl;
    gracz.zaplac(koszt*(0.1*domki),gracze[this->id_wlasciciela()]);

}
