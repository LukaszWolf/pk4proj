//#include "Enemy.h"
//#include <cmath> // dla funkcji matematycznych
//#include <cstdlib> // dla rand()
//Enemy::Enemy(std::string nam, std::string img, int str, int dex, int intel, int con, int lck, CharacterClass ch_cl, int lvl,
//    bool beaten) :
//    Character(nam, img, str, dex, intel, con, lck, ch_cl, lvl),
//    is_beaten(beaten) {}
//
//Enemy::~Enemy() {
//    // Mo¿na dodaæ ewentualne czyszczenie zasobów
//    // np. jeœli Enemy alokowa³ pamiêæ dynamicznie
//}
//
//void Enemy::attack()  {
//    int damage = calculateDamage();
//    if (rand() % 100 < calculateCritChance() * 100) {
//        damage *= 2; // Critical hit
//        std::cout << name << " lands a critical hit for " << damage << " damage!\n";
//    }
//    else {
//        std::cout << name << " attacks for " << damage << " damage\n";
//    }
//}
//
//int Enemy::calculateHP()  {
//    return (constitution * 4) + (level * 8);
//}
//
//int Enemy::calculateDamage()  {
//    return strength + (level / 2);
//}
//
//int Enemy::calculateEvasion()  {
//    return dexterity / 4;
//}
//
//
//double Enemy::calculateCritChance() {
//    return luck / 200.0;
//}
//
//bool Enemy::getIsBeaten() {
//    return hp <= 0;
//}