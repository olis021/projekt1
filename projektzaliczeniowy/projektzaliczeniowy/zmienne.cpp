#include "zmienne.h"

void zmienne::dodajm(int x) { monety = monety + static_cast<float>(x); }

void zmienne::kupmake() { monety = monety - cena_maki; maka++; }
void zmienne::kupdrozdze() { monety = monety - cena_drozdze; drozdze++; }
void zmienne::kupmleko() { monety = monety - cena_mleka;mleko = mleko++; }
void zmienne::kupjajko() { monety = monety - cena_jajka;jajka = jajka++; }
void zmienne::kupwode() { monety = monety - cena_wody, woda++; }
void zmienne::kupmaslo() { monety = monety - cena_masla, maslo++; }

void zmienne::zrobchleb(int x) { maka = maka - x * 4, drozdze = drozdze - x, woda = woda - x, chleb = chleb + x; }
void zmienne::zrobkajzerke(int x) { maka = maka - 3 * x, drozdze = drozdze - x, jajka = jajka - x, kajzerka = kajzerka + x; }
void zmienne::zrobchalke(int x) { maka = maka - 2 * x, mleko = mleko - x, drozdze = drozdze - x, chalka = chalka + x; }
void zmienne::zrobrogal(int x) { maka = maka - 4 * x, maslo = maslo - x, mleko = mleko - x, rogal = rogal + x; }
void zmienne::zrobprecel(int x) { maka = maka - x, woda = woda - x, jajka = jajka - x, precel = precel + x; }

void zmienne::zaplacpodatek() {
	monety = monety - podatek;
}
void zmienne::inflacja()
{
	cena_maki *= inflacja_wartosc;
	cena_jajka *= inflacja_wartosc;
	cena_maki *= inflacja_wartosc;
	cena_jajka *= inflacja_wartosc;
	cena_mleka *= inflacja_wartosc;
	cena_wody *= inflacja_wartosc;
	cena_masla *= inflacja_wartosc;
	cena_drozdze *= inflacja_wartosc;
	cena_rogal *= inflacja_wartosc;
	cena_kajzerka *= inflacja_wartosc;
	cena_chalka *= inflacja_wartosc;
	cena_chleb *= inflacja_wartosc;
	cena_precel *= inflacja_wartosc;
	inflacja_wartosc += 0, 2;
	podatek *= inflacja_wartosc;
}