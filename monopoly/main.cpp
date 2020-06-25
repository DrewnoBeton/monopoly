#include "menu.h"
Menu menu;
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Monopoly");
    menu.przygotuj_okno(window);
    while (window.isOpen())
    {
        menu.sterowanie(window);
        menu.wyswietl(window);
    }
    return 0;
}
