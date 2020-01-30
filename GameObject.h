
#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "Enum.h"
#include "Direction.h"
#include <utility>

using namespace std;

class Wall;

class Enemy;

class Me;

class Holiday;

class Medicine;

class Character;

//class state;

class GameObject {
protected:
    char symbol;
public:
    Direction direction;
    explicit GameObject(char sym);

    char GetSym();

    virtual pair<int, int> ChangePos(int x, int y);

    virtual state Collision(GameObject &gameObject);

    virtual state Collision(Wall &wall);

    virtual state Collision(Enemy &enemy);

    virtual state Collision(Me &me);

    virtual state Collision(Holiday &holiday);

    virtual state Collision(Medicine &medicine);
};


#endif //GAME_GAMEOBJECT_H
