# monopoly

#### Opis instalacji:
Kod źródłowy znajduje się w folderze monopoly, reszta niezbędnych plików w folderze "build-monopoly-Desktop_Qt_5_13_2_MinGW_64_bit-Debug"
Nie używałem żadnych dodatkowych bibliotek poza tymi z SFML.
Gra wymaga conajmniej c++17

#### Sterowanie: 
Po uruchomieniu gry by stworzyć nową grę klikamy N, wtedy tworzy się gra dla dwóch graczy
Jeżeli chcemy grać w więcej osób, klikamy D by dodać kolejną(tutaj proszę o cierpliwość, ponieważ licznik ma opóźnienia)

W trakcie gry sterowanie mamy wyjaśnione z prawej strony planszy pod MOŻLIWE AKCJE
Może to być jedna z trzech akcji:
- T kończy turę
- R rzuca kostką i przesuwa pionek o wyrzuconą liczbę
- K kupuje lub ulepsza pole jesli jest posiadane(i typem Posiadlosc)
Jest jeszcze ukryta opcja D, ona wyświetla stan mapy w konsoli

#### Film instruktażowy: https://youtu.be/WXIhpMK-J4g

#### Dokumentacja: 
Dokumentacja znajduje się w folderze dokumentacja/html/index.html
Jest ona w postaci rozbudowanej strony html. 

#### Opis gry:
Rozgrywka jest przeznaczona od 2 do 8 graczy.(ze względu na czytelność)
Każdy gracz oznaczony jest swoim unikalnym kolorem, są oni pokazani na planszy w odpowieddnich polach w postaci okrągłych pionków.

Plansza została przygotowana w osobnym programie graficznym, specjalnie dla potrzeb gry, w grze jest ona wyświetlana jako tło.

Zarówno gracze jak i pola są przechowywani jako obiekty odpowiadających im klas.

Gra posiada zaawansowany system tur, nie ustawi ona tury bankrutowi lub kilku graczom jednocześnie, a jesli tak będzie to czyści ona dane i ustawia ją pierwszemu graczowi ktory nie jest bankrutem.
Zabezpieczone również zostały: ruch, wyświetlanie, płatności i operacje na polach.

Gra trwa dopóki tylko jeden z graczy nie będzie bankrutem.
Gracz ten wygrywa grę.

Jako, że rozgrywka w Monopoly może być długa(oryginalna planszowa wersja potrafi trwać godzinami),
zalecam testowanie gry przy małej ilości graczy.

#### Stary opis gry z moodle
Moją propozycją na projekt jest gra typu Monopoly.

Jest to dość popularna gra, lecz gwoli ścisłości wyjaśnię na czym polega.
Gracze zaczynają z pewną startową ilością pieniędzy i celem gry jest te pieniądze przy sobie utrzymać, a przynajmniej nie zbankrutować oraz być najbogatszym spośród innych graczy.
Plansza składa się z 40 różnych pól i są to:
- pola neutralne(nic się na nich nie traci ani nie zyskuje, nie można ich kupić)
- zwykłe posiadłości: to pole można kupić, tylko jeden gracz może je posiadać, i jego właściciel pobiera czynsz za wejście kogoś na jego pole.
Pole to można ulepszać by pobierać wyższy czynsz.
- specjalne posiadłości: różnią się od zwykłych tym, że aby ulepszyć to pole trzeba kupić inne z tej samej grupy.
- pole startowe: za każdym razem(poza pierwszym) otrzymujemy pieniądze za przekroczenie go

Jak wygląda rozgrywka:

Gracze rzucają kostkami i poruszają się o wyrzuconą ilość pól.
Jeśli pole jest dostępne do kupienia to może je kupić. Jeśli to jego pole, ulepszyć.
Jeśli to czyjeś pole to płaci mu czynsz. I tak dopóki nie zbankrutują wszyscy poza zwycięzcą.

Aplikacja:
Plansza będzie wyświetlana z góry, w SFML
Gracze będą "dynamiczni", będzie można ich dodawać, edytować, usuwać(oczywiście nie dodawać i usuwać w trakcie, to by się mijało z celem gry)
Własne grafiki i efekty dźwiękowe.
 
Grę obsługiwać będziemy za pomocą klawiatury

Autor gry: Marcin Brończyk A1
