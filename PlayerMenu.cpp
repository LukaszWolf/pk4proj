#include "Page.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

PlayerMenu::PlayerMenu(Game& game) : Page(game) {
    //item_changed_flag = false;
    this->loggedInUser = game_ref.getLoggedInPlayer();
    test_counter = 0;
    this->navBar = new NavBar(400, 1080, game);
    this->player_managment_area = new ContentArea(1520, 1080, game, "player_managment_area.png", 400, 0);

    this->helmet_area = new ItemSlot({ 444,34 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->armor_area = new ItemSlot({ 444,184 }, { 126,126 }, ItemType::ARMOR, "test.png", []() {}, nullptr);
    this->gloves_area = new ItemSlot({ 444,334 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->shoes_area = new ItemSlot({ 444,484 }, { 126,126 }, ItemType::BOOTS, "test.png", []() {}, nullptr);
    this->weapon_area = new ItemSlot({ 650,484 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->weapon_effect_area = new ItemSlot({ 802,484 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->necklace_area = new ItemSlot({ 1008,34 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->belt_area = new ItemSlot({ 1008,184 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->ring_area = new ItemSlot({ 1008,334 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->lucky_item_area = new ItemSlot({ 1008,484 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    std::cout << test_counter << std::endl << std::endl;
    allSlots = {
    helmet_area,
    armor_area,
    gloves_area,
    shoes_area,
    weapon_area,
    weapon_effect_area,
    necklace_area,
    belt_area,
    ring_area,
    lucky_item_area
    };
}

PlayerMenu::~PlayerMenu() {
    delete this->navBar;
    delete this->player_managment_area;
    delete this->player_image;

    delete this->helmet_area;
    delete this->armor_area;
    delete this->gloves_area;
    delete this->shoes_area;
    delete this->weapon_area;
    delete this->weapon_effect_area;
    delete this->necklace_area;
    delete this->belt_area;
    delete this->ring_area;
    delete this->lucky_item_area;
}

void PlayerMenu::draw(sf::RenderWindow& window) {
    if (navBar != nullptr) {
        navBar->draw(window);
    }

    if (player_managment_area != nullptr) {
        player_managment_area->draw(window);
    }
    if(shoes_area!=nullptr){
    shoes_area->draw(window);
    }

}













void PlayerMenu::handleEvents(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
    sf::Vector2f mouseWorld = window.mapPixelToCoords(mousePixel);

    // 1) Forward event to NavBar
    if (navBar) {
        navBar->handleEvents(event, window);
    }

    // 2) Try to start dragging on mouse press
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        for (auto slot : allSlots) {
            slot->tryStartDrag(mousePixel, event);
            if (slot->getIsItemDragged()) {
                dragSource = slot;
                break;
            }
        }
    }

    // 3) Try to end drag on mouse release
    if (event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Left &&
        dragSource)
        //std::cout << "wykonal sie if";
    {
        for (auto target : allSlots) {
            target->endDrag(mousePixel, event, dragSource);

        }
        dragSource = nullptr;
    }

    // 4) Always call each slot's handleEvents (hover or move)
    for (auto slot : allSlots) {
        slot->handleEvents(mousePixel, event);
    }

    // 5) Sync with player data if needed
    if (loggedInUser && game_ref.getItemChangedFlag()) {
        if (auto it = loggedInUser->getItem("shoes")) {
            shoes_area->setItem(it);
        }
        game_ref.setItemChangedFlag(false);
    }

}

void PlayerMenu::setLoggedInUser(Player* player) {
    this->loggedInUser = player;
}
