
#include "Screen.h"

Screen::Screen(int h, int w, int x, int y) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();
    win = newwin(w, h, x, y);
    nodelay(win, TRUE);
    wrefresh(win);
}

Screen::~Screen() {
    endwin();
}
