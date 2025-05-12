#include "Arena.h"
#include <SFML/Graphics.hpp>

Arena::Arena(Game& game) {
    // Za³aduj czcionkê i ustaw tytu³
    //if (!font.loadFromFile("Arial.ttf")) {
        // Obs³uguje b³¹d za³adowania czcionki
    //}

    this->title.setString("Arena");
    this->title.setCharacterSize(50);
    //this->title.setPosition(300, 150);  // Pozycja tytu³u na ekranie
    this->title.setFillColor(sf::Color::White);

    // Dynamicznie tworzymy pasek nawigacji
    this->navBar = new NavBar(400, 1080, game);  // Mo¿esz ustawiæ odpowiednie wymiary
    this->content_box = new ContentArea(1520, 1080, game, "arena_all.png");
}

Arena::~Arena() {
    // Zwolnienie pamiêci dla NavBar
    delete this->navBar;
    delete this->content_box;
}

void Arena::draw(sf::RenderWindow& window) {
    // Rysujemy pasek nawigacji
    if (navBar != nullptr) {
        navBar->draw(window); // Przekazujemy referencjê do okna
    }
    if (content_box != nullptr) {
        content_box->draw(window); // Przekazujemy referencjê do okna
    }

    // Rysujemy tytu³
    window.draw(this->title);
}

void Arena::handleEvents(sf::Event event, sf::RenderWindow& window) {
    // Obs³ugujemy zdarzenia paska nawigacji
    if (navBar != nullptr) {
        navBar->handleEvents(event, window);  // Przekazujemy referencjê do okna
    }
    if (content_box != nullptr) {
        content_box->handleEvents(event, window);  // Przekazujemy referencjê do okna
    }
    // Dodaj inne zdarzenia specyficzne dla Menu
}
