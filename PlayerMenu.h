//#ifndef PLAYER_MENU_H
//#define PLAYER_MENU_H
//
//#include <SFML/Graphics.hpp>
//#include "NavBar.h"  // Nag��wek dla klasy NavBar
//#include "ContentArea.h"
//#include "Button.h"
//#include "Player.h"z
//#include "memory"
//
//// trzeba zrobic mape item_img to slot, mozna klase zrobic chyba slotBox, jesli najedziemy n aprzycisk co sie kryje pod slotem to sie pojawia opis itemu,
////jak klikniemy na slot to item przesuwa sie w miejsce slotu(lewy gorny rog zeby na pewno go trzymac albo nawet troche dalej)
////poki ni epuscimy przycisku pyszy to item renderuje sie tam gdzie jest myszka ewentualnie troche przesuniety i jesli najedziemy na itemslot inny
//// to tam sie pojawia ten item
////i item slot musi umiec zmieniac statystyki playera
////to tak  na prawde klasa pochodna Button z dodana mapa i image;
////ten image to wsm klasa item// 
////kazdy slot musi miec swoj enum typ przedmiotu
////lepiej zrobic klase enums do tych wszystkich enumow
////zamiast image klasa item
////itemy musza miec swoje id i byc przechowywane w pliku razem z linkami do tekstur czy tam img
//class Game;
//class LoginPage;
//class PlayerMenu {
//private:
//    Game& game_ref;
//    Player* loggedInUser;
//    //std::shared_ptr<Player> loggedInPlayer();
//
//    NavBar* navBar;
//    ContentArea* player_managment_area;
//    ContentArea* equipment_area;
//    //postac i jej zalozone itemy
//    sf::Image* player_image;
//    ItemSlot* helmet_area;
//    ItemSlot* armor_area;
//    ItemSlot* gloves_area;
//    ItemSlot* shoes_area;
//
//    ItemSlot* weapon_area;
//    ItemSlot* weapon_effect_area;
//
//    ItemSlot* necklace_area;
//    ItemSlot* belt_area;
//    ItemSlot* ring_area;
//    ItemSlot* lucky_item_area;
//
//    std::vector < std::pair<ItemSlot*, Item*> > bagpack_slots;
//
//    ///custom ksztalt klasa postaci
//    sf::Text* name;
//    sf::RectangleShape* level_bar;
//    sf::Text* level_text;
//
//
//    //statystyki
//    sf::Text* strenght_value;
//    sf::Text* strenght_correlated_value;
//    Button* strenght_upgrade_button;
//
//    sf::Text* dexterity_value;
//    sf::Text* correlated_value;
//    Button* dexterity_upgrade_button;
//
//    sf::Text* intelligence_value;
//    sf::Text* intelligence_correlated_value;
//    Button* intelligence_upgrade_button;
//
//    sf::Text* constitution_value;
//    sf::Text* constitution_correlated_value;
//    Button* constitution_upgrade_button;
//
//    sf::Text* luck_value;
//    sf::Text* luck_correlated_value;
//    Button* luck_upgrade_button;
//
//    sf::Text* armor_value;
//    sf::Text* armor_correlated_value;
//    Button* armor_upgrade_button;
//    // mozna je do mapy dac z kluczem string np
//    //custom ksztalty mikstura i wierzchowiec
//
//    // ekwipunekz
//    std::map<int, ItemSlot*> equipment_item_areas; // id,itemslot
//
//
//    //
//    bool item_changed_flag;
//public:
//    PlayerMenu(Game& game);
//    ~PlayerMenu();
//    void draw(sf::RenderWindow& window); // Funkcja do rysowania element�w w menu
//    void handleEvents(sf::Event event, sf::RenderWindow& window); // Obs�uguje zdarzenia w menu
//    void setLoggedInUser(Player* player);
//};
//
//#endif // MENU_H