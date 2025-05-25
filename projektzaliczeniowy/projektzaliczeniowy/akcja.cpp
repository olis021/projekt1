#include "akcja.h"
#include "zmienne.h"
#include "nakladka.h"
#include "stats.h"
#include "Klient.h"
#include "Animacja.h"
using namespace std;
using namespace sf;
int x;
akcja::akcja(petla& p1, zmienne& z1) :p1(p1), z1(z1), g1(100, 100, "tg1.png", "tg1.png"), o1(800, 700, "cat1.png"), o2(0, 0, "bakery_background.png"), o3(0,0, "nakladka_przepis.png"),
t1(700, 600, " ", Color::White, 30), t2(200, 200, " ", Color::White,30), dystans(0), t3(200, 250, "", Color::White, 30), t4(200, 300, "", Color::White, 30), 
g2(800, 150, "tg1.png", "tg1.png"), g3(100, 10, "tg1.png","tg1.png"), g4(30,13,"akcja_przepisy_guzik.png", "akcja_przepisy_guzik_zaznaczony.png"),
g5(780,0, "guzik_przepisy.png", "guzik_przepisy.png"), g6(780,137,"guzik_skladniki.png","guzik_skladniki_zaznaczony.png"),
g7(780,274, "guzik_ekwipunek.png", "guzik_ekwipunek_zaznaczony.png"), g8(780,411, "guzik_wyjdz.png", "guzik_wyjdz_zaznaczony.png"),
t5(200, 350, "kajzerka", Color::White, 30), n1(0,0,"nakladka_przepis.png"), kajzerka(20,16,340,160, 589,160,511,186,2,"kajzerka.png","guzik_plus.png", "guzik_plus.png", "guzik_minus.png", "guzik_minus.png")
{}

void akcja::logika(float dt,Event& e,RenderWindow& okno)
{
	Vector2i pozycjamyszy = Mouse::getPosition(okno);
	g4.wskaznikGuzik(pozycjamyszy);
	g5.wskaznikGuzik(pozycjamyszy);
	g6.wskaznikGuzik(pozycjamyszy);
	g7.wskaznikGuzik(pozycjamyszy);
	g8.wskaznikGuzik(pozycjamyszy);
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
		if (g4.p1(pozycjamyszy))
		{
			n1.nakladkaAktywna = true;
		}

		if (n1.nakladkaAktywna && g8.p1(pozycjamyszy))
		{
			n1.nakladkaAktywna = false;
		}
		if (kajzerka.g1.p1(pozycjamyszy))
		{
			kajzerka.liczba_do_wypieczenia++;
		}
		if (kajzerka.g2.p1(pozycjamyszy))
		{
			if(kajzerka.liczba_do_wypieczenia >= 1)
			kajzerka.liczba_do_wypieczenia--;
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
	if (!n1.nakladkaAktywna)
	{
		g4.rysuj(okno);
	}
	else
	{
		n1.rysuj(okno);
		g5.rysuj(okno);
		g6.rysuj(okno);
		g7.rysuj(okno);
		g8.rysuj(okno);
		kajzerka.rysujprzepis(okno);
	}
	okno.draw(t5.nap);
	okno.draw(t4.nap);
	okno.draw(t3.nap);
	okno.draw(t2.nap);
	okno.draw(t1.nap);
}

