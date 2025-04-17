#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
using namespace std;
using namespace sf;
#pragma once
class zmienne
{

public:
	int monety ;
	int maka ;
	int chleb;
	void dodajm(int x) { monety = monety + x; }
	void kupmake(int x) { monety = monety - x, maka = maka + 1; }
	void zrobchleb(int x) { maka = maka - x, chleb = chleb + 1; }
	zmienne() { monety = 10, maka = 0,chleb=0; }
};
