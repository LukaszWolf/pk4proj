#include "Item.h"

Item::Item(int item_id) {
    std::ifstream file("items.txt");
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku items.txt" << std::endl;
        return;
    }

    std::string line;
    // zaktualizowany regex: dodany "type:" po name:
    std::regex pattern(
        "id:\\s*" + std::to_string(item_id) +
        R"(.*?img:\s*([^\s]+)\s+name:\s*([^\s]+)\s+type:\s*([^\s]+)\s+strength:\s*(\d+)\s+dexterity:\s*(\d+)\s+intelligence:\s*(\d+)\s+constitution:\s*(\d+)\s+luck:\s*(\d+))"
    );

    std::smatch match;
    bool found = false;

    while (std::getline(file, line)) {
        if (std::regex_search(line, match, pattern)) {
            this->id = item_id;

            // wczytanie tekstury
            std::string imagePath = match[1];
            if (!this->texture.loadFromFile(imagePath)) {
                std::cerr << "Nie udalo sie wczytac textury: " << imagePath << std::endl;
            }
            else {
                this->sprite.setTexture(this->texture);
            }

            // wczytanie nazwy i przypisanie typu
            this->name = match[2];
            std::string typeStr = match[3];
            if (typeStr == "WEAPON")     this->type = ItemType::WEAPON;
            else if (typeStr == "ARMOR")      this->type = ItemType::ARMOR;
            else if (typeStr == "HELMET")     this->type = ItemType::HELMET;
            else if (typeStr == "GLOVES")     this->type = ItemType::GLOVES;
            else if (typeStr == "SHOES")      this->type = ItemType::SHOES;
            else if (typeStr == "RING")       this->type = ItemType::RING;
            else if (typeStr == "NECKLACE")   this->type = ItemType::NECKLACE;
            else if (typeStr == "BELT")       this->type = ItemType::BELT;
            else if (typeStr == "LUCKY_ITEM") this->type = ItemType::LUCKY_ITEM;
            else                                 this->type = ItemType::ANY;

            // wczytanie statystyk
            this->strength = std::stoi(match[4]);
            this->dexterity = std::stoi(match[5]);
            this->intelligence = std::stoi(match[6]);
            this->constitution = std::stoi(match[7]);
            this->luck = std::stoi(match[8]);

            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        std::cerr << "Nie znaleziono itemu o id: " << item_id << std::endl;
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


int Item::getId() const
{
    return this->id;
}

//
ItemType Item::getType() const {
    return type;
}
sf::Texture& Item::getTexture()  //referencje zeby nie operowac na kopii, brak const bo jest to obiekt edytowalny
{
    return texture;
}
int Item::getStrenght() const
{
    return strength;
}
int Item::getDexterity() const
{
    return dexterity;
}
int Item::getIntelligence() const
{
    return intelligence;
}
int Item::getConstitution() const
{
    return constitution;
}
int Item::getLuck() const
{
    return luck;
}
std::string Item::getName() const
{
    return name;
}
sf::Sprite& Item::getSprite() 
{
    return sprite;
}
