#include "akcja.h"
#include "Na1.h"
#include "Klient.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
int za, ile;
int numerkota = 0;
int ostatnikot = 0;
bool sprzedane = false;
bool hop = false;
int hopka = 0;
bool losowanie = false;
bool losowanie2 = false;
vector<string> koty = { "cat1.png","cat2.png","cat3.png","cat4.png","cat5.png","cat6.png","cat7.png","cat8.png","cat9.png","cat10.png" };
void akcja::klienci(float& dystans, float dt)
{
	if (!losowanie)
	{
		za = losuj(1, 2);
		ile = losuj(1, 4);
		numerkota = losuj(0, 9);
		while (numerkota == ostatnikot)
		{
			numerkota = losuj(0, 9);
		}
		ostatnikot = numerkota;

		o1.zmienTeksture(koty[numerkota]);
		losowanie = true;
	}
	if (dystans < 200 )
	{
		
		o1.obraz.move(-100 * dt, -50 * dt);

		if (hop && hopka==0)
		{
			o1.obraz.move(0, -10);
			hop = false;
		}else if(!hop && hopka == 0) o1.obraz.move(0, 10) , hop=true;
		dystans = dystans + 100 * dt;
		hopka++;
		if (hopka >= 50)
		{
			hopka = 0;
		}
	}
	if (dystans > 190 && dystans <= 200) t1.nap.setString(zam[0] + to_string(ile) + " " + zam[za]);
	if (za == 1 && z1.chleb >= ile && dystans >= 200 && dystans <= 800 && !sprzedane)
	{
		z1.chleb = z1.chleb - ile;
		z1.monety = z1.monety + 3 * ile;
		sprzedane = true;
	}
	if (za == 2 && z1.kajzerka >= ile && dystans >= 200 && dystans <= 800 && !sprzedane)
	{
		z1.kajzerka = z1.kajzerka - ile;
		z1.monety = z1.monety + 2 * ile;
		sprzedane = true;
	}
	if (dystans >= 200 && dystans <= 750 && sprzedane)
	{
		o1.obraz.move(-100 * dt, 0); //add move func
	

		if (hop && hopka==0)
		{
			o1.obraz.move(0, -10);
			hop = false;
		}
		else if(!hop && hopka==0) o1.obraz.move(0, 35), hop = true;
		dystans = dystans + 100 * dt;
		hopka++;
		if (hopka >= 50)
		{
			hopka = 0;
		}
		t1.nap.setString(" ");
		if (dystans >= 200 && dystans <= 240) t1.nap.setString("dziekuje do widzenia!");

	}
	if (dystans >= 750)
	{
		losowanie = false;
		sprzedane = false;
		losowanie2 = false;
		o1.obraz.setPosition(800, 700); // add set position func
		dystans = 0;
	}
}
