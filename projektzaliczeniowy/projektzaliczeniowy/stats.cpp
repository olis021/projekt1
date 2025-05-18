#include "stats.h"
#include "Na1.h"
#include "akcja.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
stats::stats(petla& p1,zmienne& z1) :p1(p1),z1(z1), t1(200, 200, "monety:"), g1(400, 400, "tg1.png"), t2(200, 240, "maka:"), g2(800, 600, "tg1.png"),t3(450,100,"dzien:")
{

}
void stats::wyswietl(RenderWindow& okno)
{
    t1.nap.setString("monety:" + to_string(z1.monety));
    t2.nap.setString("maka:" + to_string(z1.maka));
    t3.nap.setString("dzien: " + to_string(z1.dzien));
	okno.draw(t1.nap);
	okno.draw(g1.guzikson);
    okno.draw(t2.nap);
    okno.draw(g2.guzikson);
    okno.draw(t3.nap);
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
        if (g2.p1(pozycjamyszy))
        {
            p1.zmana_stanu(make_unique<akcja>(p1,z1));
        }


    }
}
void stats::logika(float dt,Event& e)
{

}