
#include "Character.h"
#include "GameObject.h"

Character::Character(int hp, int dam, char sym): GameObject(sym), hp(hp), damage(dam) {}

int Character::GetHp() {
    return hp;
}

int Character::GetDam() {
    return damage;
}




