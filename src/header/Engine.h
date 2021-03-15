#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Pacman.h"
#include "Map.h"

class Engine{
    public:
        bool init();
        void close();
        bool run();

        // init function
        bool initWindowAndRender();
        bool initPacman(SDL_Renderer * &gRenderer);
        bool initMap();

    private:
        // window game and renderer to draw 
        // the game's characters, map, etc.
        SDL_Window* gWindow;
        SDL_Renderer* gRenderer;
        Pacman *pacman;
        Map* map;

};

#endif