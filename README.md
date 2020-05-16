# monopoly
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
Będzie rozbudowane menu pozwalające na wszytskie transakcje między graczami i bankiem.
Gracze będą "dynamiczni", będzie można ich dodawać, edytować, usuwać(oczywiście nie dodawać i usuwać w trakcie, to by się mijało z celem gry)
Zapis obecnego stanu gry do pliku, odczyt dawnych gier.
Własne grafiki i efekty dźwiękowe.
 
Grę obsługiwać będziemy za pomocą myszki i klawiatury(zależy co uznam za wygodniejsze do płatności, być może wyłącznie myszki)

Być może rozwinę projekt bardziej, lecz teraz ciężko o czas.
