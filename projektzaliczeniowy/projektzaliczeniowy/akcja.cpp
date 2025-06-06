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
//2x maka
//1x woda
//1x drozdze
//
//Chleb
//4x maka
//1x drozdze
//2x woda
//
//Precel
//3x maka
//1x drozdze
//2x mleko
//
//Rogal
//3x maka
//1x mleko
//2 jajko
//
//Cha³ka
//2x maka
//3x jajka
//2x maslo



akcja::akcja(petla& p1, zmienne& z1) :p1(p1), z1(z1), g1(200, 200, "tg1.png", "tg1.png"), o1(800, 700, "cat1.png"), o2(0, 0, "bakery_background.png"), o3(0,0, "nakladka_przepis.png"),
t1(700, 600, " ", Color::White, 30), t2(100, 200, "maka", Color::White,30), dystans(0), t3(400, 30, "", Color::White, 30), t4(200, 300, "", Color::White, 30),
g2(900, 150, "tg1.png", "tg1.png"), g3(100, 10, "tg1.png","tg1.png"), g4(30,13,"akcja_przepisy_guzik.png", "akcja_przepisy_guzik_zaznaczony.png"),
g5(780,0, "guzik_przepisy.png", "guzik_przepisy.png"), g6(780,137,"guzik_skladniki.png","guzik_skladniki_zaznaczony.png"),
g7(780,274, "guzik_ekwipunek.png", "piecyk.png"), g8(780,411, "guzik_wyjdz.png", "guzik_wyjdz_zaznaczony.png"),
g9(780,600,"olis_strzalka.png","olis_strzalka03.png"), t11(200, 380, "precle:", Color::White, 30), t12(200, 420, "rogaliki", Color::White, 30), t13(480, 300, "chalki", Color::White, 30),
t5(200, 340, "kajzerka", Color::White, 30), n1(0,0,"nakladka_przepis.png"), kajzerka(20,16,2,1,1,2,"kajzerka.png","guzik_plus.png", "guzik_minus.png"),
t6(100, 950, "mleko", Color::White, 30) , t7(100, 650, "drozdze", Color::White, 30), t8(100, 430, "woda", Color::White, 30), t9(100, 200, "jajka", Color::White, 30),
t10(100,440,"maslo",Color::White,30)
, maka(20, 16, "flour.png", "guzik_plus.png", "guzik_minus.png"), chlebek(20, 276, 4,1,2,2, "chleb.png", "guzik_plus.png", "guzik_minus.png"),
mleko(20, 796, "milk.png", "guzik_plus.png", "guzik_minus.png"), drozdze(20, 536, "drozdzebabuni.png", "guzik_plus.png", "guzik_minus.png"),
chalka(20,16,2,2,3,3,"chalka.png", "guzik_plus.png", "guzik_minus.png"),
precel(20,536,3,1,2,3,"precel.png", "guzik_plus.png", "guzik_minus.png"), rogalik(20,796,3,1,2, 5, "rogal.png", "guzik_plus.png", "guzik_minus.png"),
woda(20, 276, "woda.png", "guzik_plus.png", "guzik_minus.png"),jajka(20,16,"egg.png", "guzik_plus.png", "guzik_minus.png"),maslo(20,276,"maslo.png", "guzik_plus.png", "guzik_minus.png")
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
			if (kajzerka.moznaUpiec(maka,drozdze, woda, z1) && z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.woda >= woda.liczba_do_wypieczenia)
			{
				z1.zrobkajzerke(kajzerka.liczba_do_wypieczenia);
			}
			if (chlebek.moznaUpiec(maka,drozdze,woda, z1)&& z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.woda >= woda.liczba_do_wypieczenia)
			{
				z1.zrobchleb(chlebek.liczba_do_wypieczenia);
			}
			if (precel.moznaUpiec(maka, drozdze, mleko, z1) && z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.mleko >= mleko.liczba_do_wypieczenia)
			{
				z1.zrobprecla(precel.liczba_do_wypieczenia);
			}
			if (rogalik.moznaUpiec(maka, mleko, jajka, z1) && z1.maka >= maka.liczba_do_wypieczenia && z1.jajka >= jajka.liczba_do_wypieczenia && z1.mleko >= mleko.liczba_do_wypieczenia)
			{
				z1.zrobrogala(rogalik.liczba_do_wypieczenia);
			}
			if (chalka.moznaUpiec(maka, maslo, jajka, z1) && z1.maka >= maka.liczba_do_wypieczenia && z1.jajka >= jajka.liczba_do_wypieczenia && z1.maslo >= maslo.liczba_do_wypieczenia)
			{
				z1.zrobchalke(chalka.liczba_do_wypieczenia);
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
			if(z1.dzien>1)
			precel.przyciskNacisniety(pozycjamyszy);
			if(z1.dzien>3)rogalik.przyciskNacisniety(pozycjamyszy);
		}
		else if (n1.nakladkaAktywna && n1.nakladkaprzepisy && n1.zmienstrone && z1.dzien>6) chalka.przyciskNacisniety(pozycjamyszy);
		if (n1.nakladkaskladniki && n1.nakladkaAktywna && !n1.zmienstrone)
		{
			if(z1.maka> maka.liczba_do_wypieczenia)
			maka.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (maka.g2.p1(pozycjamyszy))maka.zmniejsz();
			if (z1.mleko > mleko.liczba_do_wypieczenia && z1.dzien>1)
			mleko.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (mleko.g2.p1(pozycjamyszy))mleko.zmniejsz();
			if (z1.drozdze > drozdze.liczba_do_wypieczenia)
			drozdze.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (drozdze.g2.p1(pozycjamyszy))drozdze.zmniejsz();
			if (z1.woda > woda.liczba_do_wypieczenia)
			woda.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (woda.g2.p1(pozycjamyszy))woda.zmniejsz();
		}
		if (n1.nakladkaskladniki && n1.nakladkaAktywna && n1.zmienstrone)
		{
			if(z1.jajka>jajka.liczba_do_wypieczenia && z1.dzien>3)
			jajka.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (jajka.g2.p1(pozycjamyszy))jajka.zmniejsz();
			if(z1.maslo>maslo.liczba_do_wypieczenia && z1.dzien>6)
			maslo.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (maslo.g2.p1(pozycjamyszy))maslo.zmniejsz();
		}
		if (g2.p1(pozycjamyszy) && !n1.nakladkaAktywna)
		{
			z1.dzien++;
			p1.zmana_stanu(make_unique<sklep>(p1, z1));
		}
	}
}

void akcja::wyswietl(RenderWindow& okno)
{
	t2.nap.setString("maka: " + to_string(z1.maka));
	t3.nap.setString("monety: " + to_string(z1.monety));
	t4.nap.setString("chleby: " + to_string(z1.chleb));
	t5.nap.setString("kajzerki: " + to_string(z1.kajzerka));
	t6.nap.setString("mleko: " + to_string(z1.mleko));
	t7.nap.setString("drozdze: " + to_string(z1.drozdze));
	t8.nap.setString("woda: " + to_string(z1.woda));
	t9.nap.setString("jajka: " + to_string(z1.jajka));
	t10.nap.setString("maslo: " + to_string(z1.maslo));
	t11.nap.setString("precle: " + to_string(z1.precle));
	t12.nap.setString("rogale: " + to_string(z1.rogale));
	t13.nap.setString("chalki: " + to_string(z1.chalki));
	o2.rysuj(okno);
	MrPaw.klatka.rysuj(okno);
	//g3.rysuj(okno);
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
			if(z1.dzien>1)precel.rysujprzepis(okno);
			if(z1.dzien>3)rogalik.rysujprzepis(okno);
		}
		if (n1.nakladkaprzepisy && n1.zmienstrone)
		{
			if(z1.dzien>6)chalka.rysujprzepis(okno);
		}

		if (n1.nakladkaskladniki && !n1.zmienstrone)
		{
			maka.rysujskladnik(okno);
			drozdze.rysujskladnik(okno);
			woda.rysujskladnik(okno);
			if (z1.dzien > 1)mleko.rysujskladnik(okno);
			okno.draw(t3.nap);
			okno.draw(t2.nap);
			if (z1.dzien > 1)okno.draw(t6.nap);
			okno.draw(t7.nap);
			okno.draw(t8.nap);
		}
		if (n1.nakladkaskladniki && n1.zmienstrone)
		{
			if (z1.dzien > 3)jajka.rysujskladnik(okno);
			if (z1.dzien > 6)maslo.rysujskladnik(okno);
			okno.draw(t3.nap);
			if (z1.dzien > 3)okno.draw(t9.nap);
			if (z1.dzien > 6)okno.draw(t10.nap);
		}
		if (n1.nakladkaekwipunek)
		{
			okno.draw(t5.nap);
			okno.draw(t4.nap);
			if (z1.dzien > 1)okno.draw(t11.nap);
			if (z1.dzien > 3)okno.draw(t12.nap);
			if (z1.dzien > 6)okno.draw(t13.nap);

	g1.rysuj(okno);
		}
	}
		okno.draw(t1.nap);
}

