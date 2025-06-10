#include "akcja.h"
#include "zmienne.h"
#include "nakladka.h"
#include "sklep.h"
#include "Animacja.h"
#include "menu.h"
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



akcja::akcja(petla& p1, zmienne& z1) :p1(p1), z1(z1), g1(750, 1000, "sell.png", "sell.png"), o1(800, 700, "cat1.png"), o2(0, 0, "bakery_background.png"), o3(0, 0, "nakladka_przepis.png"),
t1(1233, 390, " ", Color::Black, 60), dystans(0), t3(400, 30, "", Color::White, 30), t4(528,475, "", Color::Black, 30), t5(528, 216, "", Color::Black, 30),
g2(1560, 13, "zakoncz_dzien.png", "zakoncz_dzien_zaznaczony.png"), g3(100, 10, "tg1.png", "tg1.png"), g4(30, 13, "akcja_przepisy_guzik.png", "akcja_przepisy_guzik_zaznaczony.png"),
g5(780, 0, "gzuik_przepisy.png", "gzuik_przepisy.png"), g6(780, 137, "guzik_skladniki.png", "guzik_skladniki_zaznaczony.png"),
g7(780, 274, "piecyk.png", "piecyk.png"), g8(780, 411, "guzik_wyjdz.png", "guzik_wyjdz_zaznaczony.png"), t6(100, 950, "mleko", Color::White, 30), t7(100, 650, "drozdze", Color::White, 30), t8(100, 430, "woda", Color::White, 30), t9(100, 200, "jajka", Color::White, 30),
t10(100, 440, "maslo", Color::White, 30), t2(100, 200, "maka", Color::White, 30),
g9(780, 600, "olis_strzalka.png", "olis_strzalka03.png"), t11(528, 730, "precle:", Color::Black, 30), t12(528, 990, "rogaliki", Color::Black, 30), t13(528, 216, "chalki", Color::Black, 30), n1(0, 0, "nakladka_przepis.png"), kajzerka(20, 16, 2, 1, 1, "kajzerka.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"),
maka(20, 16, "flour.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"), chlebek(20, 276, 4, 1, 2, "chleb.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"),
mleko(20, 796, "milk.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"), drozdze(20, 536, "drozdzebabuni.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"),
chalka(20, 16, 2, 3, 2, "chalka.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"),
precel(20, 536, 3, 1, 2, "precel.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"), rogalik(20, 796, 3, 1, 2, "rogal.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"),
woda(20, 276, "woda.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"), jajka(20, 16, "egg.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"), maslo(20, 276, "maslo.png", "guzik_plus.png", "guzik_plus_zaznaczony.png", "guzik_minus.png", "guzik_minus_zaznaczony.png"),
wyjdz(1745, 13, "guzik__akcja_wyjdz.png", "guzik__akcja_wyjdz_zaznaczony.png"), chleb_e(20, 276, "chleb_ekwipunek.png"), kajzerka_e(20, 16, "kajzerka_ekwipunek.png"),
chalka_e(20, 16, "chalka_ekwipunek.png"), precel_e(20, 536, "precel_ekwipunek.png"), rogal_e(20, 796, "rogal_ekwipunek.png"), odmow(1745, 900, "nie_sprzedaj.png", "nie_sprzedaj_zaznaczony.png"),
t14(950, 20, "monety", Color::White, 60), chmurka(939,236, "chmurka.png"), zamowienie(1078,281, "chleb_klient.png")
{
	if(!mruczenie.openFromFile("purr.ogg")) cerr << "Nie udalo siê zaladowac muzyki!" << endl;;
	mruczenie.setLoop(true);
	mruczenie.setVolume(100);
	mruczenie.play();
	if(!buffer_meow.loadFromFile("meow.ogg")) cerr << "Nie udalo sie zaladowac dzwieku!" << endl;;
	meow.setBuffer(buffer_meow);
	meow.setVolume(50);
}

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
			chlebek.liczba_do_wypieczenia = 0;
			kajzerka.liczba_do_wypieczenia = 0;
			chalka.liczba_do_wypieczenia = 0;
			precel.liczba_do_wypieczenia = 0;
			rogalik.liczba_do_wypieczenia = 0;
			maka.liczba_do_wypieczenia = 0;
			jajka.liczba_do_wypieczenia = 0;
			woda.liczba_do_wypieczenia = 0;
			drozdze.liczba_do_wypieczenia = 0;
			maslo.liczba_do_wypieczenia = 0;
			mleko.liczba_do_wypieczenia = 0;
		}
		if (odmow.p1(pozycjamyszy) && !z1.wydajzamowienie)
		{
			odmowa = true;
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
			if (precel.moznaUpiec(maka, mleko, drozdze, z1) && z1.maka >= maka.liczba_do_wypieczenia && z1.drozdze >= drozdze.liczba_do_wypieczenia && z1.mleko >= mleko.liczba_do_wypieczenia)
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
			meow.play();
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
			if (z1.mleko > mleko.liczba_do_wypieczenia && z1.dzien>1)
			mleko.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (z1.drozdze > drozdze.liczba_do_wypieczenia)
			drozdze.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if (z1.woda > woda.liczba_do_wypieczenia)
			woda.przyciskNacisnietySkladnik(z1, pozycjamyszy);
		}
		if (n1.nakladkaskladniki && n1.nakladkaAktywna && n1.zmienstrone)
		{
			if(z1.jajka>jajka.liczba_do_wypieczenia && z1.dzien>3)
			jajka.przyciskNacisnietySkladnik(z1, pozycjamyszy);
			if(z1.maslo>maslo.liczba_do_wypieczenia && z1.dzien>6)
			maslo.przyciskNacisnietySkladnik(z1, pozycjamyszy);
		}
		if (g2.p1(pozycjamyszy) && !n1.nakladkaAktywna || z1.wszyscy)
		{
			z1.inflacja();
			z1.dzien++;
			z1.ilu = 0;
			z1.wszyscy = false;
			p1.zmana_stanu(make_unique<sklep>(p1, z1));
		}
		if (wyjdz.p1(pozycjamyszy) && !n1.nakladkaAktywna)
		{
			p1.zmana_stanu(make_unique<menu>(p1));
		}
	}
}

void akcja::wyswietl(RenderWindow& okno)
{
	t2.nap.setString(to_string(z1.maka));
	t4.nap.setString(to_string(z1.chleb));
	t5.nap.setString(to_string(z1.kajzerka));
	t6.nap.setString( to_string(z1.mleko));
	t7.nap.setString( to_string(z1.drozdze));
	t8.nap.setString( to_string(z1.woda));
	t9.nap.setString( to_string(z1.jajka));
	t10.nap.setString( to_string(z1.maslo));
	t11.nap.setString(to_string(z1.precel));
	t12.nap.setString(to_string(z1.rogalik));
	t13.nap.setString(to_string(z1.chalka));
	t14.nap.setString("Coins: " + z1.zaokraglij(z1.monety));
	o2.rysuj(okno);
	MrPaw.klatka.rysuj(okno);
	o1.rysuj(okno);
	if (!z1.wydajzamowienie && !n1.nakladkaAktywna)
	{
		odmow.rysuj(okno);
	}
	if (!n1.nakladkaAktywna)
	{
	g2.rysuj(okno);
	g4.rysuj(okno);
	wyjdz.rysuj(okno);
	}
	else
	{
		n1.rysuj(okno);
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
			maka.rysujskladnik(okno), okno.draw(t2.nap);;
			drozdze.rysujskladnik(okno) , okno.draw(t7.nap);;
			woda.rysujskladnik(okno), okno.draw(t8.nap);;
			if (z1.dzien > 1)mleko.rysujskladnik(okno), okno.draw(t6.nap);;
		}
		if (n1.nakladkaskladniki && n1.zmienstrone)
		{
			if (z1.dzien > 3)jajka.rysujskladnik(okno), okno.draw(t9.nap);;
			if (z1.dzien > 6)maslo.rysujskladnik(okno), okno.draw(t10.nap);;
		}
		if (n1.nakladkaekwipunek && !n1.zmienstrone)
		{
			kajzerka_e.rysuj(okno);
			chleb_e.rysuj(okno);
			okno.draw(t5.nap);
			okno.draw(t4.nap);
			if (z1.dzien > 1)
			{
				precel_e.rysuj(okno);
				okno.draw(t11.nap);
			}
			if (z1.dzien > 3)
			{
				rogal_e.rysuj(okno);
				okno.draw(t12.nap);
			}
			g1.rysuj(okno);
		}
		if (n1.nakladkaekwipunek && !n1.zmienstrone && z1.dzien > 6)
		{
			chalka_e.rysuj(okno);
			if (z1.dzien > 6)okno.draw(t13.nap);
			g1.rysuj(okno);
		}
	}
	if (kotek_najwyzej)
	{
		chmurka.rysuj(okno);
		zamowienie.rysuj(okno);
		okno.draw(t1.nap);
	}
		okno.draw(t14.nap);
}

