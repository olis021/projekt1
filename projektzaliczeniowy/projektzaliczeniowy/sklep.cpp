#include "sklep.h"
#include "Na1.h"
#include "akcja.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
sklep::sklep(petla& p1, zmienne& z1) :p1(p1), z1(z1), o1(0, 0, "shop_tlo.png"), g1(1471, 867, "sklep_play.png", "sklep_play_zaznaczony.png") {}

void sklep::wyswietl(RenderWindow& okno)
{
    o1.rysuj(okno);
    g1.rysuj(okno);
}
void sklep::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);

        if (g1.p1(pozycjamyszy))
        {
            p1.zmana_stanu(make_unique<akcja>(p1, z1));
        }
    }
}
void sklep::logika(float dt, Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
}