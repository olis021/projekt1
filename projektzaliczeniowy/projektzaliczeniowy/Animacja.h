#pragma once
#include "SFML/Graphics.hpp"
#include "akcja.h"
#include "petla.h"
#include "Na1.h"

class Animacja
{
protected:
	const vector<string> klatki;
	const vector<float> czasKlatek;
	size_t aktualna = 0;
	float timer = 0.f;
public:
	grafika klatka;
	Animacja(const vector<string>& sciezki, const vector<float>& czasy, float x, float y);
	void update(float dt);
	virtual ~Animacja() {};
};

extern std::vector<std::string> softPawSciezki;
extern std::vector<float> softPawCzasy;
extern Animacja MrPaw;