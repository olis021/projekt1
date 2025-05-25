#include "stats.h"
#include "Na1.h"
#include "akcja.h"
#include "sklep.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
stats::stats(petla& p1, zmienne& z1) :p1(p1), z1(z1), t1(200, 200, "monety:", Color::White, 30), o1(0, 0, "statystyki_tlo.png"),
t4(200, 280, "drozdze:", Color::White, 30), t5(200, 320, "mleko:", Color::White, 30), g3(400, 500, "tg1.png", "tg1.png"), g4(400, 600, "tg1.png", "tg1.png"),
g1(400, 400, "tg1.png", "tg1.png"), t2(200, 240, "maka:", Color::White, 30), g2(1471, 867, "statystyki_next.png", "statystyki_next_zaznaczony.png"), t3(450, 60, "dzien:", Color::White, 30) {}
void stats::wyswietl(RenderWindow& okno)
{
    t1.nap.setString("monety:" + to_string(z1.monety));
    t2.nap.setString("maka:" + to_string(z1.maka));
    t3.nap.setString("dzien: " + to_string(z1.dzien));
    t4.nap.setString("drozdze: " + to_string(z1.drozdze));
    t5.nap.setString("mleko " + to_string(z1.mleko));
    o1.rysuj(okno);
    okno.draw(t2.nap);
    g2.rysuj(okno);
    g1.rysuj(okno);
    g3.rysuj(okno);
    g4.rysuj(okno);
	okno.draw(t1.nap);
    okno.draw(t3.nap);
    okno.draw(t4.nap);
    okno.draw(t5.nap);
}
void stats::obsluga_zdarzen(Event& e,RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy))
        {
            if (z1.monety >= 2) {
                z1.kupmake(2);
            }
            
        }
        if (g3.p1(pozycjamyszy))
        {
            if (z1.monety >= 1)
            {
                z1.kupdrozdze(1);
            }
        }
        if (g4.p1(pozycjamyszy))
        {
            if (z1.monety >= 1)
            {
                z1.kupmleko(1);
            }
        }
        if (g2.p1(pozycjamyszy))
        {
            p1.zmana_stanu(make_unique<akcja>(p1,z1));
        }
    }
}
void stats::logika(float dt, Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g2.wskaznikGuzik(pozycjamyszy);
}