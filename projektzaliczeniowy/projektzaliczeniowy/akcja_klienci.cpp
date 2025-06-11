#include "akcja.h"
#include "Na1.h"
#include "zmienne.h"
using namespace std;
using namespace sf;

vector<string> koty = { "cat1.png","cat2.png","cat3.png","cat4.png","cat5.png","cat6.png","cat7.png","cat8.png","cat9.png","cat10.png" }; //wektor z grafikami klientow
float czashopka = 0.0;
void akcja::klienci(float& dystans, float dt)
{
	if (!losowanie) //losowanie kotka, zamowienia
	{
	
		za = losuj(1, z1.n);
		ile = losuj(1, 3);
		numerkota = losuj(0, 9);
		while (numerkota == ostatnikot)
		{
			numerkota = losuj(0, 9);
		}
		ostatnikot = numerkota;

		o1.zmienTeksture(koty[numerkota]);
		losowanie = true;
		meow.play();
	}
	//ruch kotka po ekranie

	if (dystans < 210 )
	{
		z1.wydajzamowienie = false;
		o1.obraz.move(-100 * dt, -50 * dt);

		dystans = dystans + 100 * dt;
		//if (hop && hopka==0)
		//{
		//	o1.obraz.move(0, -10);
		//	hop = false;
		//}else if(!hop && hopka == 0) o1.obraz.move(0, 10) , hop=true;
		//hopka++;
		//czashopka += dt;
		//if (hopka >= 50*czashopka)
		//{
		//	hopka = 0;
		//}
	}
	if (dystans > 190 && dystans <= 230) //kotek w najzwyzszym polozeniu
	{
		kotek_najwyzej = true;
		zamowienie.zmienTeksture(zam[za]);
		t1.nap.setString(to_string(ile));
	}
	if (za == 1 && z1.chleb >= ile && dystans >= 200 && dystans <= 500 && !sprzedane && z1.wydajzamowienie)//wydaj chleb
	{
		z1.wydajzamowienie = false;
		z1.chleb = z1.chleb - ile;
		z1.monety = z1.monety + z1.cena_chlebek * ile;
		sprzedane = true;
	}
	if (za == 2 && z1.kajzerka >= ile && dystans >= 200 && dystans <= 500 && !sprzedane && z1.wydajzamowienie)//wydaj kajzerke
	{
		z1.wydajzamowienie = false;
		z1.kajzerka = z1.kajzerka - ile;
		z1.monety = z1.monety + z1.cena_kajzerka * ile;
		sprzedane = true;
	}
	if (za == 3 && z1.precel >= ile && dystans >= 200 && dystans <= 500 && !sprzedane && z1.wydajzamowienie)//wydaj precel
	{
		z1.wydajzamowienie = false;
		z1.precel = z1.precel - ile;
		z1.monety = z1.monety + z1.cena_precel * ile;
		sprzedane = true;
	}
	if (za == 4 && z1.rogalik >= ile && dystans >= 200 && dystans <= 500 && !sprzedane && z1.wydajzamowienie)//wydaj rogalik
	{
		z1.wydajzamowienie = false;
		z1.rogalik = z1.rogalik - ile;
		z1.monety = z1.monety + z1.cena_rogalik * ile;
		sprzedane = true;
	}
	if (za == 5 && z1.chalka >= ile && dystans >= 200 && dystans <= 500&& !sprzedane && z1.wydajzamowienie) //wydaj chalke
	{
		z1.wydajzamowienie = false;
		z1.chalka = z1.chalka - ile;
		z1.monety = z1.monety + z1.cena_chalka * ile;
		sprzedane = true;
	}
	//powrot kotka
	if (dystans >= 200 && dystans <= 500 && sprzedane || odmowa)
	{
		kotek_najwyzej = false;
		z1.wydajzamowienie = false;

		o1.obraz.move(-100 * dt, 0); 
	

		dystans = dystans + 100 * dt;
		/*if (hop && hopka==0)
		{
			o1.obraz.move(0, -10);
			hop = false;
		}
		else if(!hop && hopka==0) o1.obraz.move(0, 35), hop = true;
		hopka++;
		if (hopka >= 50)
		{
			hopka = 0;
		}*/
		t1.nap.setString(" ");
		if (dystans >= 200 && dystans <= 240) t1.nap.setString("dziekuje do widzenia!");
		
	}
	if (dystans >= 500 && !z1.wszyscy)
	{
		losowanie = false;
		sprzedane = false;
		losowanie2 = false;
		z1.ilu++;
		odmowa = false;
		o1.obraz.setPosition(800, 700);
		dystans = 0;
	}
		if (z1.ilu == z1.k)
		{
			z1.wszyscy = true;

		}
}

