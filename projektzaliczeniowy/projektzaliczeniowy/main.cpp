#include "Na1.h"
using namespace std;
using namespace sf;
int main()
{
    RenderWindow okno(VideoMode(1200, 800), "GraKotPiekarz");
    button g1(500,300,"guzik.png");
    while (okno.isOpen()) {
        Event event;
        while (okno.pollEvent(event)) {
            if (event.type == Event::Closed)
                okno.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                Vector2i pozycjamyszy = Mouse::getPosition(okno);
                    g1.p1(pozycjamyszy);
                
            }
            
        }
        okno.clear(tlo);
        okno.draw(g1.guzikson);
        okno.display();
    }

    return 0;
}