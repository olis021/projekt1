#include "stats.h"
#include "Na1.h"
#include "akcja.h"
#include "sklep.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
stats::stats(petla& p1, zmienne& z1) :p1(p1), z1(z1), t1(200, 200, "monety:", Color::White, 30), o1(0, 0, "shop_tlo.png"),
t4(200, 280, "drozdze:", Color::White, 30), t5(200, 320, "mleko:", Color::White, 30), g3(400, 500, "guzik_plus.png", "guzik_plus.png"), g4(400, 600, "guzik_plus.png", "guzik_plus.png"), g5(400, 700, "guzik_plus.png", "guzik_plus.png"), g6(400, 800, "guzik_plus.png", "guzik_plus.png"), g7(400, 900, "guzik_plus.png", "guzik_plus.png"),
t6(200, 360, "woda:", Color::White, 30), t7(200, 400, "jajka:", Color::White, 30), t8(200, 440, "maslo:", Color::White, 30),
g1(400, 400, "guzik_plus.png", "guzik_plus.png"), t2(200, 240, "maka:", Color::White, 30), g2(1471, 867, "sklep_play.png", "sklep_play_zaznaczony.png"), t3(450, 60, "dzien:", Color::White, 30) {}
void stats::wyswietl(RenderWindow& okno)
{
    t1.nap.setString("monety:" + to_string(z1.monety));
    t2.nap.setString("maka:" + to_string(z1.maka));
    t3.nap.setString("dzien: " + to_string(z1.dzien));
    t4.nap.setString("drozdze: " + to_string(z1.drozdze));
    t5.nap.setString("mleko " + to_string(z1.mleko));
    t6.nap.setString("woda: " + to_string(z1.woda));
    t7.nap.setString("jajka: " + to_string(z1.jajka));
    t8.nap.setString("maslo: " + to_string(z1.maslo));
    o1.rysuj(okno);
    okno.draw(t2.nap);
    g2.rysuj(okno);
    g1.rysuj(okno);
    g3.rysuj(okno);
    g4.rysuj(okno);
    g5.rysuj(okno);
    g6.rysuj(okno);
    g7.rysuj(okno);
	okno.draw(t1.nap);
    okno.draw(t3.nap);
    okno.draw(t4.nap);
    okno.draw(t5.nap);
    okno.draw(t6.nap);
    okno.draw(t7.nap);
    okno.draw(t8.nap);
}
void stats::obsluga_zdarzen(Event& e,RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy))
        {
            if (z1.monety >= 1) {
                z1.kupmake();
            }
            
        }
        if (g3.p1(pozycjamyszy))
        {
            if (z1.monety >= 1)
            {
                z1.kupdrozdze();
            }
        }
        if (g4.p1(pozycjamyszy))
        {
            if (z1.monety >= 1)
            {
                z1.kupmleko();
            }
        }
        if (g5.p1(pozycjamyszy))
        {
            if (z1.monety >= 1)
            {
                z1.kupwode();
            }
        }
        if (g6.p1(pozycjamyszy))
        {
            if (z1.monety >= 1)
            {
                z1.kupjajko();
            }
        }
        if (g7.p1(pozycjamyszy))
        {
            if (z1.monety >= 1)
            {
                z1.kupmaslo();
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