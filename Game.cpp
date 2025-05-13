
#include "Game.h"
#include <iostream>
//TODO
// 
// 
//w setItem w playermenu trzeba setowac item do ekwipunku gracza rowniez, wgl spoko by bylo to zsynchronizowac z playermenu
// Czyli zmieniac item w ekwipunku ustawiajac flage ze zmiana ekwipunku i jesli zmiana ekwipunku to w handle events wczytywac 
// ten ekwipunek 
// 
// 
// 
// 
// 
//
//
//
// Ogarnac wycieki player przy tworzeniu kafelkow i przy usuwaniu player a tak na prawde wylogowywaniu (trzeba usunac itemy i ustawic w mapie equipment nullptr )
// 
// handleevents przyciskow jest troche upo nawet bardzo bo dziala bez przerwy praktycznie ale dziala XD
// 
// itemy w sklepach mozna tworzyc randomowo np obrazek to nazwa randomowe img broni , w jego nazwie jest nazwaa broni i id zapisane a w id sa np informacje o 
// typie broni i np statystyki tez sa wyliczane randomowo biarac pod uwage co to za typ itemu level itp 
// 
// itemy zapisywane w pliku txt danego konta
// stworzenie postaci tworzy nowe konto i plik txt do niego
// 
// zapisac dane postaci przy wylogowywaniu
// 
// weapon w items musi miec dodatkowa statystyke damage (mozna klase pochodna zrobic) i nawet attack() o broni przypisac
// gloves dodac w itemach XD
// 
//private
void Game::initVariables() { // to chyba bez sensu jesli i tak wszystkie obiekty stron sa tworzone w konstruktorze ,trzeba bedzie potem 
    //wszystko przeniesc do game chyba i dynamicznie tworzyc strony wtedy
    //mozna zrobic wskaznik na page np w Game i go przelaczac i usuwac stare page i podpinac pod ten wskaznik nowe page
    //chyba ze wsm draw dziala tak ze inne sie nie rusyja i handle events tez jest nieaktywne to wsm to wgl nie obciaza
    //awanturniczosc i rzeczy z time musza byc w game
    this->window = nullptr;
    this->menu_Screen = nullptr;  // Inicjalizujemy wskaŸnik na nullptr
    this->arena_screen = nullptr;
    this->player_menu_screen = nullptr;
    this->changePage(GameState::LOGIN_PAGE);
}

void Game::initWindow() {
    this->video_mode = sf::VideoMode::getDesktopMode();
    this->window = new sf::RenderWindow(this->video_mode, "Shakes&Fidget 2.0", sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

//public
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->menu_Screen = new Menu(*this);  // Inicjalizujemy menu
    this->tavern_screen = new Tavern(*this);
    this->arena_screen = new Arena(*this);
    this->login_Screen = new LoginPage(*this);
    this->player_menu_screen = new PlayerMenu(*this);
    was_account_added = false;
    item_changed_flag = false;
}

Game::~Game() {
    // Zwalniamy pamiêæ dla obiektu Menu
    if (menu_Screen != nullptr) {
        delete menu_Screen;
    }
    if (tavern_screen != nullptr) {
        delete tavern_screen;
    }
    if (login_Screen != nullptr) {
        delete login_Screen;
    }
    if (player_menu_screen != nullptr) {
        delete player_menu_screen;
    }
    delete this->window;  // Zwalniamy pamiêæ dla okna
}
const sf::Vector2u Game::getWindowSize() {
    return this->window->getSize();
}

const bool Game::running() {
    return this->window->isOpen();
}

void Game::changePage(GameState new_page) {
    this->page = new_page;
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Escape) {
                // Akcja po naciœniêciu klawisza Escape
                this->window->close();  // Na przyk³ad zamkniêcie gry
            }
        }

        switch (this->page) { // to cbyba bez sensu
        case GameState::LOGIN_PAGE:
            this->login_Screen->handleEvents(this->event, *this->window);
            break;
        case GameState::MENU:
            this->menu_Screen->handleEvents(this->event, *this->window);
            break;
        case GameState::PLAYER_MENU:

            //this->tavern_screen->handleEvents(this->event, *this->window);
            this->player_menu_screen->handleEvents(this->event, *this->window); ///to do przeniesienia w inne miejsce potem
            break;
        case GameState::ARENA:
            this->arena_screen->handleEvents(this->event, *this->window);
            break;
        case GameState::BARN:
            // handleTavernEvents();  // Obs³uga zdarzeñ dla karczmy
            break;
        case GameState::SHOP_WEAPONS:
            // handleTavernEvents();  // Obs³uga zdarzeñ dla karczmy
            break;
        case GameState::SHOP_MAGIC:
            // handleTavernEvents();  // Obs³uga zdarzeñ dla karczmy
            break;
        case GameState::DUNGEONS:
            // handleTavernEvents();  // Obs³uga zdarzeñ dla karczmy
            break;
        case GameState::TAVERN:
            //this->player_menu_screen->handleEvents(this->event, *this->window);
        default:
            break;
        }
    }
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    this->window->clear(sf::Color(25, 162, 210, 255));
    switch (this->page) {
    case GameState::LOGIN_PAGE:
        this->login_Screen->draw(*this->window);
        break;
    case GameState::MENU:
        this->menu_Screen->draw(*this->window);
        break;
    case GameState::TAVERN:
        this->tavern_screen->draw(*this->window);
        break;
    case GameState::ARENA:
        this->arena_screen->draw(*this->window);
        break;
    case GameState::PLAYER_MENU:
        this->player_menu_screen->draw(*this->window);
    default:
        break;
    }

    this->window->display();
}

std::vector<Player*>& Game::getAvailableAccounts()
{
    return available_accounts;
}
Player* Game::get_last_available_account() {
    return available_accounts[4];
}

void Game::LogOut()
{

    //zapisac dane postaci
    // Przechodzimy przez ca³¹ mapê ekwipunku i usuwamy przedmioty


    if (loggedInPlayer == nullptr) {
        std::cout << "Nie ma zalogowanego gracza!" << std::endl;

    }
    else {
        // Lista slotów ekwipunku
        std::vector<std::string> equipmentSlots = {
            "helmet", "shield", "trousers", "shoes", "weapon", "necklace", "belt", "ring", "luckyitem",
            "1", "2", "3", "4", "5", "6", "7", "8"
        };

        // Iteracja po nazwach slotów ekwipunku
        for (const std::string& slot : equipmentSlots) {
            // Sprawdzenie, czy w danym slocie jest przedmiot
            Item* item = loggedInPlayer->getItem(slot); // Zak³adaj¹c, ¿e masz gettera getItem()
            if (item != nullptr) {
                // Jeœli przedmiot istnieje, usuwamy go
                delete item;
                std::cout << "Usuniêto przedmiot z slotu: " << slot << std::endl;
            }

            // Ustawienie slotu na nullptr
            loggedInPlayer->setItem(slot, nullptr);
        }
    }
    //loggedInPlayer->printEquipment(); //crash xDD
    setLoggedInPlayer(nullptr);
    changePage(GameState::LOGIN_PAGE);
}

void Game::setLoggedInPlayer(Player* player)
{
    this->loggedInPlayer = player;
    player_menu_screen->setLoggedInUser(player);
}

Player* Game::getLoggedInPlayer()
{
    return loggedInPlayer;
}

bool Game::getItemChangedFlag()
{
    return item_changed_flag;
}
void Game::setItemChangedFlag(bool changed) {
    item_changed_flag = changed;
}
