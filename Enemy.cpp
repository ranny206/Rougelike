
#include "Enemy.h"
#include "Me.h"
#include "GameObject.h"

Enemy::Enemy(int hp, int dam, char sym) : Character(hp, dam, sym) {}

pair<int, int> Enemy::ChangePos(int x, int y) {
    switch (this->direction){
        case Direction::Right:
            if(counter < 5){ // сделать, чтобы они не ходили в стены и за пределы карты
                y++;
                counter++;
            }
            else{
                y--;
                counter++;
            }
            if(counter == 11){ ////могут возникнуть проблемы с счетчиком
                counter = 0;
            }
            break;
        case Direction::Up:
            if(counter < 5){ // сделать, чтобы они не ходили в стены и за пределы карты
                x++;
                counter++;
            }
            else{
                x--;
                counter++;
            }
            if(counter == 11){ ////могут возникнуть проблемы с счетчиком
                counter = 0;
            }
            break;
    }
    return make_pair(x, y);
}


state Enemy::Collision(GameObject &gameObject) {
    return gameObject.Collision(*this);
}

state Enemy::Collision(Holiday &holiday) {
    return state::Occupied;
}

state Enemy::Collision(Medicine &medicine) {
    return state::Free;
}

state Enemy::Collision(Enemy &enemy) {
    return state::Free;
}

state Enemy::Collision(Wall &wall) {
    return state::Occupied;
}

state Enemy::Collision(Me &me) {
    hp -= me.GetDam();
    if(hp <= 0){
        return state::NeedDelete;
    }
    return state::Occupied;
}



