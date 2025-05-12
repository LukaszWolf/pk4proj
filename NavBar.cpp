#include "Game.h"
#include "NavBar.h"

#include <SFML/Graphics.hpp>
#include <iostream>




NavBar::NavBar(float width, float height, Game&game): game_ref(game) {
    this->tavern_button = new Button({ 20, 200 }, { 360, 57 }, "karczma_button_clear.png", [&game]() {game.changePage(GameState::PLAYER_MENU); });
    //this->tavern_button = new Button("TAVERN", { 20, 200 }, { 360, 57 },"karczma_button_clear.png");
    this->arena_button = new Button({ 20, 316 }, { 360, 57 }, "arena_button.png", [&game]() {game.changePage(GameState::ARENA); });
    this->barn_button = new Button({ 20, 432 }, { 360, 57 }, "zbrojownia_button.png",[&game]() {game.changePage(GameState::BARN); });
    this->shop_weapons_button = new Button({ 20, 548 }, { 360, 57 }, "Gabinet_magii_button.png", [&game]() {game.changePage(GameState::SHOP_WEAPONS); });
    this->shop_magic_button = new Button({ 20, 664 }, { 360, 57 }, "stajnia_button.png", [&game]() {game.changePage(GameState::SHOP_MAGIC); });
    this->dungeons_button = new Button({ 20, 780 }, { 360, 57 }, "lochy_button.png", [&game]() {game.changePage(GameState::DUNGEONS); });
    this->exit_button = new Button({ 20, 896 }, { 360, 57 }, "test.png", [&game]() {game.LogOut();});

    this->bar.setSize(sf::Vector2f(width, height));
    this->tex.loadFromFile("navbar_clear.png");
    this->bar.setTexture(&this->tex);
    this->bar.setPosition(0, 0);

    void initVariables();

    // Za³aduj czcionkê
    //if (!font.loadFromFile("Arial.ttf")) {
      //  std::cerr << "B³¹d ³adowania czcionki!" << std::endl;
    //}

    // Tworzymy przyciski na pasku nawigacji
//    this->button1.setFont(font);

}
NavBar::~NavBar() {

    delete this->tavern_button;
    delete this->arena_button;
    delete this->shop_magic_button;
    delete this->shop_weapons_button;
    delete this->barn_button;
    delete this->dungeons_button;
    delete this->exit_button;
}

void NavBar::initVariables()
{
    this->tavern_button = nullptr;
    this->arena_button = nullptr;
    this->shop_magic_button = nullptr;
    this->shop_weapons_button = nullptr;
    this->barn_button = nullptr;
    this->dungeons_button = nullptr;
    this->exit_button = nullptr;
}

void NavBar::draw(sf::RenderWindow& window) {
    window.draw(this->bar);
    this->tavern_button->draw(window);
    this->arena_button->draw(window);
    this->barn_button->draw(window);
    this->shop_weapons_button->draw(window);
    this->shop_magic_button->draw(window);
    this->dungeons_button->draw(window);
    this->exit_button->draw(window);

}

void NavBar::handleEvents(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    //tu chce uzyc metody klasy game
 ///jesli przycisk byl klikniety to potem sprawdzamy czy na jakims przycisku byl klikniety

    //nie moze sie to w kolko dziac , bez sensu
        tavern_button->handleEvents(mousePos, event);
        arena_button->handleEvents(mousePos, event);
        barn_button->handleEvents(mousePos, event);
        shop_weapons_button->handleEvents(mousePos, event);
        shop_magic_button->handleEvents(mousePos, event);
        dungeons_button->handleEvents(mousePos, event);
        exit_button->handleEvents(mousePos, event);

}