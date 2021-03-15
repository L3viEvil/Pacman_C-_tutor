#ifndef PACMAN_H
#define PACMAN_H

#include<SDL2/SDL_h>
#include<iostream>

class Pacman{
    public:
        Pacman();
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


        void renderCurrent(SDL_Renderer* gRenderer);


    private:
        SDL_Texture *pacmanTexture;
        int width;
        int height;
        int state;
        int velocity;
        int x;
        int y;
        
}