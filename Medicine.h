
#ifndef GAME_MEDICINE_H
#define GAME_MEDICINE_H

#include "GameObject.h"

class Medicine : public GameObject {
public:
    explicit Medicine(char sym);

    pair<int, int> ChangePos(int x, int y) override;

    state Collision(GameObject &gameObject) override;

    state Collision(Enemy &enemy) override;

    state Collision(Me &me) override;

    state Collision(Wall &wall) override;

    state Collision(Holiday &holiday) override;

    state Collision(Medicine &medicine) override;
};


#endif //GAME_MEDICINE_H
