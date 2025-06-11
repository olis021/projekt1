#include "menu.h"
#include "ustawienia.h"
#include "Na1.h"
#include "petla.h"
#include "kontrolki.h"
using namespace std;
using namespace sf;
menu::menu(petla& p1) :p1(p1), o2(0, 0, "menu_background.png"), g1(986, 305, "play_menu_button.png","play_menu_button_zaznaczony.png"), 
g2(986, 529, "quit_menu_button.png", "quit_menu_button_zaznaczony.png"), g3(986, 417, "menu_controls.png", "menu_controls_zaznaczony.png") {}

void menu::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy)) //guzik play
            p1.zmana_stanu(make_unique<ustawienia>(p1));
        if (g2.p1(pozycjamyszy)) //guzik quit
            okno.close();
        if(g3.p1(pozycjamyszy)) //guzik constrols - instrukcja gry
            p1.zmana_stanu(make_unique<kontrolki>(p1));
    }
}
void menu::wyswietl(RenderWindow& okno)
{
    o2.rysuj(okno);
    g1.rysuj(okno);
    g2.rysuj(okno);    
    g3.rysuj(okno);
}
void menu::logika(float dt,Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
    g2.wskaznikGuzik(pozycjamyszy);
    g3.wskaznikGuzik(pozycjamyszy);
}