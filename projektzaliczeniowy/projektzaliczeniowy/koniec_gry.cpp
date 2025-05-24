#include "koniec_gry.h"
#include "Na1.h"
#include "akcja.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
end::end(petla& p1) :p1(p1), o1(0, 0, "end_game_tlo.png"), g1(1471, 867, "koniec_quit.png", "koniec_quit_zaznaczony.png"), t1() {}

void end::wyswietl(RenderWindow& okno)
{
    o1.rysuj(okno);
    g1.rysuj(okno);
}
void end::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);

        if (g1.p1(pozycjamyszy))
        {
            okno.close();
        }
    }
}
void end::logika(float dt, Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
}
