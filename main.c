#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
// CONST
#define WINDOW_RATIO .5
#define TITLE_LENGTH 10
#define GAME_TITLE "GAME NAME"
// SOURCES
#include "structure.c"
#include "render.c"
#include "menu.c"

int main(int argc, char *argv[])
{
    // Init renderer
    struct renderer sRenderer;
    sRenderer.pWindow = NULL;
    sRenderer.pRenderer = NULL;

    // Load debug
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_Log("Unable to initialize SDL : %s", SDL_GetError());
        return 1;
    }else{
        SDL_Log("SDL2 -> OK");
        // Draw screen
        int windowScaleX = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO;
        int windowScaleY = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO;
        sRenderer.pWindow = SDL_CreateWindow("Moteur SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, windowScaleX, windowScaleY, SDL_WINDOW_SHOWN);

        // Renderer init
        if (sRenderer.pWindow){
            sRenderer.pRenderer = SDL_CreateRenderer(sRenderer.pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
        }

        // Image init
        int flags = IMG_INIT_JPG|IMG_INIT_PNG;
        int initted = IMG_Init(flags);
        if ((initted & flags) != flags){
            SDL_Log("IMG_Init : Failed to init required .png .jpg support !\n");
            SDL_Log("IMG_Init : %s\n", IMG_GetError());
        }else{
            SDL_Log("SDL_image -> OK");
        }

        // TTF init
        TTF_Init();
        if (TTF_Init() != 0){
            SDL_Log("SDL_TTF -> ERROR");
        }else{
            SDL_Log("SDL_TTF -> OK");
        }

        // ------ PROGRAM ------
        int gameState = 0;

        while (gameState != -1){
            switch (gameState){
                case 0: /* MENU */
                    Menu_Title(sRenderer, &gameState); break;
                case 1: /* INIT */ break;
                case 2: /* GAME */ break;
                case 3: /* CONTINUE */ break;
                case 4: /* OPTIONS */ break;
                case 5: /* CREDITS */ break;
                case 6: /* QUIT */ break;
                default : gameState = -1; break;
            }
        }
    }

    // ------ QUIT ------
    SDL_Quit();

    system("cls");

    return 0;
}
