#include "stats.h"
#include "Na1.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
stats::stats(petla& p1) :p1(p1), t1(200, 200, "monety:") , g1(400, 400, "tg1.png"), t2(200, 240, "maka:")
{
arial.loadFromFile("ArialCE.ttf");
}
void stats::wyswietl(RenderWindow& okno)
{
    t1.nap.setString("monety:" + to_string(z1.monety));
    t2.nap.setString("maka:" + to_string(z1.maka));
	okno.draw(t1.nap);
	okno.draw(g1.guzikson);
    okno.draw(t2.nap);
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



    }
}
void stats::logika(float dt)
{

}