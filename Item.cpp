#include "Item.h"

Item::Item(int id) {
    std::ifstream file("items.txt");
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
        return;
    }

    std::string line;
    std::regex pattern("id: " + std::to_string(id) +
        R"(.*?img: ([^\s]+)\s+name: ([^\s]+)\s+strenght: (\d+)\s+dexterity: (\d+)\s+intelligence: (\d+)\s+constitution: (\d+)\s+luck: (\d+))");

    std::smatch match;
    bool found = false;

    while (std::getline(file, line)) {
        if (std::regex_search(line, match, pattern)) {
            this->id = id;

            std::string imagePath = match[1];
            if (!this->texture.loadFromFile(imagePath)) {
                std::cerr << "Nie udalo sie wczytac textury: " << imagePath << std::endl;
            }
            else {
                this->sprite.setTexture(this->texture);
            }

            this->name = match[2];
            this->strength = std::stoi(match[3]);
            this->dexterity = std::stoi(match[4]);
            this->intelligence = std::stoi(match[5]);
            this->constitution = std::stoi(match[6]);
            this->luck = std::stoi(match[7]);

            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Wczytano item ID: " << this->id << std::endl;
        std::cout
            << "id:" << this->id
            //<<"texture: "<<this->match[1]
            << "name:" << this->name
            << "strenght:" << this->strength
            << "dext:" << this->dexterity
            << "inte:" << this->intelligence
            << "constit:" << this->constitution
            << "luck:" << this->luck << std::endl;
        std::cout << "------------------------------------" << std::endl;

    }
    else {
        std::cout << "Nie znaleziono itemu o id: " << id << std::endl;
    }
}
    /*
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "nie udalo sie wczytac tekstury" << texturePath << std::endl;
    }
    else {
        sprite.setTexture(texture);
    }
    */


/*
Item::Item(int item_id) {
    this->id = item_id;
    std::cout << "stworzono item id: " << item_id << std::endl;
    //tu sie powinien otworzyc plik z itemami i sie powinny statystyki wczytac itp;
    //statystyki mozna jako mnozniki zrobic ze mnoza basic staty ale chyba bez sensu wsm
}
*/

void Item::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

sf::FloatRect Item::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

int Item::getId()
{
    return this->id;
}
