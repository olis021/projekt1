#include "akcja.h"
#include "zmienne.h"
using namespace std;
using namespace sf;

	bool sprzedane = false;
akcja::akcja(petla& p1,zmienne& z1) :p1(p1),z1(z1), g1(100, 100, "tg1.png"), o1(800, 700, "klient.png"), t1(600, 650, " "),t2(200,200," "),dystans(0),t3(200,250,""),t4(200,300,"")
{

}
void akcja::logika(float dt,Event& e)
{
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

	}

}
void akcja::wyswietl(RenderWindow& okno)
{
	t2.nap.setString("maka: " + to_string(z1.maka));
	t3.nap.setString("monety: " + to_string(z1.monety));
	t4.nap.setString("chleb: " + to_string(z1.chleb));
	okno.draw(t4.nap);
	okno.draw(t3.nap);
	okno.draw(t2.nap);
	okno.draw(t1.nap);
	okno.draw(g1.guzikson);
	okno.draw(o1.guzikson);
}
void akcja::klienci(float& dystans,float dt)
{
	if (dystans < 200)
	{
		o1.guzikson.move(-100 * dt, -50 * dt);
		dystans = dystans + 100 * dt;
	}
	if (dystans > 190 && dystans <= 200) t1.nap.setString("siema moge chlebek bratku?");
	if (z1.chleb >= 1 && dystans >= 200 && dystans <= 800 && !sprzedane)
	{
		z1.chleb = z1.chleb - 1;
		z1.monety = z1.monety + 3;
		sprzedane = true;
	}
	if (dystans >= 200 && dystans <= 750 && sprzedane)
	{
		o1.guzikson.move(-100 * dt, 0);
		dystans = dystans + 100 * dt;
		t1.nap.setString(" ");
		if (dystans >= 200 && dystans <= 240) t1.nap.setString("dzieki bracie!");

	}
	if (dystans >= 750)
	{
		sprzedane = false;
		o1.guzikson.setPosition(800, 700);
		dystans = 0;
	}

}