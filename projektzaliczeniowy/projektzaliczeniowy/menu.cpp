#include "menu.h"
#include "ustawienia.h"
#include "Na1.h"
#include "petla.h"
using namespace std;
using namespace sf;
menu::menu(petla& p1) :p1(p1), o2(0, 0, "menu_background.png"), g1(986, 305, "play_menu_button.png","play_menu_button_zaznaczony.png"), g2(986, 417, "quit_menu_button.png", "quit_menu_button_zaznaczony.png") {}

void menu::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy))
        {
            p1.zmana_stanu(make_unique<ustawienia>(p1));
        }
        if (g2.p1(pozycjamyszy))
        {
            okno.close();
        }
    }
}
void menu::wyswietl(RenderWindow& okno)
{
    o2.rysuj(okno);
    g1.rysuj(okno);
    g2.rysuj(okno);    
}
void menu::logika(float dt,Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
    g2.wskaznikGuzik(pozycjamyszy);
}