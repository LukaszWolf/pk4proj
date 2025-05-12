#include "Character.h"
#include <sstream>
#include <stdexcept>

Character::Character(std::string nam, std::string img, int str, int dex, int intel, int con,
    int luck, CharacterClass ch_cl, int level): name(nam), img_file_name(img), strength(str),
    dexterity(dex), intelligence(intel), constitution(con) {

}



// Implementacje getterów
std::string Character::getImgName() const { return img_file_name; }
std::string Character::getName() const { return name; }
int Character::getLevel() const { return level; }
int Character::getStrength() const { return strength; }
int Character::getDexterity() const { return dexterity; }
int Character::getIntelligence() const { return intelligence; }
int Character::getConstitution() const { return constitution; }
int Character::getLuck() const { return luck; }
CharacterClass Character::getCharacterClass() const { return ch_class; }