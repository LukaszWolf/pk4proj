#include "Player.h"
#include "Game.h"
#include <cmath> // Do obliczeñ statystyk

Player::Player(std::string nam, std::string img, int str, int dex, int intel, int con, int lck, CharacterClass ch_cl, int lvl,
    Mount mnt, int tht, double gld, int mush, int hglass, Game&game):
Character(nam, img,str,dex,intel,con,lck,ch_cl,lvl),
mount(mnt), thirst_of_adventure(tht),gold(gld), mushrooms(mush), hourglasses(hglass), game_ref(game) {
    initEquipment();
}



Player::~Player() {}

// Implementacje metod wirtualnych
void Player::attack() {
    std::cout << name << " attacks for " << calculateDamage() << " damage!\n";
    if (rand() % 100 < calculateCritChance() * 100) {
        std::cout << "Critical hit!\n";
    }
}

int Player::calculateHP() {
    return (constitution * 5) + (level * 10);
}

int Player::calculateDamage() {
    int base = strength;
    if (ch_class == CharacterClass::WARRIOR) base *= 1.5;
    else if (ch_class == CharacterClass::MAGE) base += intelligence;
    return base + (dexterity / 2);
}

int Player::calculateEvasion() {
    return dexterity / 3 + (mount == Mount::HORSE ? 5 : 0);
}

int Player::calculateResistance() {
    return intelligence / 2 + armor / 4;
}

int Player::calculateDamageReduction() {
    return armor / 5 + (mount == Mount::DRAGON ? 3 : 0);
}

double Player::calculateCritChance() {
    return luck / 100.0 + (mount == Mount::TIGER ? 0.05 : 0);
}

// Implementacje metod specyficznych dla Player
void Player::calculateXPtoNextLvl() {
    // Przyk³adowa formu³a doœwiadczenia
    int xp_needed = level * level * 100;
    std::cout << "XP needed for next level: " << xp_needed << "\n";
}

void Player::levelUp() {
    level++;
    strength += (ch_class == CharacterClass::WARRIOR) ? 2 : 1;
    dexterity += (ch_class == CharacterClass::SCOUT) ? 2 : 1;
    intelligence += (ch_class == CharacterClass::MAGE) ? 2 : 1;
    constitution += 1;
    luck += 1;
    updateStats();
}

void Player::upgradeStat() {
    // Tutaj mo¿na dodaæ logikê ulepszania statystyk
    // np. za punkty umiejêtnoœci
    strength++;
    updateStats();
}



void Player::updateStats() {
    hp = calculateHP();
    damage = calculateDamage();
    evasion = calculateEvasion();
    resistance = calculateResistance();
    damage_reduction = calculateDamageReduction();
    crit_chance = calculateCritChance();
}

void Player::initEquipment()
{
    this->equipment  = {
            {"helmet", nullptr},
            {"shield", nullptr},
            {"trousers", nullptr},
            {"shoes", nullptr},
            {"weapon", nullptr},
            {"necklace", nullptr},
            {"belt", nullptr},
            {"ring", nullptr},
            {"luckyitem", nullptr},
            {"1", nullptr},
            {"2", nullptr},
            {"3", nullptr},
            {"4", nullptr},
            {"5", nullptr},
            {"6", nullptr},
            {"7", nullptr},
            {"8", nullptr},
    };
}
// Getter – tylko do odczytu
Item* Player::getItem(const std::string& slot_name) const {
    auto it = equipment.find(slot_name);
    if (it != equipment.end()) {
        return it->second;
    }
    return nullptr;
}

// Setter – do ustawienia wskaŸnika
void Player::setItem(const std::string& slot_name, Item* item) {
    auto it = equipment.find(slot_name);
    if (it != equipment.end()) {
        it->second = item;
    }
    else {
        std::cerr << "Invalid slot name";
    }
	if(!game_ref.getItemChangedFlag())
	this->game_ref.setItemChangedFlag(true);
}
void Player::printEquipment() {
    std::cout << "Ekwipunek gracza:\n";
    for (const  auto &pair : equipment) {
        if (pair.second) {
            std::cout << pair.first << " -> Przedmiot ID: "
                << "id:" << pair.second->getId()
                //<<"texture: "<<this->match[1]
                << "name:" << pair.second->name
                << "strenght:" << pair.second->strength
                << "dext:" << pair.second->dexterity
                << "inte:" << pair.second->intelligence
                << "constit:" << pair.second->constitution
                << "luck:" << pair.second->luck << std::endl;
        }
        else {
            std::cout << pair.first << " -> brak\n";
        }
    }
}






void Player::updateEquipment(std::string filename)
{
	//std::string name = login; // <-- tutaj wpisz nazwê gracza do wyszukania
	
	std::ifstream file(filename);
	if (!file) {
		std::cout << "nie udalo sie otworzyc pliku";
		return;
	}
	else {
		std::cout << "otwarto plik " << std::endl;
	}
	std::string line;
	bool found = false;
	// regex do dopasowania danych gracza
	std::regex pattern(R"(login:\s*(\w+)\s+helmet:\s*(\d+)\s+shield:\s*(\d+)\s+trousers:\s*(\d+)\s+shoes:\s*(\d+)\s+weapon:\s*(\d+)\s+necklace:\s*(\d+)\s+belt:\s*(\d+)\s+ring:\s*(\d+)\s+luckyitem:\s*(\d+)\s+slot1:\s*(\d+)\s+slot2:\s*(\d+)\s+slot3:\s*(\d+)\s+slot4:\s*(\d+)\s+slot5:\s*(\d+)\s+slot6:\s*(\d+)\s+slot7:\s*(\d+)\s+slot8:\s*(\d+))");
	while (std::getline(file, line) and !found) {
		//std::cout << line;
		std::smatch match;
		std::cout << std::endl << std::endl << std::endl;
		if (std::regex_match(line, match, pattern)) {
			//std::cout << match[1] << ",,,,,," << game_ref.getLoggedInPlayer()->getName() << std::endl;
			std::cout << match[1] << ",,,,,," << this->getName() << std::endl;
			//if (std::string( match[1]) == std::string(game_ref.getLoggedInPlayer()->getImgName())) { //czemu to nie dzialaXD
			if (std::string(match[1]) == "player1") {
				found = true;
				//std::cout << "MATCH DZIALAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
				Item* helmet = (std::stoi(match[2]) != 0) ? new Item(std::stoi(match[2])) : nullptr;
				Item* shield = (std::stoi(match[3]) != 0) ? new Item(std::stoi(match[3])) : nullptr;
				Item* trousers = (std::stoi(match[4]) != 0) ? new Item(std::stoi(match[4])) : nullptr;
				Item* shoes = (std::stoi(match[5]) != 0) ? new Item(std::stoi(match[5])) : nullptr;
				Item* weapon = (std::stoi(match[6]) != 0) ? new Item(std::stoi(match[6])) : nullptr;
				Item* necklace = (std::stoi(match[7]) != 0) ? new Item(std::stoi(match[7])) : nullptr;
				Item* belt = (std::stoi(match[8]) != 0) ? new Item(std::stoi(match[8])) : nullptr;
				Item* ring = (std::stoi(match[9]) != 0) ? new Item(std::stoi(match[9])) : nullptr;
				Item* luckyitem = (std::stoi(match[10]) != 0) ? new Item(std::stoi(match[10])) : nullptr;

				Item* slot1 = (std::stoi(match[11]) != 0) ? new Item(std::stoi(match[11])) : nullptr;
				Item* slot2 = (std::stoi(match[12]) != 0) ? new Item(std::stoi(match[12])) : nullptr;
				Item* slot3 = (std::stoi(match[13]) != 0) ? new Item(std::stoi(match[13])) : nullptr;
				Item* slot4 = (std::stoi(match[14]) != 0) ? new Item(std::stoi(match[14])) : nullptr;
				Item* slot5 = (std::stoi(match[15]) != 0) ? new Item(std::stoi(match[15])) : nullptr;
				Item* slot6 = (std::stoi(match[16]) != 0) ? new Item(std::stoi(match[16])) : nullptr;
				Item* slot7 = (std::stoi(match[17]) != 0) ? new Item(std::stoi(match[17])) : nullptr;
				Item* slot8 = (std::stoi(match[18]) != 0) ? new Item(std::stoi(match[18])) : nullptr;

				this->setItem("helmet", helmet);
				this->setItem("shield", shield);
				this->setItem("trousers", trousers);
				this->setItem("shoes", shoes);
				this->setItem("weapon", weapon);
				this->setItem("necklace", necklace);
				this->setItem("belt", belt);
				this->setItem("ring", ring);
				this->setItem("luckyitem", luckyitem);
				this->setItem("1", slot1);

				this->setItem("2", slot2);
				this->setItem("3", slot3);
				this->setItem("4", slot4);
				this->setItem("5", slot5);
				this->setItem("6", slot6);
				this->setItem("7", slot7);
				this->setItem("8", slot8);
				//player->printEquipment();
								
			};
			///






						//std::cout << std::endl<<std::endl<<items["helmet"];

			break; // gracz znaleziony, koniec pêtli
			//player->printEquipment();
		}
		else {
			std::cout << "nie udalo sie wczytac ekwipunku";
			//	player->printEquipment();
		}
	}
}/*
	Item* helmet = (1) ? new Item(100) : nullptr;
	Item* shield = (1) ? new Item(200) : nullptr;
	Item* trousers = (1) ? new Item(300) : nullptr;
	Item* shoes = (1) ? new Item(400) : nullptr;
	Item* weapon = (1) ? new Item(500) : nullptr;
	Item* necklace = (1) ? new Item(600) : nullptr;
	Item* belt = (1) ? new Item(700) : nullptr;
	Item* ring = (1) ? new Item(800) : nullptr;
	Item* luckyitem = (1) ? new Item(900) : nullptr;

	Item* slot1 = (1) ? new Item(110) : nullptr;
	Item* slot2 = (1) ? new Item(120) : nullptr;
	Item* slot3 = (1) ? new Item(130) : nullptr;
	Item* slot4 = (1) ? new Item(140) : nullptr;
	Item* slot5 = (1) ? new Item(150) : nullptr;
	Item* slot6 = (1) ? new Item(160) : nullptr;
	Item* slot7 = (1) ? new Item(170) : nullptr;
	Item* slot8 = (1) ? new Item(180) : nullptr;

	// Przypisanie do ekwipunku gracza
	player->setItem("helmet", helmet);
	player->setItem("shield", shield);
	player->setItem("trousers", trousers);
	player->setItem("shoes", shoes);
	player->setItem("weapon", weapon);
	player->setItem("necklace", necklace);
	player->setItem("belt", belt);
	player->setItem("ring", ring);
	player->setItem("luckyitem", luckyitem);

	player->setItem("1", slot1);
	player->setItem("2", slot2);
	player->setItem("3", slot3);
	player->setItem("4", slot4);
	player->setItem("5", slot5);
	player->setItem("6", slot6);
	player->setItem("7", slot7);
	player->setItem("8", slot8);
	*/





// Gettery
int Player::getMushrooms() { return mushrooms; }
int Player::getHourglasses() { return hourglasses; }
double Player::getGold() { return gold; }
int Player::getThirst() { return thirst_of_adventure; }
Mount Player::getMount() { return mount; }