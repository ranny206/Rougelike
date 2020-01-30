
#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <vector>
#include <memory>
#include <map>
#include "GameObject.h"
#include "Character.h"
#include "Screen.h"
using namespace std;

class GameObject;

class Map{
public:
    Screen screen;
    vector<vector<char>> my_map;
    map<pair<int, int>, shared_ptr<GameObject>> entity;//в виде гномика

    Map();

    void DrawMap();
    void ChangeMap(Direction direction);

};


#endif //GAME_MAP_H
