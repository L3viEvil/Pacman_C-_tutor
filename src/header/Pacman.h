#ifndef PACMAN_H
#define PACMAN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "LTexture.h"

using namespace std;

class Pacman{
    public:
        Pacman(SDL_Renderer* &gRenderer);
        ~Pacman();

        void setWidth(int w);
        void setHeight(int h);
        void setState(int s);
        void setVelocity(int v);
        void set_x(int x);
        void set_y(int y);
        int getWidth();
        int getHeight();
        int getState();
        int getVelocity();
        int get_x();
        int get_y();

        void handleEvent( SDL_Event& e );
		void move();

        void renderCurrent(SDL_Renderer* &gRenderer);
        bool loadMedia(SDL_Renderer* &gRenderer);

        int animatedState = 0;
        // Using class LTexture 
        LTexture pacmanTexture[8];
        string pacmanTexturePath[8] = {
            "./assert/img/pacman_links_1.png",
            "./assert/img/pacman_links_2.png",
            "./assert/img/pacman_links_1.png",
            "./assert/img/pacman_links_1.png",
            "./assert/img/pacman_links_1.png",
            "./assert/img/pacman_links_1.png",
            "./assert/img/pacman_links_1.png",
            "./assert/img/pacman_links_1.png"
        };

    private:
        // SDL_Texture *pacmanTexture;
        int width;
        int height;
        int state;
        int velocity;
        int x;
        int y;
        
};

#endif