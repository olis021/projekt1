#include "sklep.h"
#include "Na1.h"
#include "stats.h"
#include "koniec_gry.h"
#include "zmienne.h"
#include "nowy_skladnik.h"
using namespace std; 
using namespace sf;
sklep::sklep(petla& p1, zmienne& z1) :p1(p1), z1(z1), o1(0, 0, "statystyki_tlo.png"), g1(1471, 867, "sklep_play.png", "sklep_play_zaznaczony.png"),
g2(945, 503, "statystyki_next.png", "statystyki_next_zaznaczony.png"), t1(145, 323, "Monety:", Color::White, 60), t2(145, 243, "Dzien: ", Color::White, 60),
t3(145,403, "Inflacja: ", Color::White, 60), t4(145, 483, "Podatek: ", Color::White, 60)
{}

void sklep::wyswietl(RenderWindow& okno)
{
    t1.nap.setString("Coins: " + z1.zaokraglij(z1.monety));
    t2.nap.setString("Day: " + to_string(z1.dzien - 1));
    t3.nap.setString("Inflation: " + z1.zaokraglij(z1.inflacja_wartosc));
    t4.nap.setString("Tax and utility bill: " + z1.zaokraglij(z1.podatek));
    o1.rysuj(okno);
    g1.rysuj(okno);
    if(z1.dzien >1)g2.rysuj(okno);
    okno.draw(t1.nap);
    okno.draw(t2.nap);
    okno.draw(t3.nap);
    okno.draw(t4.nap);
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
            z1.zaplacpodatek();
            zaplacone = true;
        }
        if (g1.p1(pozycjamyszy) && zaplacone && z1.monety>0)
        {
            if (z1.dzien == 2 || z1.dzien == 4 || z1.dzien == 7)
            {
                p1.zmana_stanu(make_unique<nowy_skladnik>(p1, z1));
            }
            else
            {
                p1.zmana_stanu(make_unique<stats>(p1, z1));
            }
            zaplacone = false;
        }
        else if (z1.monety < 0)
        {
            p1.zmana_stanu(make_unique<koniec>(p1, z1));

        }
    }
}
void sklep::logika(float dt, Event& e, RenderWindow& okno)
{
    Vector2i pozycjamyszy = Mouse::getPosition(okno);
    g1.wskaznikGuzik(pozycjamyszy);
}