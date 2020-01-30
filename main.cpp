#include <iostream>

int Level = 1;
#include "Map.h"
#include <unistd.h>
#include <ncurses.h>

using namespace std;


class Game{
public:
    Game()= default;
    void game(){
        Map map();
        map.DrawMap();
        Direction dir;
        while (true){
            int click = wgetch(map.screen.win);
            switch (click) {
                case KEY_LEFT:
                    //y--;
                    dir = Direction::Left;
                case KEY_RIGHT:
                    //y++;
                    dir = Direction::Right;
                case KEY_UP:
                    //x--;
                    dir = Direction::Up;
                case KEY_DOWN:
                    //x++;
                    dir = Direction::Down;
            }
            map.ChangeMap(dir);
            map.DrawMap();
            sleep(1);
        }
    }
};

int main() {
    Game game;
    game.game();
    return 0;
}
