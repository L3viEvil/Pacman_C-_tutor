#ifndef PACMAN_H
#define PACMAN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

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


        void renderCurrent(SDL_Renderer* &gRenderer);
        bool loadMedia(SDL_Renderer* &gRenderer);
        SDL_Texture* loadTexture( std::string path, SDL_Renderer* &gRenderer);

        int animatedState = 0;
        SDL_Texture *pacmanTexture[8];
        string pacmanTexturePath[8] = {
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png",
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_2.png",
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png",
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png",
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png",
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png",
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png",
            "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png"
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