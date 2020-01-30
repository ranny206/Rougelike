
#ifndef GAME_HOLIDAY_H
#define GAME_HOLIDAY_H

#include "GameObject.h"

class Holiday: public GameObject {
public:
    explicit Holiday(char sym);


    state Collision(GameObject &gameObject) override;

    state Collision(Enemy &enemy) override;

    state Collision(Me &me) override;

    state Collision(Wall &wall) override;

    state Collision(Holiday &holiday) override;

    state Collision(Medicine &medicine) override;

};

#endif //GAME_HOLIDAY_H
