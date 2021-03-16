#include "Pacman.h"
#include <iostream>

#include <string>

Pacman::Pacman(SDL_Renderer * &gRenderer) {

    this->loadMedia(gRenderer);
}

Pacman::~Pacman() {
    //Free texture if it exists
    for (int i = 0; i < 8; i++) {
        this->pacmanTexture[i].free();
    }

    this->setWidth(0);
    this->setHeight(0);

}

void Pacman::setWidth(int w) {
    this->width = w;
}

void Pacman::setHeight(int h) {
    this->height = h; 
}

void Pacman::setState(int s) {
    this->state = s;
}

void Pacman::setVelocity(int v) {
    this->velocity = v;
}

void Pacman::set_x(int x) {
    this->x = x;
}

void Pacman::set_y(int y) {
    this->y = y;
}

int Pacman::getWidth() {
    return this->width;
}

int Pacman::getHeight() {
    return this-> height;
}

int Pacman::getState() {
    return this->state;
}

int Pacman::getVelocity() {
    return this->velocity;
}

int Pacman::get_x() {
    return this->x;
}

int Pacman::get_y() {
    return this->y;
}

bool Pacman::loadMedia(SDL_Renderer* &gRenderer) {
    //Loading success flag
    bool success = true;
    for (int i = 0; i < 8; i++) {
        // Load texture 
        this->pacmanTexture[i].loadFromFile(this->pacmanTexturePath[i], gRenderer);
    }
    
    for (int i = 0; i < 8; i++) {
        if (this->pacmanTexture[i].get_mTexture() == NULL) {
            success = false;
            printf( "Failed to load texture image %d!\n", i );
            break;
        }
    }

    return success;
}

void Pacman::renderCurrent(SDL_Renderer *&gRenderer) {

    /*
    TODO: draw the pacman character annimated
    */

    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
    
    //Render texture to screen
    this->pacmanTexture[this->animatedState].render(gRenderer, 40, 40);
    
    // update annimatedState
    this->animatedState += 1;
    this->animatedState = this->animatedState % 8;

    SDL_RenderPresent( gRenderer );

    return;
}
