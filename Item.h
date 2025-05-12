#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
#include <fstream>
#include <regex>
enum class ItemType {
    WEAPON,
    ARMOR,
    HELMET,
    SHIELD,
    BOOTS,
    RING,
    AMULET,
    CONSUMABLE,
    NONE
};

class Item {
public:
    int id;
    std::string name;
    std::string description;
    ItemType type;
    sf::Sprite sprite;
    sf::Texture texture;

    // Statystyki
    int strength;
    int dexterity;
    int intelligence;
    int constitution;
    int luck;
    Item(int item_id);
    Item(int id, const std::string& texturePath, const std::string& name, ItemType type, int strength, int dexterity,
        int intelligence, int constitution, int luck);

    void setPosition(sf::Vector2f pos);
    sf::FloatRect getGlobalBounds() const;
    int getId();
};
#endif