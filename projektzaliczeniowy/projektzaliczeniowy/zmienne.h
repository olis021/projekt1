#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <random>
using namespace std;
using namespace sf;

class zmienne
{
public:
	float monety;
	int maka ;
	int mleko = 0;
	int drozdze = 0;
	int jajka = 0;
	int woda = 0;
	int maslo = 0;
	int rogal;
	int precel;
	int chalka;
	int chleb;
	int dzien;
	int kajzerka;
	bool wydajzamowienie = false;
	float cena_maki;
	float cena_jajka;
	float cena_mleka;
	float cena_wody;
	float cena_masla;
	float cena_drozdze;
	float cena_rogal;
	float cena_kajzerka;
	float cena_chalka;
	float cena_chleb;
	float cena_precel;
	float inflacja_wartosc;
	float podatek;

	//nakladka przewijanie
	enum coKlikniete { Brak, Gora, Dol };
	coKlikniete ostatniKlik = Brak;
	int licznikGora = 0;
	int licznikDol = 0;
	const int maxKlikniec = 2;

	void kupmake();
	void kupdrozdze();
	void kupmleko();
	void kupjajko();
	void kupwode();
	void zrobchleb(int x);
	void zrobkajzerke(int x);
	void zrobchalke(int x);
	void zrobrogal(int x);
	void zrobprecel(int x);

	void inflacja();
	void dodajm(int x);
	void kupmaslo();
	void zaplacpodatek();
	zmienne() {
		monety = 35.0f, dzien = 1, podatek = 5.0f, inflacja_wartosc = 1.2f, chalka = 0, precel = 0, chleb = 0, kajzerka = 0, rogal = 0,
			jajka = 0, maslo = 0, woda = 0, maka = 0, drozdze = 0, mleko = 0, cena_jajka = 0.8f, cena_masla = 3.8f, cena_mleka = 2.6f, cena_wody = 0.2f, cena_maki = 3.0f, cena_drozdze = 1.0f,
			cena_rogal = 2.0f, cena_precel = 1.8f, cena_kajzerka = 0.5f, cena_chleb = 3.8f, cena_chalka = 4.0f;
	}
};
inline int losuj(int min, int max) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
extern vector<string> zam;
