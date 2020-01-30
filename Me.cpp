#include <utility>
#include "Me.h"
#include "Character.h"
#include "Enemy.h"
#include "Medicine.h"
#include <ncurses.h>

using namespace std;

Me::Me(int h, int dam, char sym, int maxhp): Character(h, dam, sym), maxhp(maxhp) {}

pair<int, int> Me::ChangePos(int x, int y) {
    switch (direction) {
        case Direction::Left:
            y--;
            return make_pair(x, y);
        case Direction::Right:
            y++;
            return make_pair(x, y);
        case Direction::Up:
            x--;
            return make_pair(x, y);
        case Direction::Down:
            x++;
            return make_pair(x, y);
    }
}

state Me::Collision(GameObject &gameObject){
    return gameObject.Collision(*this);
}
//real action
state Me::Collision(Holiday &holiday) {
    return state::NextLevel;
}

state Me::Collision(Medicine &medicine) {
    this->hp += 20;
    if (hp > 100) {
        hp = 100;
    }
    return state::Free;
}

state Me::Collision(Enemy &enemy) {
    this->hp -= enemy.GetDam();
    if(hp <= 0){
        return state::NeedDelete;
    }
    return state::Occupied;
}

state Me::Collision(Wall &wall) {
    return state::Occupied;
}

state Me::Collision(Me &me) {
    return state::Free;
}











