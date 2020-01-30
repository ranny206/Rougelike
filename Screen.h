
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <ncurses.h>

class Screen {
public:
    WINDOW *win;
    explicit Screen(int h, int w, int x, int y);
    ~Screen();
};


#endif //GAME_SCREEN_H
