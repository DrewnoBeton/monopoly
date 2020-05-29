#include <iostream>
#include "monopoly.h"
using namespace std;

int main()
{
    Gracz gracz1 = Gracz("a",false,0,0,false);
    Gracz gracz2 = Gracz("a",false,0,0,false);
    Gracz gracz3 = Gracz("a",false,0,0,false);
    cout << gracz1.id() <<gracz2.id() <<gracz3.id();
    return 0;
}
