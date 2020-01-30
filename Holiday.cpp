
#include "Holiday.h"

Holiday::Holiday(char sym) : GameObject(sym) {}

state Holiday::Collision(GameObject &gameObject) {
    return gameObject.Collision(*this);
}

state Holiday::Collision(Enemy &enemy) {
    return state::Occupied;;
}

state Holiday::Collision(Me &me) {
    return state::Free;
}

state Holiday::Collision(Wall &wall) {
    return state::Occupied;
}

state Holiday::Collision(Holiday &holiday) {
    return state::Occupied;
}

state Holiday::Collision(Medicine &medicine) {
    return state::Occupied;
}
