#include "stats.h"
#include "Na1.h"
#include "akcja.h"
#include "sklep.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
stats::stats(petla& p1, zmienne& z1) :p1(p1), z1(z1), t1(145, 323, "monety:", Color::White, 60), o1(0, 0, "shop_tlo.png"),//tnowy(145,643,"nowyskladnik",Color::Black,50),
t4(145, 483, "drozdze:", Color::White, 60), t5(145, 643, "mleko:", Color::White, 60), g3(1405, 503, "guzik_plus_sklep.png", "guzik_plus_sklep.png"), g4(1405, 583, "guzik_plus_sklep.png", "guzik_plus_sklep.png"), g5(1405, 663, "guzik_plus_sklep.png", "guzik_plus_sklep.png"), g6(1405, 743, "guzik_plus_sklep.png", "guzik_plus_sklep.png"), g7(1405, 823, "guzik_plus_sklep.png", "guzik_plus_sklep.png"),
t6(145, 563, "wodda:", Color::White, 60), t7(145, 723, "jajka:", Color::White, 60), t8(145, 803, "maslo:", Color::White, 60),
g1(1405, 423, "guzik_plus_sklep.png", "guzik_plus_sklep.png"), t2(145, 403, "maka:", Color::White, 60), g2(1471, 867, "sklep_play.png", "sklep_play_zaznaczony.png"), t3(145, 243, "dzien:", Color::White, 60) {}
void stats::wyswietl(RenderWindow& okno)
{
    t1.nap.setString("Coins:" + z1.zaokraglij(z1.monety));
    t2.nap.setString("Flour:" + to_string(z1.maka) + ", price: " + z1.zaokraglij(z1.cena_maka));
    t3.nap.setString("Day: " + to_string(z1.dzien));
    t4.nap.setString("Yeast:" + to_string(z1.drozdze) + ", price: " + z1.zaokraglij(z1.cena_drozdze));
    t6.nap.setString("Water:" + to_string(z1.woda) + ", price: " + z1.zaokraglij(z1.cena_woda));
    t5.nap.setString("Milk: " + to_string(z1.mleko) + ", price: " + z1.zaokraglij(z1.cena_mleko));
    t7.nap.setString("Egg: " + to_string(z1.jajka) + ", price: " + z1.zaokraglij(z1.cena_jajko));
    t8.nap.setString("Butter: " + to_string(z1.maslo) + ", price: " + z1.zaokraglij(z1.cena_masla));
    o1.rysuj(okno);
    g2.rysuj(okno);
    g1.rysuj(okno);
    okno.draw(t2.nap);
    g3.rysuj(okno);
    okno.draw(t4.nap);
    g4.rysuj(okno);
    okno.draw(t6.nap);
    if (z1.dzien > 1)
    {
        g5.rysuj(okno);
        okno.draw(t5.nap);
    }
    if (z1.dzien > 3)
    {
        g6.rysuj(okno);
        okno.draw(t7.nap);
    }
    if (z1.dzien > 6)
    {
        g7.rysuj(okno);
        okno.draw(t8.nap);
    }
	okno.draw(t1.nap);
    okno.draw(t3.nap);
}

void stats::obsluga_zdarzen(Event& e,RenderWindow& okno)
{
    if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
    {
        Vector2i pozycjamyszy = Mouse::getPosition(okno);
        if (g1.p1(pozycjamyszy))
        {
            if (z1.monety+niepewnosc >= z1.cena_maka) {
                z1.kupmake();
            }
            
        }
        if (g3.p1(pozycjamyszy))
        {
            if (z1.monety + niepewnosc >= z1.cena_drozdze)
            {
                z1.kupdrozdze();
            }
        }
        if (g4.p1(pozycjamyszy))
        {
            if (z1.monety + niepewnosc >= z1.cena_woda)
            {
                z1.kupwoda();
            }
        }
        if (g5.p1(pozycjamyszy) && z1.dzien>1)
        {
            if (z1.monety + niepewnosc >= z1.cena_mleko)
            {
                z1.kupmleko();
            }
        }
        if (g6.p1(pozycjamyszy) && z1.dzien>3)
        {
            if (z1.monety + niepewnosc >= z1.cena_jajko)
            {
                z1.kupjajka();
            }
        }
        if (g7.p1(pozycjamyszy) && z1.dzien>6)
        {
            if (z1.monety + niepewnosc >= z1.cena_masla)
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