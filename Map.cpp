#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include "Map.h"
#include "Me.h"
#include "Enemy.h"
#include "Holiday.h"
#include "Screen.h"
#include "Wall.h"
#include "Medicine.h"


#include <ncurses.h>

using namespace std;

Map::Map(): screen(21, 8, 0, 0){
    ifstream f_map("Level1.txt"); //мепа пар с файлами по ключу уровня
    my_map.resize(7);//C:\Users\NUTA\CLionProjects\Game
    for (int i = 0; i < 7; ++i) {
        my_map[i].resize(20);
        for (int j = 0; j < 20; ++j) {
            f_map >> my_map[i][j];
            if(my_map[i][j] == '#'){
                auto wall = make_shared<Wall>(my_map[i][j]);
                entity.insert(make_pair(make_pair(i, j), wall));
            }
            else if(my_map[i][j] == '*'){
                auto medicine = make_shared<Medicine>(my_map[i][j]);
                entity.insert(make_pair(make_pair(i, j), medicine));
            }
            else if(my_map[i][j] == 'H') {
                auto holiday = make_shared<Holiday>(my_map[i][j]);
                entity.insert(make_pair(make_pair(i, j), holiday));
            }
        }
    }
    ifstream f_hero("Level1_e.txt");
    string line;
    while(getline(f_hero, line)){
        istringstream ss(line);
        int hp, dam;
        char sym;
        pair<int, int> cord;
        ss >> hp >> dam >> sym >> cord.first >> cord.second;
        if(sym == 'I'){
            auto me = make_shared<Me>(hp, dam, sym, hp);//сделать перезапись героя при смене уровня, но сохранить его хп
            entity.insert(make_pair(make_pair(cord.second, cord.first), me));
        }
        else{
            auto enemy = make_shared<Enemy>(hp, dam, sym);
            entity.insert(make_pair(make_pair(cord.second, cord.first), enemy));
        }
    }
}

void Map::DrawMap() {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 20; ++j) {
            mvwaddch(screen.win, i, j, my_map[i][j]);
            wrefresh(screen.win);
        }
    }
    for(auto i: entity){
        if(i.second->GetSym() == 'I'){
            auto h = i.fir
        }
        mvwaddch(screen.win, i.first.first, i.first.second, i.second->GetSym());
        wrefresh(screen.win);
    }
}

void Map::ChangeMap(Direction dir) {
    for(const auto& i: entity){
        i.second->direction = dir;
        auto p = i.second->ChangePos(i.first.first, i.first.second);
        auto f = entity.find(p);
        if(f != entity.end()){
            state ans = i.second->Collision(*(f->second));
            if(ans == state::Free){
                entity.insert(make_pair(p, i.second));
                entity.erase(i.first);
            }
            if(ans == state::NeedDelete){
                entity.erase(i.first);
            }
            entity.erase(f->first);
            int t;
            auto h = *f;
            //int hp;
            auto hp = dynamic_pointer_cast<shared_ptr<Enemy>>(f->second);
            switch(dir){
                case Direction::Right:
                    t = h.first.second - 1;
                    entity.insert(make_pair(make_pair(h.first.first, t), h.second));
                    break;
                case Direction::Left:
                    t = f->first.second + 1;
                    entity.insert(make_pair(f->first.first, t), f->first);
                    break;
                case Direction::Up:
                    t = f->first.first - 1;
                    entity.insert(make_pair(t, f->first.second), f->first);
                    break;
                case Direction::Down:
                    t = f->first.first + 1;
                    entity.insert(make_pair(t, f->first.second), f->first);
                    break;
            }
        }
        else{
            auto tmp = i;
            entity.erase(i.first);
            entity.insert(make_pair(p, tmp.second));
        }
    }
    wrefresh(screen.win);
}

