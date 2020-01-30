#include <utility>
#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "GameObject.h"

using namespace std;

class Character: public GameObject{
protected:
    int hp;
    int damage;
public:
    Character(int hp, int dam, char sym);
    int GetHp();
    int GetDam();

};


#endif //GAME_CHARACTER_H
