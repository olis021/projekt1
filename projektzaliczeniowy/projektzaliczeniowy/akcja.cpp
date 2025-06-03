#include "akcja.h"
#include "zmienne.h"
#include "nakladka.h"
#include "sklep.h"
#include "Animacja.h"
using namespace std;
using namespace sf;
int x;

//PRZEPISY
//Kajzerka
//3x maka
//1x jajko
//1x drozdze
//
//Chleb
//4x maka
//1x drozdze
//1x woda
//
//Rogal
//4x maka
//1x mleko
//1x maslo
//
//Cha³ka
//2x maka
//1x mleko
//1x drozdze
//
//Precel
//1x maka
//1x woda
//1x jajko



akcja::akcja(petla& p1, zmienne& z1) :p1(p1), z1(z1), g1(200, 200, "tg1.png", "tg1.png"), o1(800, 700, "cat1.png"), o2(0, 0, "bakery_background.png"), o3(0,0, "nakladka_przepis.png"),
t1(700, 600, " ", Color::White, 30), t2(100, 200, "maka", Color::White,30), dystans(0), t3(400, 30, "", Color::White, 30), t4(200, 300, "", Color::White, 30),
g2(900, 150, "tg1.png", "tg1.png"), g3(100, 10, "tg1.png","tg1.png"), g4(30,13,"akcja_przepisy_guzik.png", "akcja_przepisy_guzik_zaznaczony.png"),
g5(780,0, "guzik_przepisy.png", "guzik_przepisy.png"), g6(780,137,"guzik_skladniki.png","guzik_skladniki_zaznaczony.png"),
g7(780,274, "guzik_ekwipunek.png", "guzik_ekwipunek_zaznaczony.png"), g8(780,411, "guzik_wyjdz.png", "guzik_wyjdz_zaznaczony.png"),
g9(780,600,"tg1.png","tg1.png"),
t5(200, 350, "kajzerka", Color::White, 30), n1(0,0,"nakladka_przepis.png"), kajzerka(20,16,1,1,1,2,"kajzerka.png","guzik_plus.png", "guzik_minus.png"),
t6(100, 430, "mleko", Color::White, 30) , t7(100, 650, "drozdze", Color::White, 30), t8(100, 950, "woda", Color::White, 30), t9(100, 200, "jajka", Color::White, 30),
t10(100,440,"maslo",Color::White,30)
, maka(20, 16, "flour.png", "guzik_plus.png", "guzik_minus.png"), chlebek(20, 276, 4,1,1,2, "chleb.png", "guzik_plus.png", "guzik_minus.png"),
mleko(20, 276, "milk.png", "guzik_plus.png", "guzik_minus.png"), drozdze(20, 536, "drozdzebabuni.png", "guzik_plus.png", "guzik_minus.png"),
chalka(20,16,2,1,1,3,"chalka.png", "guzik_plus.png", "guzik_minus.png"),
precel(20,536,1,1,1,3,"precel.png", "guzik_plus.png", "guzik_minus.png"), rogalik(20,796,4,1,1, 5, "rogal.png", "guzik_plus.png", "guzik_minus.png"),
woda(20,796, "woda.png", "guzik_plus.png", "guzik_minus.png"),jajka(20,16,"egg.png", "guzik_plus.png", "guzik_minus.png"),maslo(20,276,"maslo.png", "guzik_plus.png", "guzik_minus.png")
{}

void akcja::logika(float dt,Event& e,RenderWindow& okno)
{
	Vector2i pozycjamyszy = Mouse::getPosition(okno);
	guzikiZaznaczenie(pozycjamyszy);
	MrPaw.update(dt);
	klienci(dystans, dt);
}

void akcja::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
	Vector2i pozycjamyszy = Mouse::getPosition(okno);
	if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
	{
		if (g1.p1(pozycjamyszy) && n1.nakladkaekwipunek)
		{
			z1.wydajzamowienie = true;
		}
		if (g2.p1(pozycjamyszy) && !n1.nakladkaAktywna)
		{
			z1.dzien++;
			p1.zmana_stanu(make_unique<sklep>(p1, z1));
		}
		if (g6.p1(pozycjamyszy))
		{
			n1.ustawbool(false, true, false, false, z1);
		}
		if (g5.p1(pozycjamyszy))
		{
			n1.ustawbool(true, false, false, false, z1);
		}
		if (g7.p1(pozycjamyszy))
		{
			if (kajzerka.moznaUpiec(maka,drozdze, mleko, z1) && z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.mleko >= mleko.liczba_do_wypieczenia)
			{
				z1.zrobkajzerke(kajzerka.liczba_do_wypieczenia);
			}
			if (chlebek.moznaUpiec(maka,mleko,drozdze, z1)&& z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.mleko >= mleko.liczba_do_wypieczenia)
			{
				z1.zrobchleb(chlebek.liczba_do_wypieczenia);
			}
			n1.ustawbool(false, false, true, z1.wydajzamowienie, z1);
		}
		if (g4.p1(pozycjamyszy) && !n1.nakladkaAktywna)
		{
			n1.nakladkaAktywna = true;
		}

		if (n1.nakladkaAktywna && g8.p1(pozycjamyszy))
		{
			n1.nakladkaAktywna = false;
		}
		if (n1.nakladkaAktywna && g9.p1(pozycjamyszy) && !n1.zmienstrone)
		{
			n1.zmienstrone = true;
		}
		else if (n1.nakladkaAktywna && g9.p1(pozycjamyszy) && n1.zmienstrone)
		{
			n1.zmienstrone = false;
		}
		if (n1.nakladkaAktywna && n1.nakladkaprzepisy && !n1.zmienstrone)
		{
			kajzerka.przyciskNacisniety(pozycjamyszy);
			chlebek.przyciskNacisniety(pozycjamyszy);
			precel.przyciskNacisniety(pozycjamyszy);
			rogalik.przyciskNacisniety(pozycjamyszy);
		}
		if (n1.nakladkaskladniki && n1.nakladkaAktywna && !n1.zmienstrone)
		{
			if(z1.maka> maka.liczba_do_wypieczenia)
			maka.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (z1.mleko > maka.liczba_do_wypieczenia)
			mleko.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (z1.drozdze > maka.liczba_do_wypieczenia)
			drozdze.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (z1.woda > woda.liczba_do_wypieczenia)
			woda.przyciskNacisnietySkladnik(z1, pozycjamyszy);
		}
		if (n1.nakladkaskladniki && n1.nakladkaAktywna && n1.zmienstrone)
		{
			if(z1.jajka>jajka.liczba_do_wypieczenia)
			jajka.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if(z1.maslo>maslo.liczba_do_wypieczenia)
			maslo.przyciskNacisnietySkladnik(z1, pozycjamyszy);
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
	t8.nap.setString("woda: " + to_string(z1.woda));
	t9.nap.setString("jajka: " + to_string(z1.jajka));
	t10.nap.setString("maslo: " + to_string(z1.maslo));
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
		n1.s1.rysuj(okno);
		g5.rysuj(okno);
		g6.rysuj(okno);
		g7.rysuj(okno);
		g8.rysuj(okno);
		g9.rysuj(okno);
		if (n1.nakladkaprzepisy && !n1.zmienstrone)
		{
			kajzerka.rysujprzepis(okno);
			chlebek.rysujprzepis(okno);
			precel.rysujprzepis(okno);
			rogalik.rysujprzepis(okno);
		}
		if (n1.nakladkaprzepisy && n1.zmienstrone)
		{
			chalka.rysujprzepis(okno);
		}

		if (n1.nakladkaskladniki && !n1.zmienstrone)
		{
			maka.rysujskladnik(okno);
			mleko.rysujskladnik(okno);
			drozdze.rysujskladnik(okno);
			woda.rysujskladnik(okno);
			okno.draw(t3.nap);
			okno.draw(t2.nap);
			okno.draw(t6.nap);
			okno.draw(t7.nap);
			okno.draw(t8.nap);
		}
		if (n1.nakladkaskladniki && n1.zmienstrone)
		{
			jajka.rysujskladnik(okno);
			maslo.rysujskladnik(okno);
			okno.draw(t3.nap);
			okno.draw(t9.nap);
			okno.draw(t10.nap);
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

