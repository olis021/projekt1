#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
using namespace sf;

class zmienne
{
public:
	double monety;
	double inflacja_wartosc;
	double podatek;

	int maka;
	int mleko;
	int drozdze;
	int jajka;
	int woda;
	int maslo;

	int chleb;
	int dzien;
	int kajzerka;
	int precel;
	int chalka;
	int rogalik;

	bool wydajzamowienie = false;
	double cena_kajzerka;
	double cena_chlebek;
	double cena_precel;
	double cena_rogalik;
	double cena_chalka;
	double cena_maka;
	double cena_woda;
	double cena_drozdze;
	double cena_jajko;
	double cena_mleko;
	double cena_masla;
	void kupmake() { monety = monety - cena_maka, maka++; }
	void kupdrozdze() { monety = monety - cena_drozdze, drozdze++; }
	void kupmleko() { monety = monety - cena_mleko, mleko++; }
	void kupmaslo() { monety = monety - cena_masla, maslo++; }
	void kupjajka() { monety = monety - cena_jajko, jajka++; }
	void kupwoda() { monety = monety - cena_woda, woda++; }
	void zrobchleb(int x) { maka = maka - x*4,drozdze=drozdze-x,woda=woda-x*2, chleb = chleb + x; }
	void zrobprecla(int x) { maka = maka - x * 3, drozdze = drozdze - x,  mleko = mleko - x * 2, precel = precel + x; }
	void zrobrogala(int x) { maka = maka - x * 3, jajka = jajka - 2*x, mleko = mleko - x , rogalik = rogalik + x; }
	void zrobchalke(int x) { maka = maka - x * 2, jajka = jajka - x*3, maslo = maslo - x * 2, chalka = chalka + x; }
	void zrobkajzerke(int x) { maka = maka - 2*x,drozdze=drozdze-x,woda=woda-x, kajzerka = kajzerka + x; }
	void zaplacpodatek() {;
		monety = monety - podatek;
	}
	zmienne() {
		monety = 100, dzien = 1, maka = 0, chleb = 0, kajzerka = 0, precel = 0, rogalik = 0, chalka = 0, jajka = 0, drozdze = 0, woda = 0, maka = 0, maslo = 0, mleko = 0, inflacja_wartosc = 1.2, podatek = 15;
			cena_maka = 2, cena_jajko = 0.8, cena_mleko = 2, cena_woda = 0.2, cena_masla = 2.8, cena_drozdze = 1, cena_chlebek = 3, cena_kajzerka = 0.8, cena_precel = 2.8, cena_chalka = 3, cena_rogalik = 1.8;
	}
	void inflacja()
	{
		cena_maka = cena_maka*inflacja_wartosc;
		cena_jajko = cena_jajko*inflacja_wartosc;
		cena_drozdze = cena_drozdze*inflacja_wartosc;
		cena_woda = cena_woda*inflacja_wartosc;
		cena_masla = cena_masla*inflacja_wartosc;
		cena_mleko = cena_mleko*inflacja_wartosc;

		cena_chlebek = cena_chlebek*inflacja_wartosc;
		cena_kajzerka = cena_kajzerka*inflacja_wartosc;
		cena_chalka = cena_chalka*inflacja_wartosc;
		cena_rogalik = cena_rogalik*inflacja_wartosc;
		cena_precel = cena_precel*inflacja_wartosc;

		podatek = podatek * inflacja_wartosc;

		inflacja_wartosc += 0.2;
	}
	string zaokraglij(double x)
	{
		ostringstream bufor_do_string;
		bufor_do_string << fixed << setprecision(2) << x;
		return bufor_do_string.str();
	}

	virtual ~zmienne() {};
};
inline int losuj(int min, int max) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
extern vector<string> zam;
