// PROTOTYPES
void Render_Background(struct renderer);
void Render_Title(struct renderer, char title[TITLE_LENGTH], float xOffset, float yOffset, float size, SDL_Color color);


// Render menu title
void Render_Title(struct renderer sRenderer, char title[TITLE_LENGTH], float xOffset, float yOffset, float size, SDL_Color color){
    // Font load
    TTF_Font* textFont = TTF_OpenFont("./assets/font/textFont.ttf", 24);
    if (!textFont)
        printf("textFont.ttf --- LOAD ERROR !\n");
    // Sprite
    SDL_Rect titleRect;
    titleRect.w = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO * .5 * size * strlen(title) * .15;
    titleRect.h = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO * .1 * size;
    titleRect.x = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO * .5 - titleRect.w * .5 + WINDOW_RATIO * xOffset;
    titleRect.y = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO * .25 - titleRect.h * .5 + WINDOW_RATIO * yOffset;
    // Render
    rendererObject renderTitle;
    renderTitle.pSurface = TTF_RenderText_Solid(textFont, title, color);
    renderTitle.pTexture = SDL_CreateTextureFromSurface(sRenderer.pRenderer, renderTitle.pSurface);
    SDL_FreeSurface(renderTitle.pSurface);
    SDL_RenderCopy(sRenderer.pRenderer, renderTitle.pTexture, NULL, &titleRect);
    SDL_DestroyTexture(renderTitle.pTexture);
}

// Render background
void Render_Background(struct renderer sRenderer){
    // Sprite
    SDL_Rect backgroundRect;
    backgroundRect.x = 0;
    backgroundRect.y = 0;
    backgroundRect.w = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO;
    backgroundRect.h = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO;
    // Render
    rendererObject renderBackground;
    renderBackground.pSurface = IMG_Load("./assets/background/default.png");
    if (!renderBackground.pSurface)
        SDL_Log("default.png -> LOAD ERROR !\n");
    renderBackground.pTexture = SDL_CreateTextureFromSurface(sRenderer.pRenderer, renderBackground.pSurface);
    SDL_FreeSurface(renderBackground.pSurface);
    SDL_RenderCopy(sRenderer.pRenderer, renderBackground.pTexture, NULL, &backgroundRect);
    SDL_DestroyTexture(renderBackground.pTexture);
}
