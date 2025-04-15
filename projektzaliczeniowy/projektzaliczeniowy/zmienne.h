#include "petla.h"
using namespace std;
using namespace sf;
#pragma once
class zmienne
{

public:
	int monety = 10;
	int maka = 0;
	void dodajm(int x) { monety = monety + x; }
	void kupmake(int x) { monety = monety - x, maka = maka + 1; }
	zmienne() { monety = 10, maka = 0; }
};
