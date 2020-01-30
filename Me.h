#include <utility>
#ifndef GAME_ME_H
#define GAME_ME_H

#include "Character.h"

using namespace std;

class Me: public Character{
private:
    int maxhp;
public:
    Me(int hp, int dam, char sym, int maxhp);

    pair<int, int> ChangePos(int x, int y) override;

    state Collision(GameObject &gameObject) override;

    state Collision(Wall &wall) override;

    state Collision(Enemy &enemy) override;

    state Collision(Medicine &medicine) override;

    state Collision(Holiday &holiday) override;

    state Collision(Me &me) override;
};


#endif //GAME_ME_H
