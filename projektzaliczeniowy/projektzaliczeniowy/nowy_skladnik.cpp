#include "nowy_skladnik.h"
#include "stats.h"
#include "akcja.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
nowy_skladnik::nowy_skladnik(petla& p1, zmienne& z1) :p1(p1), z1(z1), o1(0, 0, "nowy_skladnik_tlo.png"), o2(682, 380,"mleko_oblokowano.png"), t1(145, 243, "Nowy skladnik to: ", Color::White, 60),
g1(1471, 867, "nowy_shop.png", "nowy_shop_zaznaczony.png"){}

void nowy_skladnik::wyswietl(RenderWindow& okno)
{
    o1.rysuj(okno); //tlo
    g1.rysuj(okno); //guzik przejdz dalej
    okno.draw(t1.nap);
    o2.rysuj(okno); //narusj odblokowany skladnik
}
void nowy_skladnik::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy)) //klikniecie przejdz dalej
        {
            p1.zmana_stanu(make_unique<stats>(p1, z1));

        }
    }
}
void nowy_skladnik::logika(float dt, Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
    if (z1.dzien == 4) //mleko jest ustawione domyslnie wiec zaczynamy od jajka
        o2.zmienTeksture("jajko_oblokowano.png");
    if (z1.dzien == 7)
        o2.zmienTeksture("maslo_oblokowano.png");
}