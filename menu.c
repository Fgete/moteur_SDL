// PROTOTYPES
void Menu_Title(struct renderer, int*);
void Menu_Credits(struct renderer, int*);
void Menu_Quit(struct renderer, int*);
void Menu_Validation(int* gameState, int* menuState, int menuGameState);

// Menu validation (it turns the "while"'s state into chosen menu state)
void Menu_Validation(int* gameState, int* menuState, int menuGameState){
    *gameState = menuGameState;
    *menuState = -1;
}

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
    // Event
    while (titleState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */
                        Menu_Validation(gameState, &titleState, titleGameState[titleIndex]); break;
                    case SDLK_SPACE: /* VALIDATE */
                        Menu_Validation(gameState, &titleState, titleGameState[titleIndex]); break;
                    case SDLK_KP_ENTER: /* VALIDATE */
                        Menu_Validation(gameState, &titleState, titleGameState[titleIndex]); break;
                    case SDLK_ESCAPE: /* RETURN */
                        Menu_Validation(gameState, &titleState, 6); break;
                        break;
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
            if (event.type == SDL_QUIT){
                Menu_Validation(gameState, &titleState, -1); break;
            }
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

// Menu credits
void Menu_Credits(struct renderer sRenderer, int* gameState){
    // Variables
    SDL_Event event;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blackOff = {0, 0, 0, 100};
    int creditsState = 0;
    // Event
    while (creditsState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */
                        Menu_Validation(gameState, &creditsState, 0); break;
                    case SDLK_SPACE: /* VALIDATE */
                        Menu_Validation(gameState, &creditsState, 0); break;
                    case SDLK_KP_ENTER: /* VALIDATE */
                        Menu_Validation(gameState, &creditsState, 0); break;
                    case SDLK_ESCAPE: /* RETURN */
                        Menu_Validation(gameState, &creditsState, 0); break;
                        break;
                    default : break;
                }
            }
            if (event.type == SDL_QUIT){
                Menu_Validation(gameState, &creditsState, -1); break;
            }
            fflush(stdin);
        }
        // Render
        SDL_RenderClear(sRenderer.pRenderer);
        Render_Background(sRenderer);
        Render_Title(sRenderer, "Credits", 0, -50, 1, black);
        Render_Title(sRenderer, "Developer", 0, 100, .5, black);
        Render_Title(sRenderer, DEV_NAME0, 0, 200, .4, black);
        Render_Title(sRenderer, DEV_NAME1, 0, 250, .4, black);
        Render_Title(sRenderer, "Back", 0, 400, .5, black);
        SDL_RenderPresent(sRenderer.pRenderer);
    }
}

// Menu quit
void Menu_Quit(struct renderer sRenderer, int* gameState){
    // Variables
    SDL_Event event;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blackOff = {0, 0, 0, 100};
    int quitIndex = 1;
    int quitState = 0;
    int quitGameState[2] = {-1, 0};
    char quitTitles[2][TITLE_LENGTH];
    strcpy(quitTitles[0], "Yes");
    strcpy(quitTitles[1], "No");
    // Events
    while (quitState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */
                        Menu_Validation(gameState, &quitState, quitGameState[quitIndex]); break;
                    case SDLK_SPACE: /* VALIDATE */
                        Menu_Validation(gameState, &quitState, quitGameState[quitIndex]); break;
                    case SDLK_KP_ENTER: /* VALIDATE */
                        Menu_Validation(gameState, &quitState, quitGameState[quitIndex]); break;
                    case SDLK_ESCAPE: /* RETURN */
                        Menu_Validation(gameState, &quitState, 0); break;
                        break;
                    case SDLK_LEFT: /* NAVIGATION */
                        if (quitIndex > 0)
                            quitIndex--;
                        else
                            quitIndex = 1;
                        break;
                    case SDLK_RIGHT: /* NAVIGATION */
                        if (quitIndex < 1)
                            quitIndex++;
                        else
                            quitIndex = 0;
                        break;
                    default : break;
                }
            }
            if (event.type == SDL_QUIT){
                Menu_Validation(gameState, &quitState, -1); break;
            }
            fflush(stdin);
        }
        // Render
        SDL_RenderClear(sRenderer.pRenderer);
        Render_Background(sRenderer);
        Render_Title(sRenderer, "Are you sure ?", 0, 0, .5, black);
        for (int i = 0; i < 2; i++){
            if (i == quitIndex)
                Render_Title(sRenderer, quitTitles[i], -100 + 200 * i, 100, .5, black);
            else
                Render_Title(sRenderer, quitTitles[i], -100 + 200 * i, 100, .5, blackOff);
        }
        SDL_RenderPresent(sRenderer.pRenderer);
    }
}
