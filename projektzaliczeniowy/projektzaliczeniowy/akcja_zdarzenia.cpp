#include "akcja.h"
#include "zmienne.h"
#include "nakladka.h"
#include "stats.h"
#include "Animacja.h"
using namespace std;
using namespace sf;
void akcja::akcja_zdarzenia(Vector2i pozycjamyszy)
{

}
void akcja::zmianastrony(Vector2i pozycjamyszy)
{
	
}

void akcja::przewinPrzepisy(int przesuniecie) {
    deque<przepis*> tymczasowe_widoczne;
    deque<przepis*> tymczasowe_niewidoczne;
    //przesuwamy przepisy widoczne i niewidoczne
    for (przepis* i : przepisy_widoczne)
        i->przeniesPrzepis(przesuniecie);
    for (przepis* i : przepisy_niewidoczne)
        i->przeniesPrzepis(przesuniecie);

    //te, ktore mieszcza sie w przedziale [69,743] sa widoczne, inne sa niewidoczne
    for (przepis* i : przepisy_widoczne)
    {
        if (!i) continue;
        i->widoczny = false;
        if (i->zwrocPolozenie().y >= 69 && i->zwrocPolozenie().y <= 743) {
            i->widoczny = true;
            tymczasowe_widoczne.push_back(i);
        }
        else {
            tymczasowe_niewidoczne.push_back(i);
        }
    }

    for (przepis* i : przepisy_niewidoczne)
    {
        if (!i) continue;
        i->widoczny = false;
        if (i->zwrocPolozenie().y >= 69 && i->zwrocPolozenie().y <= 743) {
            i->widoczny = true;
            tymczasowe_widoczne.push_back(i);
        }
        else {
            tymczasowe_niewidoczne.push_back(i);
        }
    }
    // upewniamy sie, ze elementy widoczne sa w dobrej kolejnosci (od najmniejszego y do najwiekszego)
    sort(tymczasowe_widoczne.begin(), tymczasowe_widoczne.end(), [](przepis* a, przepis* b) {
        return a->zwrocPolozenie().y < b->zwrocPolozenie().y;
        });

    // ustawiamy pozycje przepisów widocznych
    vector<float> pozycje_widoczne = { 69.f, 406.f, 743.f };
    for (int i = 0; i < tymczasowe_widoczne.size() && i < 3; ++i)
    {
        przepis* p = tymczasowe_widoczne[i];
        float x = p->zwrocPolozenie().x;
        float y = pozycje_widoczne[i];

        p->zmienPolozenie(x, y);
        p->t1.zmienPolozenie(x + 495, y + 168);
        p->t2.zmienPolozenie(x + 412, y + 9);
        p->t3.zmienPolozenie(x + 532, y + 9);
        p->t4.zmienPolozenie(x + 651, y + 9);
        p->g1.zmienPolozenie(x + 340, y + 160);
        p->g2.zmienPolozenie(x + 589, y + 160);
    }

    // Zapisujemy nowy stan
    przepisy_widoczne = std::move(tymczasowe_widoczne);
    przepisy_niewidoczne = std::move(tymczasowe_niewidoczne);
}