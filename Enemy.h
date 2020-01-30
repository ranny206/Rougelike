
#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include <utility>
#include "Character.h"

using namespace std;

class Enemy : public Character {
private:
    int counter = 0;
public:
    Enemy(int hp, int dam, char sym);

    pair<int, int> ChangePos(int x, int y) override;

    state Collision(GameObject &gameObject) override;

    state Collision(Wall &wall) override;

    state Collision(Enemy &enemy) override;

    state Collision(Medicine &medicine) override;

    state Collision(Holiday &holiday) override;

    state Collision(Me &me) override;

};


#endif //GAME_ENEMY_H
