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
	//dane dnia
	float monety ;
	int dzien;
	float inflacja_wartosc;
	float podatek;
	//liczba skladnikow
	int maka ;
	int mleko;
	int jajko;
	int woda;
	int maslo;
	int drozdze;
	//liczba wypiekow
	int chleb;
	int kajzerka;
	int rogal;
	int chalka;
	int precel;
	//cena biezaca skladnikow
	float cena_maki;
	float cena_jajka;
	float cena_mleka;
	float cena_wody;
	float cena_masla;
	float cena_drozdze;
	//cena biezaca wypiekow
	float cena_rogal;
	float cena_kajzerka;
	float cena_chalka;
	float cena_chleb;
	float cena_precel;

	bool wydajzamowienie = false;

	void dodajm(int x);
	void kupmake();
	void kupmleko();
	void kupdrozdze();
	void kupjajko();
	void kupwode();
	void zrobchleb(int x);
	void zrobkajzerke(int x);
	void zrobrogal(int x);
	void zrobprecel(int x);
	void zrobchalke(int x);
	void zaplacpodatek();
	void inflacja();
	zmienne() 
	{monety = 40; dzien = 1; maka = 0; mleko = 0; jajko = 0; maslo = 0; woda = 0; drozdze = 0; chleb = 0; precel = 0;
	rogal = 0; kajzerka = 0; chalka = 0; kajzerka = 0; cena_maki = 1, 6; cena_mleka = 2; cena_jajka = 0, 8; cena_wody = 0, 5; cena_masla = 4, 1; cena_drozdze = 1, 2;
	cena_rogal = 3, 4; cena_chleb = 6; cena_kajzerka = 1, 2; cena_chalka = 8; cena_precel = 2, 8; inflacja_wartosc = 1; podatek = 5;
	}
};
inline int losuj(int min, int max) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
extern vector<string> zam;
