#include "akcja.h"
#include "zmienne.h"
#include "stats.h"
#include "Klient.h"
#include "Animacja.h"
using namespace std;
using namespace sf;


int x;
akcja::akcja(petla& p1, zmienne& z1) :p1(p1), z1(z1), g1(100, 100, "tg1.png", "tg1.png"), o1(800, 700, "cat1.png"), o2(0, 0, "bakery_background.png"),
t1(700, 600, " ", Color::White, 30), t2(200, 200, " ", Color::White,30), dystans(0), t3(200, 250, "", Color::White, 30), t4(200, 300, "", Color::White, 30), 
g2(800, 150, "tg1.png", "tg1.png"), g3(100, 10, "tg1.png","tg1.png"), t5(200, 350, "kajzerka", Color::White, 30){}
void akcja::logika(float dt,Event& e,RenderWindow& okno)
{
	MrPaw.update(dt);
klienci(dystans, dt);
}
void akcja::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
	if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
	{
		Vector2i pozycjamyszy = Mouse::getPosition(okno);
		if (g1.p1(pozycjamyszy))
		{
			if (z1.maka >= 1)
			{
				z1.zrobchleb(1);
			}
		}
		if (g3.p1(pozycjamyszy))
		{
			if (z1.maka >= 1)
			{
				z1.zrobkajzerke(1);
			}
		}
		if (g2.p1(pozycjamyszy))
		{
			z1.dzien++;
			p1.zmana_stanu(make_unique<stats>(p1, z1));
		}
	}

}
void akcja::wyswietl(RenderWindow& okno)
{
	t2.nap.setString("maka: " + to_string(z1.maka));
	t3.nap.setString("monety: " + to_string(z1.monety));
	t4.nap.setString("chleb: " + to_string(z1.chleb));
	t5.nap.setString("kajzerki: " + to_string(z1.kajzerka));
	g1.rysuj(okno);
	o2.rysuj(okno);
	MrPaw.klatka.rysuj(okno);
	g2.rysuj(okno);
	g3.rysuj(okno);
	o1.rysuj(okno);
	okno.draw(t5.nap);
	okno.draw(t4.nap);
	okno.draw(t3.nap);
	okno.draw(t2.nap);
	okno.draw(t1.nap);
}

