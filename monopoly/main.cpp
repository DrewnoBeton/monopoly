#include <iostream>
#include "monopoly.h"
using namespace std;

int wybor;
bool ruszono = false;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "My window");
    sf::Font font;
    font.loadFromFile("czcionka.ttf");
    sf::Text tekst;
    tekst.setFont(font);
    sf::Clock clock;
    tekst.setCharacterSize(20);
    tekst.setPosition(300, 400);
    tekst.setColor(sf::Color::Black);
    sf::Texture texture;
    if (!texture.loadFromFile("obrazki//plansza_gotowa.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite tlo;
    tlo.setTexture(texture);
    //tlo.setScale(2.0,2.0);
    tlo.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    //todo przerob wektor na set, zeby nie miec duplikatow bo id sie powtarzaja
    //debug
    Gracz gracz1 = Gracz("a",false,21000,40,true);
    Gracz gracz2 = Gracz("a",true,0,0,false);
    Gracz gracz3 = Gracz("a",false,1000,0,false);
    gracze.emplace_back(gracz1);
    gracze.emplace_back(gracz2);
    gracze.emplace_back(gracz2);
    //gracze.emplace_back(gracz3);
    //gracze.emplace_back(gracz3);
    gracze.emplace_back(gracz3);
    //cout << gracze[3].id();
    nowa_gra(gracze,pola);
    debug_wyswietl_graczy(gracze);
    //Posiadlosc test(-1,"b",123,1);
    //test.efekt_na_graczu(gracz1,gracze,pola);
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R)
            {
                if(!ruszono)
                {
                    ruch(gracze[czyja_tura(gracze)],gracze,pola);
                    debug_wyswietl_graczy(gracze);
                    ruszono = true;
                }
                else
                {
                    cout << "Juz wykonales ruch w swojej turze"<<endl;
                    tekst.setString("Juz wykonales ruch w swojej turze");
                }
            }
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::K && ruszono)
            {
                kup_lub_ulepsz_pole(gracze[czyja_tura(gracze)],gracze,pola);
                debug_wyswietl_graczy(gracze);
            }
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::T)
            {
                ustaw_ture(gracze,koniec);
                debug_wyswietl_graczy(gracze);
                ruszono = false;
            }
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D)
            {
                debug_wyswietl_pola(pola);
            }
        }

        // mierzy ile minelo czasu od ostatniego restartu
        sf::Time ile_minelo = clock.restart();
        float czas = ile_minelo.asSeconds();
        //std::cout << czas <<std::endl;


        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(tlo);
        window.draw(tekst);
        for(Gracz &g:gracze)
        {
            g.wyswietl_gracza(window);
        }
        //debug_wyswietl_pola(pola);
        wyswietl_wlascicieli(pola,gracze,window);
        // draw everything here...

        // end the current frame
        //gracz1.wyswietl_gracza(window);
        //gracz2.wyswietl_gracza(window);

        window.display();
    }

    return 0;
}
