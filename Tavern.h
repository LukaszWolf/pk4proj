#ifndef TAVERN_H
#define TAVERN_H

#include <SFML/Graphics.hpp>
#include "NavBar.h"  // Nag��wek dla klasy NavBar
#include"ContentArea.h"
class Game;
class Tavern {
private:
    NavBar* navBar;
    sf::Text title;
    ContentArea* content_box;
public:
    Tavern(Game& game);
    ~Tavern();
    void draw(sf::RenderWindow& window); // Funkcja do rysowania element�w w menu
    void handleEvents(sf::Event event, sf::RenderWindow& window); // Obs�uguje zdarzenia w menu
};

#endif 
