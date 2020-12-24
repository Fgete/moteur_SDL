// PROTOTYPES
void Menu_Title(struct renderer, int*);
void Menu_Options(struct renderer*, int*);
void Menu_Credits(struct renderer, int*);
void Menu_Quit(struct renderer, int*);
void Menu_Navigation(int* gameState, int* menuState, int menuGameState);
void Toggle_Fullscreen(struct renderer*, char[TITLE_LENGTH]);


// Toggle fullscreen
void Toggle_Fullscreen(struct renderer* sRenderer, char option[TITLE_LENGTH]){
    if (WINDOW_RATIO == FS_OFF){
        WINDOW_RATIO = FS_ON;
        strcpy(option, "Fullscreen ON");
    }else{
        WINDOW_RATIO = FS_OFF;
        strcpy(option, "Fullscreen OFF");
    }
    // Redraw screen
    Render_Window(sRenderer);
}

// Menu navigation (it turns the "while"'s state into chosen menu state)
void Menu_Navigation(int* gameState, int* menuState, int menuGameState){
    *gameState = menuGameState;
    *menuState = -1;
}

// Menu title
void Menu_Title(struct renderer sRenderer, int* gameState){
    const int nTitle = 5;
    // Variables
    SDL_Event event;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blackOff = {0, 0, 0, 100};
    int titleIndex = 0;
    int titleState = 0;
    // int titleGameState[5] = {1, 3, 4, 5, 6}; // Final states
    int titleGameState[nTitle]; // Temporary states
    titleGameState[0] = 0;
    titleGameState[1] = 0;
    titleGameState[2] = 4;
    titleGameState[3] = 5;
    titleGameState[4] = 6;
    char titles[nTitle][TITLE_LENGTH];
    strcpy(titles[0], "Start");
    strcpy(titles[1], "Continue");
    strcpy(titles[2], "Options");
    strcpy(titles[3], "Credits");
    strcpy(titles[4], "Quit");
    // Objects
    sprite sBackground = {
        {0, 0},
        {GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)},
        "./assets/background/default.png"};
    // Event
    while (titleState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */
                        Menu_Navigation(gameState, &titleState, titleGameState[titleIndex]); break;
                    case SDLK_SPACE: /* VALIDATE */
                        Menu_Navigation(gameState, &titleState, titleGameState[titleIndex]); break;
                    case SDLK_KP_ENTER: /* VALIDATE */
                        Menu_Navigation(gameState, &titleState, titleGameState[titleIndex]); break;
                    case SDLK_ESCAPE: /* RETURN */
                        Menu_Navigation(gameState, &titleState, 6); break;
                        break;
                    case SDLK_UP: /* NAVIGATION */
                        if (titleIndex > 0)
                            titleIndex--;
                        else
                            titleIndex = nTitle - 1;
                        break;
                    case SDLK_DOWN: /* NAVIGATION */
                        if (titleIndex < nTitle - 1)
                            titleIndex++;
                        else
                            titleIndex = 0;
                        break;
                    default : break;
                }
            }
            if (event.type == SDL_QUIT){
                Menu_Navigation(gameState, &titleState, -1); break;
            }
            fflush(stdin);
        }
        // Render
        SDL_RenderClear(sRenderer.pRenderer);
        Render_Sprite(sRenderer, sBackground);
        Render_Title(sRenderer, GAME_TITLE, 0, -250, 1, black);
        for (int i = 0; i < nTitle; i++){
            if (i == titleIndex)
                Render_Title(sRenderer, titles[i], 0, 100 * i - 50, .5, black);
            else
                Render_Title(sRenderer, titles[i], 0, 100 * i - 50, .5, blackOff);
        }
        SDL_RenderPresent(sRenderer.pRenderer);
    }
}

// Menu options
void Menu_Options(struct renderer* sRenderer, int* gameState){
    const int nOption = 2;
    // Variables
    SDL_Event event;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blackOff = {0, 0, 0, 100};
    int optionIndex = 0;
    int optionState = 0;
    int optionGameState[nOption];
    optionGameState[0] = 4;
    optionGameState[1] = 0;
    char options[nOption][TITLE_LENGTH];
    if (WINDOW_RATIO == FS_OFF)
        strcpy(options[0], "Fullscreen OFF");
    else
        strcpy(options[0], "Fullscreen ON");
    strcpy(options[1], "Back");
    // Objects
    sprite sBackground = {
        {0, 0},
        {GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)},
        "./assets/background/default.png"};
    // Event
    while (optionState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */
                            switch (optionIndex){
                                case 0: /*FULLSCREEN*/
                                    Toggle_Fullscreen(sRenderer, options[0]); break;
                                case 1: /*BACK TO MENU*/
                                    Menu_Navigation(gameState, &optionState, optionGameState[optionIndex]); break;
                                default : break;
                            }
                        break;
                    case SDLK_SPACE: /* VALIDATE */
                        switch (optionIndex){
                                case 0: /*FULLSCREEN*/
                                    Toggle_Fullscreen(sRenderer, options[0]); break;
                                case 1: /*BACK TO MENU*/
                                    Menu_Navigation(gameState, &optionState, optionGameState[optionIndex]); break;
                                default : break;
                            }
                        break;
                    case SDLK_KP_ENTER: /* VALIDATE */
                        switch (optionIndex){
                                case 0: /*FULLSCREEN*/
                                    Toggle_Fullscreen(sRenderer, options[0]); break;
                                case 1: /*BACK TO MENU*/
                                    Menu_Navigation(gameState, &optionState, optionGameState[optionIndex]); break;
                                default : break;
                            }
                        break;
                    case SDLK_ESCAPE: /* RETURN */
                        Menu_Navigation(gameState, &optionState, 0);
                        break;
                    case SDLK_UP: /* NAVIGATION */
                        if (optionIndex > 0)
                            optionIndex--;
                        else
                            optionIndex = nOption - 1;
                        break;
                    case SDLK_DOWN: /* NAVIGATION */
                        if (optionIndex < nOption - 1)
                            optionIndex++;
                        else
                            optionIndex = 0;
                        break;
                    default : break;
                }
            }
            if (event.type == SDL_QUIT){
                Menu_Navigation(gameState, &optionState, 0);
            }
            fflush(stdin);
        }
        // Render
        SDL_RenderClear(sRenderer->pRenderer);
        Render_Sprite(*sRenderer, sBackground);
        Render_Title(*sRenderer, "Options", 0, -250, 1, black);
        for (int i = 0; i < nOption - 1; i++){
            if (i == optionIndex)
                Render_Title(*sRenderer, options[i], -100, 100 * i - 50, .5, black);
            else
                Render_Title(*sRenderer, options[i], -100, 100 * i - 50, .5, blackOff);
        }
        if (optionIndex == nOption - 1)
            Render_Title(*sRenderer, options[nOption - 1], 0, 350, .5, black);
        else
            Render_Title(*sRenderer, options[nOption - 1], 0, 350, .5, blackOff);
        SDL_RenderPresent(sRenderer->pRenderer);
    }
}

// Menu credits
void Menu_Credits(struct renderer sRenderer, int* gameState){
    // Variables
    SDL_Event event;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blackOff = {0, 0, 0, 100};
    int creditsState = 0;
    // Objects
    sprite sBackground = {
        {0, 0},
        {GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)},
        "./assets/background/default.png"};
    sprite sLagLogo = {
        {GetSystemMetrics(SM_CXSCREEN) * .5 - 100, GetSystemMetrics(SM_CYSCREEN) * .5 + 100},
        {200, 180},
        "./assets/image/lag.png"};
    // Event
    while (creditsState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */
                        Menu_Navigation(gameState, &creditsState, 0); break;
                    case SDLK_SPACE: /* VALIDATE */
                        Menu_Navigation(gameState, &creditsState, 0); break;
                    case SDLK_KP_ENTER: /* VALIDATE */
                        Menu_Navigation(gameState, &creditsState, 0); break;
                    case SDLK_ESCAPE: /* RETURN */
                        Menu_Navigation(gameState, &creditsState, 0); break;
                        break;
                    default : break;
                }
            }
            if (event.type == SDL_QUIT){
                Menu_Navigation(gameState, &creditsState, -1); break;
            }
            fflush(stdin);
        }
        // Render
        SDL_RenderClear(sRenderer.pRenderer);
        // Render_Background(sRenderer);
        Render_Sprite(sRenderer, sBackground);
        Render_Title(sRenderer, "Credits", 0, -250, 1, black);
        Render_Title(sRenderer, "Developer", 0, -50, .5, black);
        Render_Title(sRenderer, DEV_NAME0, 0, 50, .4, black);
        Render_Title(sRenderer, DEV_NAME1, 0, 100, .3, blackOff);
        Render_Title(sRenderer, "Back", 0, 350, .5, black);
        Render_Sprite(sRenderer, sLagLogo);
        SDL_RenderPresent(sRenderer.pRenderer);
    }
}

// Menu quit
void Menu_Quit(struct renderer sRenderer, int* gameState){
    const int nQuit = 2;
    // Variables
    SDL_Event event;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color blackOff = {0, 0, 0, 100};
    int quitIndex = 1;
    int quitState = 0;
    int quitGameState[nQuit];
    quitGameState[0] = -1;
    quitGameState[1] = 0;
    char quitTitles[nQuit][TITLE_LENGTH];
    strcpy(quitTitles[0], "Yes");
    strcpy(quitTitles[1], "No");
    // Objects
    sprite sBackground = {
        {0, 0},
        {GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)},
        "./assets/background/default.png"};
    // Events
    while (quitState != -1){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_RETURN: /* VALIDATE */
                        Menu_Navigation(gameState, &quitState, quitGameState[quitIndex]); break;
                    case SDLK_SPACE: /* VALIDATE */
                        Menu_Navigation(gameState, &quitState, quitGameState[quitIndex]); break;
                    case SDLK_KP_ENTER: /* VALIDATE */
                        Menu_Navigation(gameState, &quitState, quitGameState[quitIndex]); break;
                    case SDLK_ESCAPE: /* RETURN */
                        Menu_Navigation(gameState, &quitState, 0); break;
                        break;
                    case SDLK_LEFT: /* NAVIGATION */
                        if (quitIndex > 0)
                            quitIndex--;
                        else
                            quitIndex = nQuit - 1;
                        break;
                    case SDLK_RIGHT: /* NAVIGATION */
                        if (quitIndex < nQuit - 1)
                            quitIndex++;
                        else
                            quitIndex = 0;
                        break;
                    default : break;
                }
            }
            if (event.type == SDL_QUIT){
                Menu_Navigation(gameState, &quitState, -1); break;
            }
            fflush(stdin);
        }
        // Render
        SDL_RenderClear(sRenderer.pRenderer);
        Render_Sprite(sRenderer, sBackground);
        Render_Title(sRenderer, "Are you sure ?", 0, 0, .5, black);
        for (int i = 0; i < nQuit; i++){
            if (i == quitIndex)
                Render_Title(sRenderer, quitTitles[i], -100 + 200 * i, 100, .5, black);
            else
                Render_Title(sRenderer, quitTitles[i], -100 + 200 * i, 100, .5, blackOff);
        }
        SDL_RenderPresent(sRenderer.pRenderer);
    }
}
