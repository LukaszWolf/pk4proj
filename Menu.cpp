#include "Page.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

Menu::Menu(Game& game) : Page(game) {
    this->navBar = new NavBar(400, 1080, game);
    this->content_box = new ContentArea(1520, 1080, game, sf::Color::Green);
}

Menu::~Menu() {
    delete this->navBar;
    delete this->content_box;
}

void Menu::draw(sf::RenderWindow& window) {
    if (navBar != nullptr) {
        navBar->draw(window);
    }
    if (content_box != nullptr) {
        content_box->draw(window);
    }
}

void Menu::handleEvents(sf::Event event, sf::RenderWindow& window) {
    if (navBar != nullptr) {
        navBar->handleEvents(event, window);
    }
    if (content_box != nullptr) {
        content_box->handleEvents(event, window);
    }
}
