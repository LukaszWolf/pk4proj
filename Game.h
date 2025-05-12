
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Page.h"
#include "Tavern.h"
#include"Arena.h"
#include "LoginPage.h"
#include "Player.h"
#include "PlayerMenu.h"

class Game {
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode video_mode;
    sf::Vector2u windowSize;
    GameState page;
    Menu* menu_Screen;
    Tavern* tavern_screen;
    Arena* arena_screen;
    LoginPage* login_Screen;
    PlayerMenu* player_menu_screen;
    std::vector<Player*> available_accounts; // Tablica wskaŸników do dostepnych kont do szybkiego zalogowania
    void initVariables();
    void initWindow();


    Player* loggedInPlayer;
    ///loginpage
    bool was_account_added;
    bool item_changed_flag;

    //playermenu

    std::vector<std::pair<ItemSlot*, Item*>> bagpack_slots;
    std::map<int, ItemSlot*> equipment_item_areas;
public:
    Game();
    virtual ~Game();
    //gettery
    const sf::Vector2u getWindowSize();// u to unsigned int

    //metody
    const bool running();
    void changePage(GameState new_page);
    void pollEvents();
    void update();
    void render();

    void LogOut();

    std::vector<Player*>& getAvailableAccounts();
    Player* get_last_available_account();
    void setLoggedInPlayer(Player* player);
    Player* getLoggedInPlayer();
    bool getItemChangedFlag();
    void setItemChangedFlag(bool changed);
};

#endif // GAME_H
