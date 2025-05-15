#include "Page.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

PlayerMenu::PlayerMenu(Game& game) : Page(game) {
    //item_changed_flag = false;
    this->loggedInUser = game_ref.getLoggedInPlayer();
    test_counter = 0;
    this->navBar = new NavBar(400, 1080, game);
    this->player_managment_area = new ContentArea(1520, 1080, game, "player_menu_background.png", 400, 0);

    this->helmet_slot = new ItemSlot({ 439,34 }, { 129,129 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->armor_slot = new ItemSlot({ 439,184 }, { 129,129 }, ItemType::ARMOR, "test.png", []() {}, nullptr);
    this->gloves_slot = new ItemSlot({ 439,335 }, { 129,129 }, ItemType::GLOVES, "test.png", []() {}, nullptr);
    this->shoes_slot = new ItemSlot({ 439,486 }, { 129,129 }, ItemType::SHOES, "test.png", []() {}, nullptr);
    this->weapon_slot = new ItemSlot({ 721,487 }, { 129,129 }, ItemType::WEAPON, "test.png", []() {}, nullptr);
  //  this->weapon_effect_area = new ItemSlot({ 802,484 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->necklace_slot = new ItemSlot({ 1004,34 }, { 129,129 }, ItemType::NECKLACE, "test.png", []() {}, nullptr);
    this->belt_slot = new ItemSlot({ 1004,185 }, { 129,129 }, ItemType::BELT, "test.png", []() {}, nullptr);
    this->ring_slot = new ItemSlot({ 1004,336 }, { 129,129 }, ItemType::RING, "test.png", []() {}, nullptr);
    this->lucky_item_slot = new ItemSlot({ 1004,487 }, { 129,129 }, ItemType::LUCKY_ITEM, "test.png", []() {}, nullptr);

    this->bag_slot1 = new ItemSlot({ 1251,34 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot2 = new ItemSlot({ 1400,34 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot3 = new ItemSlot({ 1545,34 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot4 = new ItemSlot({ 1693,34 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot5= new ItemSlot({ 1251,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot6 = new ItemSlot({ 1400,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot7 = new ItemSlot({ 1545,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot8 = new ItemSlot({ 1693,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);

    this->upgrade_strenght_btn = new Button({ 720, 681 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_dexterity_btn = new Button({ 720, 774 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_intelligence_btn = new Button({ 720, 867 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_constitution_btn = new Button({ 1042, 681 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_luck_btn = new Button({ 1042, 774 }, { 0, 0 }, "upgrade_stat_button.png", []() {});


    

    

    ////////dodac sloty z plecaka

    allSlots = {
    helmet_slot,
    armor_slot,
    gloves_slot,
    shoes_slot,
    weapon_slot,
    necklace_slot,
    belt_slot,
    ring_slot,
    lucky_item_slot,
    bag_slot1,
    bag_slot2,
    bag_slot3,
    bag_slot4,
    bag_slot5,
    bag_slot6,
    bag_slot7,
    bag_slot8
    };
    updateSlots();
    itemSwapped = false;
}

PlayerMenu::~PlayerMenu() {
    delete this->navBar;
    delete this->player_managment_area;
    delete this->player_image;

    delete this->helmet_slot;
    delete this->armor_slot;
    delete this->gloves_slot;
    delete this->shoes_slot;
    delete this->weapon_slot;
    delete this->necklace_slot;
    delete this->belt_slot;
    delete this->ring_slot;
    delete this->lucky_item_slot;

    delete this->bag_slot1;
    delete this->bag_slot2;
    delete this->bag_slot3;
    delete this->bag_slot4;
    delete this->bag_slot5;
    delete this->bag_slot6;
    delete this->bag_slot7;
    delete this->bag_slot8;


    delete this->upgrade_strenght_btn;
    delete this->upgrade_dexterity_btn;
    delete this->upgrade_intelligence_btn;
    delete this->upgrade_constitution_btn;
    delete this->upgrade_luck_btn;
}

void PlayerMenu::draw(sf::RenderWindow& window) {
    if (navBar != nullptr) {
        navBar->draw(window);
    }

    if (player_managment_area != nullptr) {
        player_managment_area->draw(window);
    }
    for (auto slot : allSlots) {
        if (slot) {
            slot->draw(window);
        }
    }

    if (upgrade_strenght_btn) {
        upgrade_strenght_btn->draw(window);
    }
    if (upgrade_dexterity_btn) {
        upgrade_dexterity_btn->draw(window);
    }
    if (upgrade_intelligence_btn) {
        upgrade_intelligence_btn->draw(window);
    }
    if (upgrade_constitution_btn) {
        upgrade_constitution_btn->draw(window);
    }
    if (upgrade_luck_btn) {
        upgrade_luck_btn->draw(window);
    }

}




void PlayerMenu::handleEvents(sf::Event event, sf::RenderWindow& window) {

    ///zamiana itemow przez game ref najlepiej chyba albo plik tekstowy



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

        itemSwapped = false;
        for (auto target : allSlots) {
            if(target->isHovered(mousePixel))
            {
                
                itemSwapped = target->endDrag(mousePixel, event, dragSource);
                dragSource->cancelDrag();
                break;
            }
        }
        if (!itemSwapped) {
        
            std::cout << "upuszczono nie na slocie" << std::endl;
            dragSource->getCurrentItem()->setPosition(dragSource->getPosition()); // item wraca na miejsce jesli nie trafil do zadnego sl
            dragSource->getCurrentItem()->setPosition(dragSource->getPosition());
            dragSource->cancelDrag();
            //moze sie pojawic informacja ze upuszczono w nieprawidlowym miejscu
        }
        /*if (dragSource and !itemSwapped) {
            dragSource->getCurrentItem()->setPosition(dragSource->getPosition());
            dragSource = nullptr;
            dragSource->setIsItemDragged(false);
        }*/
        dragSource = nullptr;
    }

    // 4) Always call each slot's handleEvents (hover or move)
    for (auto slot : allSlots) {
        slot->handleEvents(mousePixel, event);
    }


    if (upgrade_strenght_btn) {
        upgrade_strenght_btn->handleEvents(mousePixel,event);
    }
    if (upgrade_dexterity_btn) {
        upgrade_dexterity_btn->handleEvents(mousePixel, event);
    }
    if (upgrade_intelligence_btn) {
        upgrade_intelligence_btn->handleEvents(mousePixel, event);
    }
    if (upgrade_constitution_btn) {
        upgrade_constitution_btn->handleEvents(mousePixel, event);
    }
    if (upgrade_luck_btn) {
        upgrade_luck_btn->handleEvents(mousePixel, event);
    }



    // 5) Sync with player data if needed
    if (loggedInUser && game_ref.getItemChangedFlag()) {
        //if (auto it = loggedInUser->getItem("shoes")) {
          //  shoes_slot->setItem(it);
        //}
        updateSlots();
        game_ref.setItemChangedFlag(false);
    }

}
void PlayerMenu::updateSlots() {
    if (loggedInUser) {
        // synchronizujemy każdy ItemSlot z przedmiotem w ekwipunku gracza
        helmet_slot->setItem(loggedInUser->getItem("helmet"));
        armor_slot->setItem(loggedInUser->getItem("shield"));
        gloves_slot->setItem(loggedInUser->getItem("trousers"));
        shoes_slot->setItem(loggedInUser->getItem("shoes"));
        weapon_slot->setItem(loggedInUser->getItem("weapon"));
        necklace_slot->setItem(loggedInUser->getItem("necklace"));
        belt_slot->setItem(loggedInUser->getItem("belt"));
        ring_slot->setItem(loggedInUser->getItem("ring"));
        lucky_item_slot->setItem(loggedInUser->getItem("luckyitem"));

        // sloty na przedmioty w plecaku
        bag_slot1->setItem(loggedInUser->getItem("1"));
        bag_slot2->setItem(loggedInUser->getItem("2"));
        bag_slot3->setItem(loggedInUser->getItem("3"));
        bag_slot4->setItem(loggedInUser->getItem("4"));
        bag_slot5->setItem(loggedInUser->getItem("5"));
        bag_slot6->setItem(loggedInUser->getItem("6"));
        bag_slot7->setItem(loggedInUser->getItem("7"));
        bag_slot8->setItem(loggedInUser->getItem("8"));
    }
    else {
        // jeżeli nie ma zalogowanego gracza, czyścimy wszystkie sloty
        for (auto slot : allSlots) {
            slot->setItem(nullptr);
        }
    }
}
void PlayerMenu::setLoggedInUser(Player* player) {
    this->loggedInUser = player;
    updateSlots();
}
