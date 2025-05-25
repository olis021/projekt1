#include "sklep.h"
#include "Na1.h"
#include "stats.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
sklep::sklep(petla& p1, zmienne& z1) :p1(p1), z1(z1), o1(0, 0, "shop_tlo.png"), g1(1471, 867, "sklep_play.png", "sklep_play_zaznaczony.png"), g2(420, 200, "tg1.png", "tg1.png"), t1(200, 200, "monety:", Color::White, 30)
{}

void sklep::wyswietl(RenderWindow& okno)
{
    t1.nap.setString("monety:" + to_string(z1.monety));
    o1.rysuj(okno);
    g1.rysuj(okno);
    g2.rysuj(okno);
    okno.draw(t1.nap);

}
bool zaplacone = false;
void sklep::obsluga_zdarzen(Event& e, RenderWindow& okno)
{

    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        if (z1.dzien == 1) 
        {
            zaplacone = true;
        }
        Vector2i pozycjamyszy = Mouse::getPosition(okno);

        if (g2.p1(pozycjamyszy) && z1.dzien >1 && !zaplacone)
        {
            z1.zaplacpodatek(z1.dzien);
            zaplacone = true;
        }
        if (g1.p1(pozycjamyszy) && zaplacone)
        {
            p1.zmana_stanu(make_unique<stats>(p1, z1));
            zaplacone = false;
        }
    }
}
void sklep::logika(float dt, Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
}