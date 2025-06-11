#include "ustawienia.h"
#include "Na1.h"
#include "petla.h"
#include "stats.h"
using namespace std;
using namespace sf;

ustawienia::ustawienia(petla& p1) :p1(p1), z1(p1.k1), o1(0, 0, "instrukcja.png"), g1(1471, 867, "instrukcja_play.png", "instrukcja_play_zaznaczony.png") {}

void ustawienia::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy)) //instukcja dla gracza po rozpoczeciu rozgrywki
        {
            p1.zmana_stanu(make_unique<stats>(p1,z1));
        }
    }
}
void ustawienia::wyswietl(RenderWindow& okno)
{
    o1.rysuj(okno);
    g1.rysuj(okno);

}
void ustawienia::logika(float dt,Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
}