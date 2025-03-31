#include "SFML/Graphics.hpp"
#include <iostream>

int main() {
    sf::RenderWindow okno(sf::VideoMode(800, 600), "SFML Test");

    while (okno.isOpen()) {
        sf::Event zdarzenie;
        while (okno.pollEvent(zdarzenie)) {
            if (zdarzenie.type == sf::Event::Closed)
                okno.close();
        }

        okno.clear(sf::Color::Blue);
        okno.display();
    }

    return 0;
}