#include "Animacja.h"
#include <vector>
using namespace std;
using namespace sf;

Animacja::Animacja(const vector<string>& sciezki, const vector<float>& czasy, float x, float y): klatki(sciezki), czasKlatek(czasy), klatka(x, y, sciezki[0]) {}
void Animacja::update(float dt) {
    timer += dt;
    if (timer >= czasKlatek[aktualna]) {
        timer = 0.f;
        aktualna = (aktualna + 1) % klatki.size(); //na poczatku klatka 0 sprawdzamy jaka reszta przez liczbe klatek, jezeli nie 0 to przechodzimy do nastepnje klatki
        klatka.zmienTeksture(klatki[aktualna]);
    }
}


vector<string> softPawSciezki = { "SofrPaw1.png","SofrPaw2.png","SofrPaw3.png", "SofrPaw4.png" };
vector<float> softPawCzasy = { 0.5f,0.3f,0.5f,0.3f };

Animacja MrPaw(softPawSciezki, softPawCzasy, 1269, 167);