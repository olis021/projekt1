#include "menu.h"
#include "ustawienia.h"
#include "Na1.h"
#include "petla.h"
using namespace std;
using namespace sf;

menu::menu(petla& p1) :p1(p1), o2(350, 100, "menugowne.png"), g1(450, 300, "start.png")
{

}
void menu::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy))
        {
            p1.zmana_stanu(make_unique<ustawienia>(p1));
        }
      


    }
}
void menu::wyswietl(RenderWindow& okno)
{
    okno.draw(o2.guzikson);
    okno.draw(g1.guzikson);
    
}
void menu::logika(float dt,Event& e)
{

}