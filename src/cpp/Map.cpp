#include "Map.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

Map::Map() {
    return;
}

Map::~Map() {
    return;
}

void Map::loadMap(char* fileMapPath) {

    /* TODO:
    Load map from file txt to char** map
    */

    return;
}
 
char** Map:: getMap() {
    return this->map;
}

bool Map::renderMap() {

    /* TODO:
    Render the map on the window
    */

    return true;
}