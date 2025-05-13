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

    //itemy

    sf::Image* player_image = nullptr;
    ItemSlot* helmet_slot;
    ItemSlot* armor_slot;
    ItemSlot* gloves_slot;
    ItemSlot* shoes_slot;
    ItemSlot* weapon_slot;
    ItemSlot* necklace_slot;
    ItemSlot* belt_slot;
    ItemSlot* ring_slot;
    ItemSlot* lucky_item_slot;
    ItemSlot* bag_slot1;
    ItemSlot* bag_slot2;
    ItemSlot* bag_slot3;
    ItemSlot* bag_slot4;
    ItemSlot* bag_slot5;
    ItemSlot* bag_slot6;
    ItemSlot* bag_slot7;
    ItemSlot* bag_slot8;
   
    std::vector<ItemSlot*> allSlots;
    ItemSlot* dragSource = nullptr;
    bool itemSwapped;

//statystyki
    Button* upgrade_strenght_btn;
    Button* upgrade_dexterity_btn;
    Button* upgrade_intelligence_btn;
    Button* upgrade_constitution_btn;
    Button* upgrade_luck_btn;
public:
    PlayerMenu(Game& game);
    ~PlayerMenu();

    void draw(sf::RenderWindow& window) override;
    void handleEvents(sf::Event event, sf::RenderWindow& window) override;
    void setLoggedInUser(Player* player);
};

#endif
