#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <random>
using namespace std;
using namespace sf;
#pragma once
class zmienne
{
public:
	int monety ;
	int maka ;
	int chleb;
	int dzien;
	int kajzerka;
	void dodajm(int x) { monety = monety + x; }
	void kupmake(int x) { monety = monety - x, maka = maka + 1; }
	void zrobchleb(int x) { maka = maka - x, chleb = chleb + 1; }
	void zrobkajzerke(int x) { maka = maka - x, kajzerka = kajzerka + 2; }
	zmienne() { monety = 10, maka = 0, chleb = 0, dzien = 1,kajzerka=0; }
};
inline int losuj(int min, int max) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
extern vector<string> zam;
