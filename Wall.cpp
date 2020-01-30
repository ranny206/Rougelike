
#include "Wall.h"

Wall::Wall(char sym) : GameObject(sym){}

pair<int, int> Wall::ChangePos(int x, int y) {
    return GameObject::ChangePos(x, y);
}

state Wall::Collision(GameObject &gameObject) {
    return gameObject.Collision(*this);
}

state Wall::Collision(Enemy &enemy) {
    return state::Occupied;
}

state Wall::Collision(Me &me) {
    return state::Occupied;
}

state Wall::Collision(Wall &wall) {
    return state::Occupied;
}

state Wall::Collision(Holiday &holiday) {
    return state::Occupied;
}

state Wall::Collision(Medicine &medicine) {
    return state::Occupied;
}



