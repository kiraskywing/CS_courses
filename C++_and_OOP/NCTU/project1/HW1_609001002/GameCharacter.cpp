#include "GameCharacter.h"
using namespace std;

GameCharacter::GameCharacter(string name, string tag, int hp, int atk, int dfn)
    : Object(name, tag), maxHealth(hp), currentHealth(hp), attack(atk), defense(dfn)
    {}

bool GameCharacter::checkIsDead() {
    return currentHealth <= 0;
}

int GameCharacter::takeDamage(int dmg) {
    currentHealth -= dmg;
    return dmg;
}

bool GameCharacter::triggerEvent(Object* obj) {
    return true;
}

void GameCharacter::setMaxHealth(int maxHp) { maxHealth = maxHp; }
void GameCharacter::setCurrentHealth(int hp) { currentHealth = hp; }
void GameCharacter::setAttack(int atk) { attack = atk; }
void GameCharacter::setDefense(int dfn) { defense = dfn; }
int GameCharacter::getMaxHealth() { return maxHealth; }
int GameCharacter::getCurrentHealth() { return currentHealth; }
int GameCharacter::getAttack() { return attack; }
int GameCharacter::getDefense() { return defense; }