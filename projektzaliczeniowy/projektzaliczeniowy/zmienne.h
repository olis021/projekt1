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
	int monety ;
	int maka ;
	int mleko = 0;
	int drozdze = 0;
	int jajka = 0;
	int woda = 0;
	int maslo = 0;
	int chleb;
	int dzien;
	int kajzerka;
	bool wydajzamowienie = false;
	void dodajm(int x) { monety = monety + x; }
	void kupmake(int x) { monety = monety - x, maka = maka + 1; }
	void kupdrozdze(int x) { monety = monety - x, drozdze = drozdze + 3; }
	void kupmleko(int x) { monety = monety - x, mleko = mleko + 1; }
	void kupmaslo(int x) { monety = monety - x, maslo = maslo + 1; }
	void kupjajka(int x) { monety = monety - x, jajka = jajka + 4; }
	void kupwoda(int x) { monety = monety - x, woda = woda + 5; }
	void zrobchleb(int x) { maka = maka - x*2,drozdze=drozdze-2*x,mleko=mleko-x, chleb = chleb + x; }
	void zrobkajzerke(int x) { maka = maka - x,drozdze=drozdze-x,mleko=mleko-x, kajzerka = kajzerka + x; }
	void zaplacpodatek(int x) {
		int podatek = 5 + x * 2;
		monety = monety - podatek;  }
	zmienne() { monety = 35, maka = 0, chleb = 0, dzien = 1,kajzerka=0; }
};
inline int losuj(int min, int max) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
extern vector<string> zam;
