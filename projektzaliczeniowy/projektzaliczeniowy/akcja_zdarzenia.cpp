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
    //przesuwamy przepisy widoczne i niewidoczne
    for (przepis* i : przepisy_zbior)
        i->przeniesPrzepis(przesuniecie);
   
    //te, ktore mieszcza sie w przedziale [69,743] sa widoczne, inne sa niewidoczne
    for (przepis* i : przepisy_zbior)
    {
        if (!i) continue;
        i->widoczny = false;
        if (i->zwrocPolozenie().y >= 69 && i->zwrocPolozenie().y <= 743) {
            i->widoczny = true;
        }
    }

    // ustawiamy pozycje przepisów widocznych
    vector<float> pozycje_widoczne = { 69.f, 406.f, 743.f };
    vector<float> pozycje_niewidoczne = { -268.f, 1080.f, 1417.f };
    int licznikw = 0;
    for (przepis* i : przepisy_zbior)
    {
        if (i->widoczny)
        {
            if (licznikw < 3)
            {
                float x = i->zwrocPolozenie().x;
                float y = pozycje_widoczne[licznikw];

                i->zmienPolozenie(x, y);
                i->t1.zmienPolozenie(x + 495, y + 168);
                i->t2.zmienPolozenie(x + 412, y + 9);
                i->t3.zmienPolozenie(x + 532, y + 9);
                i->t4.zmienPolozenie(x + 651, y + 9);
                i->g1.zmienPolozenie(x + 340, y + 160);
                i->g2.zmienPolozenie(x + 589, y + 160);
                licznikw++;
            }
        }
    }
}