#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include <stdbool.h>

static const unsigned SCREEN_WIDTH = 700;
static const unsigned SCREEN_HEIGHT = 700;


int main(int argc, char *argv[])
{
	ObjGame game;
	static Mode mode;
	bool isRunning = true;
	SDL_Window* window = NULL;
	ObjPlay playOne;
	ObjPlay playTwo;



	if(SDL_Init(SDL_INIT_VIDEO))
	{
		puts("falha ao iniciar sdl");
		exit(1);
	}
	else
	{
		window = SDL_CreateWindow("Dama Ruralina",SDL_WINDOWPOS_UNDEFINED, 
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, 
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN); 
		if(window == NULL)
		{
			printf("Error %i\n",SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}

	IMG_Init(IMG_INIT_PNG);

	game = newGame("C:\\Users/Robertinho do fv/Documents/UFRRJ\4° Periodo/Tópicos CCOMP/Dama-Ruralina-IM/Tabuleiro.png","PeaoOne.png","PeaoTwo.png");
    
    playOne = newPlay();
    playTwo = newPlay();

    while(isRunning)
    {
    	isRunning = game->Run(game, mode, playOne, playTwo);
    }

	return 0;
}