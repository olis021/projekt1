#include "akcja.h"
#include "zmienne.h"
#include "nakladka.h"
#include "sklep.h"
#include "Klient.h"
#include "Animacja.h"
using namespace std;
using namespace sf;
int x;
akcja::akcja(petla& p1, zmienne& z1) :p1(p1), z1(z1), g1(200, 200, "tg1.png", "tg1.png"), o1(800, 700, "cat1.png"), o2(0, 0, "bakery_background.png"), o3(0,0, "nakladka_przepis.png"),
t1(700, 600, " ", Color::White, 30), t2(100, 200, " ", Color::White,30), dystans(0), t3(400, 30, "", Color::White, 30), t4(200, 300, "", Color::White, 30), tdu(110, 350, "CHLEB", Color::White, 30),
g2(900, 150, "tg1.png", "tg1.png"), g3(100, 10, "tg1.png","tg1.png"), g4(30,13,"akcja_przepisy_guzik.png", "akcja_przepisy_guzik_zaznaczony.png"),
g5(780,0, "guzik_przepisy.png", "guzik_przepisy.png"), g6(780,137,"guzik_skladniki.png","guzik_skladniki_zaznaczony.png"),
g7(780,274, "guzik_ekwipunek.png", "guzik_ekwipunek_zaznaczony.png"), g8(780,411, "guzik_wyjdz.png", "guzik_wyjdz_zaznaczony.png"),
t5(200, 350, "kajzerka", Color::White, 30), n1(0,0,"nakladka_przepis.png"), kajzerka(20,16,340,160, 589,160,511,186,2,"kajzerka.png","guzik_plus.png", "guzik_plus.png", "guzik_minus.png", "guzik_minus.png"),
t6(100, 430, "mleko", Color::White, 30) , t7(100, 650, "drozdze", Color::White, 30)
, maka(20, 16, 340, 160, 589, 160, 511, 186, 2, "makabasia.png", "guzik_plus.png", "guzik_plus.png", "guzik_minus.png", "guzik_minus.png"), chlebek(20, 276, 340, 160, 589, 160, 511, 480, 2, "kajzerka.png", "guzik_plus.png", "guzik_plus.png", "guzik_minus.png", "guzik_minus.png"),
mleko(20, 276, 340, 160, 589, 160, 511, 480, 2, "mleko.png", "guzik_plus.png", "guzik_plus.png", "guzik_minus.png", "guzik_minus.png"), drozdze(20, 550, 340, 160, 589, 160, 511, 750, 2, "drozdzebabuni.png", "guzik_plus.png", "guzik_plus.png", "guzik_minus.png", "guzik_minus.png")
{}
//PRZEPIS NA 1 CHLEB TO : 2 MAKA 2 DROZDZE I 1 MLEKO
// PRZEPIS NA 1 KAJZERKE TO : 1 MAKA 1 MLEKO I 1 DROZDZE
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
		if (g1.p1(pozycjamyszy) && n1.nakladkaekwipunek)
		{
			z1.wydajzamowienie = true;
		}
		//if (g3.p1(pozycjamyszy))
		//{
		//	if (z1.maka >= 1)
		//	{
		//		z1.zrobkajzerke(1);
		//	}
		//}
		if (g2.p1(pozycjamyszy) && !n1.nakladkaAktywna)
		{
			z1.dzien++;
			p1.zmana_stanu(make_unique<sklep>(p1, z1));
		}
		if (g6.p1(pozycjamyszy))
		{
			n1.nakladkaskladniki = true;
			n1.nakladkaprzepisy = false;
			n1.nakladkaekwipunek = false;
			z1.wydajzamowienie = false;
		}
		if (g5.p1(pozycjamyszy))
		{
			n1.nakladkaskladniki = false;
			n1.nakladkaprzepisy = true;
			n1.nakladkaekwipunek = false;
			z1.wydajzamowienie = false;
		}
		if (g7.p1(pozycjamyszy))
		{
			if (kajzerka.liczba_do_wypieczenia == maka.liczba_do_wypieczenia && mleko.liczba_do_wypieczenia == kajzerka.liczba_do_wypieczenia && drozdze.liczba_do_wypieczenia == kajzerka.liczba_do_wypieczenia && z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.mleko >= mleko.liczba_do_wypieczenia)
			{
				z1.zrobkajzerke(kajzerka.liczba_do_wypieczenia);
			}
			if ((2 * chlebek.liczba_do_wypieczenia) == maka.liczba_do_wypieczenia && mleko.liczba_do_wypieczenia == chlebek.liczba_do_wypieczenia && drozdze.liczba_do_wypieczenia == 2 * chlebek.liczba_do_wypieczenia && z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.mleko >= mleko.liczba_do_wypieczenia)
			{
				z1.zrobchleb(chlebek.liczba_do_wypieczenia);
			}
			n1.nakladkaekwipunek = true;
			n1.nakladkaprzepisy = false;
			n1.nakladkaskladniki = false;
		}
		if (g4.p1(pozycjamyszy) && !n1.nakladkaAktywna)
		{
			n1.nakladkaAktywna = true;
		}

		if (n1.nakladkaAktywna && g8.p1(pozycjamyszy))
		{
			n1.nakladkaAktywna = false;
		}
		if (n1.nakladkaAktywna && n1.nakladkaprzepisy)
		{
			if (kajzerka.g1.p1(pozycjamyszy))
			{
				kajzerka.liczba_do_wypieczenia++;
			}
			if (kajzerka.g2.p1(pozycjamyszy))
			{
				if (kajzerka.liczba_do_wypieczenia >= 1)
					kajzerka.liczba_do_wypieczenia--;
			}
			if (chlebek.g1.p1(pozycjamyszy))
			{
				chlebek.liczba_do_wypieczenia++;
			}
			if (chlebek.g2.p1(pozycjamyszy))
			{
				if (chlebek.liczba_do_wypieczenia >= 1)
					chlebek.liczba_do_wypieczenia--;
			}
		}
		if (n1.nakladkaskladniki && n1.nakladkaAktywna)
		{
			if (maka.g1.p1(pozycjamyszy) && z1.maka>maka.liczba_do_wypieczenia)
			{
				maka.liczba_do_wypieczenia++;
			}
			if (maka.g2.p1(pozycjamyszy))
			{
				if (maka.liczba_do_wypieczenia >= 1)
					maka.liczba_do_wypieczenia--;
			}
			if (mleko.g1.p1(pozycjamyszy) && z1.mleko > mleko.liczba_do_wypieczenia)
			{
				mleko.liczba_do_wypieczenia++;
			}
			if (mleko.g2.p1(pozycjamyszy))
			{
				if (mleko.liczba_do_wypieczenia >= 1)
					mleko.liczba_do_wypieczenia--;
			}
			if (drozdze.g1.p1(pozycjamyszy) && z1.drozdze > drozdze.liczba_do_wypieczenia)
			{
				drozdze.liczba_do_wypieczenia++;
			}
			if (drozdze.g2.p1(pozycjamyszy))
			{
				if (drozdze.liczba_do_wypieczenia >= 1)
					drozdze.liczba_do_wypieczenia--;
			}
		}
	}
}

void akcja::wyswietl(RenderWindow& okno)
{
	t2.nap.setString("maka: " + to_string(z1.maka));
	t3.nap.setString("monety: " + to_string(z1.monety));
	t4.nap.setString("chleb: " + to_string(z1.chleb));
	t5.nap.setString("kajzerki: " + to_string(z1.kajzerka));
	t6.nap.setString("mleko: " + to_string(z1.mleko));
	t7.nap.setString("drozdze: " + to_string(z1.drozdze));
	o2.rysuj(okno);
	MrPaw.klatka.rysuj(okno);
	g3.rysuj(okno);
	o1.rysuj(okno);
	if (!n1.nakladkaAktywna)
	{
	g2.rysuj(okno);
		g4.rysuj(okno);
	}
	else
	{
		n1.rysuj(okno);
		g5.rysuj(okno);
		g6.rysuj(okno);
		g7.rysuj(okno);
		g8.rysuj(okno);
		if (n1.nakladkaprzepisy)
		{
			kajzerka.rysujprzepis(okno);
			chlebek.rysujprzepis(okno);
			okno.draw(tdu.nap);
		}

		if (n1.nakladkaskladniki)
		{
			maka.rysujprzepis(okno);
			mleko.rysujprzepis(okno);
			drozdze.rysujprzepis(okno);
			okno.draw(t3.nap);
			okno.draw(t2.nap);
			okno.draw(t6.nap);
			okno.draw(t7.nap);
		}
		if (n1.nakladkaekwipunek)
		{
			okno.draw(t5.nap);
			okno.draw(t4.nap);
	g1.rysuj(okno);
		}
	}
		okno.draw(t1.nap);
}

