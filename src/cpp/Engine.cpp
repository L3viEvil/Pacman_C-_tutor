#include "Engine.h"
#include "Config.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

bool Engine::initWindowAndRender() {

    // Initialization flag
    bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		this->gWindow = SDL_CreateWindow( "Pacman C++", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( this->gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			this->gRenderer = SDL_CreateRenderer( this->gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( this->gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}
 
bool Engine::initPacman(SDL_Renderer * &gRenderer) {
    this->pacman = new Pacman(gRenderer);

    return true;
}

bool Engine::initMap() {
    this->map = new Map();

    return true;
}

bool Engine::init() {
    /*
    Init function that inits all window, render, and characters such as pacman, ghosts, map, etc
    */
    
    /* 
    TODO: add success flag to check if initize success or not
    */

    this->initWindowAndRender();
    this->initPacman(this->gRenderer);
    this->initMap();

    return true;
}

void Engine::close() {

	//Free pacman
	// this->pacman->free();
    delete(this->pacman);
    delete(this->map);

	//Destroy window	
	SDL_DestroyRenderer( this->gRenderer );
	SDL_DestroyWindow( this->gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

    return;
}

bool Engine::run() {
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;
    
    // Game loop. This contain game action
    while( !quit )
    {
        //Handle events on queue and check when user deciced to quit game
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        // Handle game logic in here
        /*
        TODO: add game logic in here
        */
        
        /*
        Note that we define render in each object as this function, and in engine, we check the state of each 
        object and call this render function to draw on the screen
        */

        // First, just render the character
        this->pacman->renderCurrent(this->gRenderer);

    }

    // End game and free the memory
    this->close();

    return true;
}
