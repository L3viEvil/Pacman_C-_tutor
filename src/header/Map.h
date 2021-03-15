#ifndef MAP_H
#define MAP_H

#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Map{
    public:
        Map();
        ~Map();

        void loadMap(char* fileMapPath);
        char** getMap();
        bool renderMap();

    private:
        char **map;

};

#endif