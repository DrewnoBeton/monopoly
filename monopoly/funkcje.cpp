#include "gracz.h"
#include "pole.h"
//#include <memory>
int test(){
    return 887;
}
void nowa_plansza(vector<shared_ptr<Pole>> &pola)//tu trzeba zrobic wektor shared pointerow x d, nie wiem czego to ja nie porusze w tym projekcie
{
    if(!pola.empty()) pola.clear();
    //grupy 1-zadupie, 2-wioska, 3-wies, 4-duza wies, 5-miasteczko, 6-male miasto, 7-miasto, 8-metropolia
    pola.emplace_back(make_shared<Neutralne>(-1,"start",9999999));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"zadupie1",200,1));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"zadupie2",200,1));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"zadupie3",200,1));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"zadupie4",200,1));
    pola.emplace_back(make_shared<Specjalna>(-1,"dworzec1",750));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wioska1",400,2));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wioska2",400,2));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wioska3",400,2));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wioska4",400,2));
    pola.emplace_back(make_shared<Neutralne>(-1,"parking1",9999999)); //10
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wies1",600,3));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wies2",600,3));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wies3",600,3));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"wies4",600,3));
    pola.emplace_back(make_shared<Specjalna>(-1,"dworzec2",750));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"duza_wies1",800,4));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"duza_wies2",800,4));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"duza_wies3",800,4));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"duza_wies4",800,4));
    pola.emplace_back(make_shared<Neutralne>(-1,"parking2",9999999)); //20
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasteczko1",1000,5));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasteczko2",1000,5));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasteczko3",1000,5));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasteczko4",1000,5));
    pola.emplace_back(make_shared<Specjalna>(-1,"dworzec3",750));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"male_miasto1",1200,6));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"male_miasto2",1200,6));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"male_miasto3",1200,6));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"male_miasto4",1200,6));
    pola.emplace_back(make_shared<Neutralne>(-1,"parking3",9999999)); //30
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasto1",1400,7));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasto2",1400,7));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasto3",1400,7));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"miasto4",1400,7));
    pola.emplace_back(make_shared<Specjalna>(-1,"dworzec4",750));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"metropolia1",1600,8));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"metropolia2",1600,8));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"metropolia3",1600,8));
    pola.emplace_back(make_shared<Posiadlosc>(-1,"metropolia4",1600,8));
    cout << "Utworzono nowa plansze!" <<endl;
}
void nowa_gra(vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola)//do dokonczenia
{
    int ilu_graczy = 4;
    int kwota_start = 5000;
    string nazwa = "nazwa_gracza";
    /*for(int i=0; i<ilu_graczy;i++)
    {
        Gracz g(nazwa,false,kwota_start,0,false);
        gracze.emplace_back(g);
    }*/
    nowa_plansza(pola);

    //gracze[0].tura=true;
}
int czyja_tura(vector<Gracz> &gracze)
{
        bool znaleziono = false;
        int i=0;
        for(Gracz &g:gracze) //to szuka gracza z tura
        {
            if(g.tura && !g.czy_bankrut())
            {
                znaleziono = true;
                break;
            }
            i++;
        }
        if(!znaleziono)
        {
            i=0;
        }
        //cout << "gracz z tura: " << i <<endl;
        return i;
}
void ustaw_ture(vector<Gracz> &gracze, bool &koniec)
{
    int i=0;
    int poprzednia_tura = czyja_tura(gracze);
    i=czyja_tura(gracze);
    for(int licznik=0;licznik<gracze.size();licznik++)
    {
        cout << i <<": \n";
        if(i+1<gracze.size())
        {
            i++;
            cout << "zwiekszam" <<endl;
            if(!gracze[i].czy_bankrut())
            {
                cout << "bingo!:" << i <<endl;
                if(i == poprzednia_tura) koniec = true;
                for(Gracz &g:gracze)g.tura = false;
                gracze[i].tura = true;
                return;
            }
        }
        else
        {
            cout << "za daleko, wracamy do zera"<<endl;
            i=0;
            if(!gracze[i].czy_bankrut())
            {
                cout << "bingo!" << i <<endl;
                if(i == poprzednia_tura) koniec = true;
                for(Gracz &g:gracze)g.tura = false;
                gracze[i].tura = true;
                return;
            }
            //i=i-gracze.size()+1;
            //cout << i;
        }
    }
    cout << "Nie znaleziono zadnego nastepnego gracza" << endl;
    koniec = true;
}
void debug_wyswietl_graczy(vector<Gracz> &gracze)
{
    cout << "-------------------------------------\n";
    //cout << "TURA GRACZA: "<< czyja_tura() << " \n";
    for(int i = 0; i < gracze.size(); i++)
    {
        if(gracze[i].czy_bankrut())
        {
            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "| Gracz " << i << " | ";
            cout << gracze[i].nazwa << " | ";
            cout << gracze[i].czy_bankrut() << " | ";
            cout << gracze[i].stan_konta() << " | ";
            cout << gracze[i].gdzie_jest() << " | ";
            cout << gracze[i].tura << " |\n";
            //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else
        {
            cout << "| Gracz " << i << " | ";
            cout << gracze[i].nazwa << " | ";
            cout << gracze[i].czy_bankrut() << " | ";
            cout << gracze[i].stan_konta() << " | ";
            cout << gracze[i].gdzie_jest() << " | ";
            cout << gracze[i].tura << " |\n";
        }
    }
    cout << "-------------------------------------\n";
}
void ruch(Gracz &gracz,vector<Gracz> &gracze,vector<shared_ptr<Pole>> &pola)
{
    int rzut = gracz.rzuc_kostkami();
    cout << "wyrzucono: " <<rzut<<endl;
    gracz.zmien_pozycje(rzut);
    pola[gracz.gdzie_jest()]->efekt_na_graczu(gracz,gracze,pola);
    auto neutralne = dynamic_pointer_cast<Neutralne>(pola[gracz.gdzie_jest()]);
    if(neutralne)
    {
        cout << "Pola neutralnego nie mozesz kupic"<<endl;
    }
    else
    {
        if(pola[gracz.gdzie_jest()]->id_wlasciciela() == -1)
        {
            cout << "Mozesz kupic to pole! Wcisnij K by kupic"<<endl;
            char guzior;
           // cin >> guzior;
            if(guzior == 'k' || guzior == 'K')
            {
                auto posiadlosc = dynamic_pointer_cast<Posiadlosc>(pola[gracz.gdzie_jest()]);
                auto specjalna = dynamic_pointer_cast<Specjalna>(pola[gracz.gdzie_jest()]);
                if(posiadlosc) posiadlosc->kup_pole(gracz);
                else if(specjalna) specjalna->kup_pole(gracz);
            }
        }
        else if(pola[gracz.gdzie_jest()]->id_wlasciciela() == gracz.id())
        {
            cout << "To twoje pole!"<<endl;
            auto posiadlosc = dynamic_pointer_cast<Posiadlosc>(pola[gracz.gdzie_jest()]);
            if(posiadlosc)
            {
                cout << "Mozesz kupic tu domek! Wcisnij U by ulepszyc"<<endl;
                char guzior;
                //cin >> guzior;
                if(guzior == 'u' || guzior == 'U')
                {
                    posiadlosc->kup_domek(gracz);
                }
            }
        }
    }
    //sprawdza czy wszystkie posiadlosci bankrutow juz do nich nie naleza
    for(Gracz &g:gracze)
    {
        if(g.czy_bankrut())
        {
            for(auto &p:pola)
            {
                if(p->id_wlasciciela() ==g.id())
                {
                    p->id_wlasciciela_ = -1;
                }
            }
        }
    }
}
void wyswietl_wlascicieli(vector<shared_ptr<Pole>> &pola,vector<Gracz> &gracze,sf::RenderWindow &window)
{
    int licznik =1;
    sf::RectangleShape pionek;
    pionek.setSize(sf::Vector2f(20,20));
    for(auto p:pola)
    {
        if(p->id_wlasciciela() != -1) pionek.setFillColor(gracze[p->id_wlasciciela()].kolor);
        else pionek.setFillColor(sf::Color::White);
        switch (licznik)
        {
            case 1:
            {
                pionek.setPosition(810,800);
                break;
            }
            case 2:
            {
                pionek.setPosition(720,800);
                break;
            }
            case 3:
            {
                pionek.setPosition(640,800);
                break;
            }
            case 4:
            {
                pionek.setPosition(560,800);
                break;
            }
            case 5:
            {
                pionek.setPosition(480,800);
                break;
            }
            case 6:
            {
                pionek.setPosition(400,800);
                break;
            }
            case 7:
            {
                pionek.setPosition(320,800);
                break;
            }
            case 8:
            {
                pionek.setPosition(250,800);
                break;
            }
            case 9:
            {
                pionek.setPosition(170,800);
                break;
            }
            case 11:
            {
                pionek.setPosition(150,770);
                break;
            }
            case 12:
            {
                pionek.setPosition(150,690);
                break;
            }
            case 13:
            {
                pionek.setPosition(150,610);
                break;
            }
            case 14:
            {
                pionek.setPosition(150,530);
                break;
            }
            case 15:
            {
                pionek.setPosition(150,450);
                break;
            }
            case 16:
            {
                pionek.setPosition(150,370);
                break;
            }
            case 17:
            {
                pionek.setPosition(150,290);
                break;
            }
            case 18:
            {
                pionek.setPosition(150,220);
                break;
            }
            case 19:
            {
                pionek.setPosition(150,150);
                break;
            }
            case 21:
            {
                pionek.setPosition(170,120);
                break;
            }
            case 22:
            {
                pionek.setPosition(250,120);
                break;
            }
            case 23:
            {
                pionek.setPosition(320,120);
                break;
            }
            case 24:
            {
                pionek.setPosition(400,120);
                break;
            }
            case 25:
            {
                pionek.setPosition(480,120);
                break;
            }
            case 26:
            {
                pionek.setPosition(560,120);
                break;
            }
            case 27:
            {
                pionek.setPosition(640,120);
                break;
            }
            case 28:
            {
                pionek.setPosition(720,120);
                break;
            }
            case 29:
            {
                pionek.setPosition(810,120);
                break;
            }
            case 31:
            {
                pionek.setPosition(810,30);
                break;
            }
            case 32:
            {
                pionek.setPosition(910,140);
                break;
            }
            case 33:
            {
                pionek.setPosition(910,220);
                break;
            }
            case 34:
            {
                pionek.setPosition(910,290);
                break;
            }
            case 35:
            {
                pionek.setPosition(910,370);
                break;
            }
            case 36:
            {
                pionek.setPosition(910,450);
                break;
            }
            case 37:
            {
                pionek.setPosition(910,530);
                break;
            }
            case 38:
            {
                pionek.setPosition(910,610);
                break;
            }
            case 39:
            {
                pionek.setPosition(910,690);
                break;
            }
        }
        licznik++;
        window.draw(pionek);
    }

}
