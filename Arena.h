#ifndef ARENA_H
#define ARENA_H

#include <SFML/Graphics.hpp>
#include "NavBar.h"  // Nag³ówek dla klasy NavBar
#include"ContentArea.h"
class Game;
class Arena {
private:
    NavBar* navBar;
    sf::Text title;
    ContentArea* content_box;
public:
    Arena(Game& game);
    ~Arena();
    void draw(sf::RenderWindow& window); // Funkcja do rysowania elementów w menu
    void handleEvents(sf::Event event, sf::RenderWindow& window); // Obs³uguje zdarzenia w menu
};

#endif 


