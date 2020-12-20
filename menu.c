// PROTOTYPES
void Menu_Title(struct renderer, int*);

// Menu title
void Menu_Title(struct renderer sRenderer, int* gameState){
    // Variables
    SDL_Event event;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blackOff = {0, 0, 0, 100};
    int titleIndex = 0;
    int titleState = 0;
    int titleGameState[5] = {1, 3, 4, 5, 6};
    char titles[5][TITLE_LENGTH];
    strcpy(titles[0], "Start");
    strcpy(titles[1], "Continue");
    strcpy(titles[2], "Options");
    strcpy(titles[3], "Credits");
    strcpy(titles[4], "Quit");
    while (titleState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */ break;
                    case SDLK_SPACE: /* VALIDATE */ break;
                    case SDLK_KP_ENTER: /* VALIDATE */ break;
                    case SDLK_ESCAPE: /* RETURN */ *gameState = -1; break;
                    case SDLK_UP: /* NAVIGATION */
                        if (titleIndex > 0)
                            titleIndex--;
                        else
                            titleIndex = strlen(titles) - 1;
                        break;
                    case SDLK_DOWN: /* NAVIGATION */
                        if (titleIndex < strlen(titles) - 1)
                            titleIndex++;
                        else
                            titleIndex = 0;
                        break;
                    default : break;
                }
            }
            if (event.type == SDL_QUIT)
                *gameState = -1;
                titleState = -1;
            fflush(stdin);
        }
        // Render
        SDL_RenderClear(sRenderer.pRenderer);
        Render_Background(sRenderer);
        Render_Title(sRenderer, GAME_TITLE, 0, -50, 1, black);
        for (int i = 0; i < strlen(titles); i++){
            if (i == titleIndex)
                Render_Title(sRenderer, titles[i], 0, 100 * (i+1), .5, black);
            else
                Render_Title(sRenderer, titles[i], 0, 100 * (i+1), .5, blackOff);
        }
        SDL_RenderPresent(sRenderer.pRenderer);
    }
}
