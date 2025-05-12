#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
//#include "Game.h"
#include <iostream>
#include <vector>
enum class Mount {
	COW,
	HORSE,
	TIGER,
	DRAGON,
	NONE
};

class Game;
class Player : public Character
{
	//std::vector<Item> equipment;
	// itemy na postaci
	Mount mount;
	int thirst_of_adventure;
	double gold;
	int mushrooms, hourglasses;
	int armor;

	bool stat_changed; // ustawiac na true gdy statystyka postaci sie zmieni i wtedy handle events wie ze trzeba cos zmienic, czy tam update
	
	std::map<std::string, Item*> equipment;
	Game& game_ref;
public:
	Player();
	Player(std::string nam, std::string img, int strength, int dexterity, int intelligence, int constitution,int luck, CharacterClass ch_cl, int level,
		Mount mount, int thirst, double gold, int mush, int hglass, Game&game); 
	~Player();

	void calculateXPtoNextLvl();
	void levelUp(); //trzeba obsluzyc wszystkie rzeczy zwiazane ze zmiana statystyk np
	void upgradeStat(); //jakis enum moze
	//void changeItem(); //tu tez
	void updateStats(); // po kazdej zmianie eq itp i po wylevelowaniu np
	
	void initEquipment();

	void attack() override final ;
	int calculateHP() override final;
	int calculateDamage() override final;
	int calculateEvasion() override final;
	int calculateResistance() override final;
	int calculateDamageReduction() override final;
	double calculateCritChance() override final;

	void printEquipment();

	Item* getItem(const std::string& slot_name) const;
	void setItem(const std::string& slot_name, Item* item);
	int getMushrooms();
	int getHourglasses();
	double getGold();
	int getThirst();
	Mount getMount();

	void updateEquipment(std::string filename);


};

#endif