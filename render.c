// PROTOTYPES
void Render_Title(struct renderer, char title[TITLE_LENGTH], float xOffset, float yOffset, float size, SDL_Color color);
void Render_Sprite(struct renderer, struct sprite);
void Render_Window(struct renderer*);


// Render window
void Render_Window(struct renderer* sRenderer){
    if (sRenderer->pWindow)
        SDL_DestroyWindow(sRenderer->pWindow);
    sRenderer->pWindow = SDL_CreateWindow(
        GAME_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO,
        GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO,
        SDL_WINDOW_SHOWN);
    sRenderer->pRenderer = SDL_CreateRenderer(sRenderer->pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
}

// Render menu title
void Render_Title(struct renderer sRenderer, char title[TITLE_LENGTH], float xOffset, float yOffset, float size, SDL_Color color){
    // Font load
    TTF_Font* textFont = TTF_OpenFont("./assets/font/default.ttf", 64);
    if (!textFont)
        printf("default.ttf --- LOAD ERROR !\n");
    // Sprite
    SDL_Rect titleRect;
    titleRect.w = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO * .5 * size * strlen(title) * .1;
    titleRect.h = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO * .1 * size;
    titleRect.x = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO * .5 - titleRect.w * .5 + WINDOW_RATIO * xOffset;
    titleRect.y = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO * .5 - titleRect.h * .5 + WINDOW_RATIO * yOffset;
    // Render
    rendererObject renderTitle;
    renderTitle.pSurface = TTF_RenderText_Solid(textFont, title, color);
    renderTitle.pTexture = SDL_CreateTextureFromSurface(sRenderer.pRenderer, renderTitle.pSurface);
    SDL_FreeSurface(renderTitle.pSurface);
    SDL_RenderCopy(sRenderer.pRenderer, renderTitle.pTexture, NULL, &titleRect);
    SDL_DestroyTexture(renderTitle.pTexture);
}

// Render background
void Render_Sprite(struct renderer sRenderer, struct sprite sprite){
    // Sprite
    SDL_Rect imageRect;
    imageRect.x = sprite.position.x * WINDOW_RATIO;
    imageRect.y = sprite.position.y * WINDOW_RATIO;
    imageRect.w = sprite.scale.x * WINDOW_RATIO;
    imageRect.h = sprite.scale.y * WINDOW_RATIO;
    // Render
    rendererObject renderImage;
    renderImage.pSurface = IMG_Load(sprite.src);
    if (!renderImage.pSurface)
        SDL_Log("%s -> LOAD ERROR !\n", sprite.src);
    renderImage.pTexture = SDL_CreateTextureFromSurface(sRenderer.pRenderer, renderImage.pSurface);
    SDL_FreeSurface(renderImage.pSurface);
    SDL_RenderCopy(sRenderer.pRenderer, renderImage.pTexture, NULL, &imageRect);
    SDL_DestroyTexture(renderImage.pTexture);
}
