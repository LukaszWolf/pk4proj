//#ifndef LOGIN_PAGE_H
//#define LOGIN_PAGE_H
//
//#include <SFML/Graphics.hpp>
//#include <cctype>
//#include <fstream>
//#include "Player.h"
//#include"ContentArea.h"
//#include "Button.h"
//#include "Character.h"
//#include "TextBox.h"
//#include"GameState.h"
//#include <regex>
//#include<memory>
//class Game;
//class LoginPage {
//private:
//    ContentArea* content_box;
//    ContentArea* player_select_panel;
//    sf::RectangleShape* login_box;
//    sf::Vector2f login_box_size;
//    Button* login_button;
//    Button* register_button;
//    TextBox* username_text_box;
//    TextBox* password_text_box;
//
//    bool was_account_added;
//    std::vector<Button*> account_btns;
//    std::list<Player*> insertion_order;  // Kolejno�� dodawania
//    std::unordered_map<Player*, std::unique_ptr<Button>> userToButtonMap;
//    //std::shared_ptr<Player> logged_in_user;  // Wsp�dzielony gracz
//    const size_t MAX_PLAYERS = 6;
//    //std::vector<Button*> buttons;  // Kolekcja przycisk�w
//
//    Game& game_ref;
//
//    void initVariables();
//    bool isValidLogin(std::string login);
//    bool isValidPassword(std::string password);
//    bool isPasswordMatched(std::string password, std::string name);
//public:
//    LoginPage(Game& game);
//    ~LoginPage();
//
//    void draw(sf::RenderWindow& window); // Funkcja do rysowania element�w w menu
//    void handleEvents(sf::Event event, sf::RenderWindow& window); // Obs�uguje zdarzenia w menu
//
//    std::string userExistLine(std::string nam, std::string file_name);
//    //   void addNewUser(std::string nam, std::string img_file, CharacterClass ch_class);// chyab nie trzeba tych dwoch bo to ma przekierowac albo do 
//       //menu albo do kreatora wsm, albo wsm tylko to moze robic
//    void addAccountToAvailable(std::string stats);
//    void updateEquipment(std::string filename, Player* player);
//
//    void LogIn(Player* player);
//
//
//    //std::shared_ptr<Player> getLoggedInUserPtr();
//
//};
//#endif 