#include "Pacman.h"
#include <iostream>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <string>

Pacman::Pacman(SDL_Renderer * &gRenderer) {

    this->loadMedia(gRenderer);
}

Pacman::~Pacman() {
    //Free texture if it exists
    for (int i = 0; i < 8; i++) {
        if( this->pacmanTexture[i] != NULL ) {
            SDL_DestroyTexture( this->pacmanTexture[i] );
            this->pacmanTexture[i] = NULL;
        }
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

SDL_Texture* Pacman::loadTexture(std::string path, SDL_Renderer* &gRenderer) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool Pacman::loadMedia(SDL_Renderer* &gRenderer) {
    //Loading success flag
    bool success = true;

    // //Load PNG texture
    // gTexture = loadTexture( "/home/ailab/Desktop/pacman/assert/img/pacman_links_1.png" );
    // if( gTexture == NULL )
    // {
    //     printf( "Failed to load texture image!\n" );
    //     success = false;
    // }

    // Load pacmanTexture from images
    for (int i = 0; i < 8; i++) {
        this->pacmanTexture[i] = loadTexture(this->pacmanTexturePath[i], gRenderer);
    }
    
    for (int i = 0; i < 8; i++) {
        if (this->pacmanTexture[i] == NULL) {
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
    SDL_RenderCopy( gRenderer, this->pacmanTexture[this->animatedState], NULL, NULL );
    
    // update annimatedState
    this->animatedState += 1;
    this->animatedState = this->animatedState % 8;

    SDL_RenderPresent( gRenderer );

    return;
}