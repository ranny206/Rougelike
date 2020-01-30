
#include "Medicine.h"
#include "GameObject.h"

Medicine::Medicine(char sym) : GameObject(sym) {}

pair<int, int> Medicine::ChangePos(int x, int y) {
    return GameObject::ChangePos(x, y);
}

state Medicine::Collision(GameObject &gameObject) {
    return gameObject.Collision(*this);
}

state Medicine::Collision(Enemy &enemy) {
    return state::Occupied;
}

state Medicine::Collision(Me &me) {
    return state::NeedDelete;
}

state Medicine::Collision(Wall &wall) {
    return state::Occupied;
}

state Medicine::Collision(Holiday &holiday) {
    return state::Occupied;
}

state Medicine::Collision(Medicine &medicine) {
    return state::Occupied;
}
