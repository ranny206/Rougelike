
#include "GameObject.h"

GameObject::GameObject(char sym): symbol(sym){}

char GameObject::GetSym() {
    return symbol;
}

pair<int, int> GameObject::ChangePos(int x, int y) {
    return make_pair(x, y);
}

state GameObject::Collision(GameObject &gameObject) {
    return state::Free;
}

state GameObject::Collision(Wall &wall) {
    return state::Free;
}

state GameObject::Collision(Me &me) {
    return state::Free;
}

state GameObject::Collision(Holiday &holiday) {
    return state::Free;
}

state GameObject::Collision(Medicine &medicine) {
    return state::Free;
}

state GameObject::Collision(Enemy &enemy) {
    return state::Free;
}




