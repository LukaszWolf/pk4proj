#ifndef PAGE_H
#define PAGE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>
#include "Button.h"
#include "TextBox.h"
#include "ContentArea.h"
#include "Player.h"
#include "GameState.h"
#include "Character.h"
#include "NavBar.h"
class Game;

// === Bazowa klasa Page ===
class Page {
protected:
    Game& game_ref;

public:
    Page(Game& game) : game_ref(game) {}
    virtual ~Page() = default;

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void handleEvents(sf::Event event, sf::RenderWindow& window) = 0;
};



// === LoginPage ===
class LoginPage : public Page {
private:
    ContentArea* content_box;
    ContentArea* player_select_panel = nullptr;
    Button* login_button;
    Button* register_button;
    TextBox* username_text_box;
    TextBox* password_text_box;
    

    std::vector<Button*> account_btns;
    std::list<Player*> insertion_order;
    std::unordered_map<Player*, std::unique_ptr<Button>> userToButtonMap;
    const size_t MAX_PLAYERS = 6;

    void initVariables();
    bool isValidLogin(std::string login);
    bool isValidPassword(std::string password);
    bool isPasswordMatched(std::string password, std::string line);

public:
    LoginPage(Game& game);
    ~LoginPage();

    void draw(sf::RenderWindow& window) override;
    void handleEvents(sf::Event event, sf::RenderWindow& window) override;

    std::string userExistLine(std::string name, std::string file_name);
    void addAccountToAvailable(std::string stats);
    void updateEquipment(std::string filename, Player* player);
    void LogIn(Player* player);
};



// === Menu ===
class Menu : public Page {
private:
    NavBar* navBar;
    ContentArea* content_box;

public:
    Menu(Game& game);
    ~Menu();

    void draw(sf::RenderWindow& window) override;
    void handleEvents(sf::Event event, sf::RenderWindow& window) override;
};



// === PlayerMenu ===
class PlayerMenu : public Page {
private:
    Player* loggedInUser;
    int test_counter;
    NavBar* navBar;
    ContentArea* player_managment_area;

    sf::Image* player_image = nullptr;
    ItemSlot* helmet_area;
    ItemSlot* armor_area;
    ItemSlot* gloves_area;
    ItemSlot* shoes_area;
    ItemSlot* weapon_area;
    ItemSlot* weapon_effect_area;
    ItemSlot* necklace_area;
    ItemSlot* belt_area;
    ItemSlot* ring_area;
    ItemSlot* lucky_item_area;

   
    std::vector<ItemSlot*> allSlots;
    ItemSlot* dragSource = nullptr;

   // void tryStartDrag(const sf::Vector2i& mousePos, const sf::Event& event);
    //void tryEndDrag(const sf::Vector2i& mousePos, const sf::Event& event);
   // bool item_changed_flag;

public:
    PlayerMenu(Game& game);
    ~PlayerMenu();

    void draw(sf::RenderWindow& window) override;
    void handleEvents(sf::Event event, sf::RenderWindow& window) override;
    void setLoggedInUser(Player* player);
};

#endif
