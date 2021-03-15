#include "Pacman.h"
#include <iostream>
#include <SDL2/SDL.h>

void Pacman::Pacman() {
    return;
}

void Pacman::~Pacman() {
    //Free texture if it exists
	if( this->pacmanTexture != NULL )
	{
		SDL_DestroyTexture( this->pacmanTexture );
		this->pacmanTexture = NULL;
		this->setWidth(0);
		this->setHeight(0);
	}
    return;
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

void renderCurrent(SDL_Renderer *gRenderer) {

    /*
    TODO: draw the pacman character 
    */

    return;
}