// PROTOTYPES
void Render_Title(struct renderer, char title[TITLE_LENGTH], float xOffset, float yOffset, float size, SDL_Color color);
void Render_Text(struct renderer, struct text text, SDL_Color color);
// void Render_Collection(struct renderer, struct sprite[N_OBJ_COLLECTION], struct text[N_OBJ_COLLECTION]);
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

void Render_Title(struct renderer sRenderer, char title[TITLE_LENGTH], float xOffset, float yOffset, float size, SDL_Color color){

}

// Render text
void Render_Text(struct renderer sRenderer, struct text text, SDL_Color color){
    // Font load
    TTF_Font* textFont = TTF_OpenFont("./assets/font/default.ttf", 64);
    if (!textFont)
        printf("default.ttf --- LOAD ERROR !\n");
    // Sprite
    SDL_Rect titleRect;
    titleRect.w = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO * .5 * text.transform.scale.x * strlen(text.caption) * .1;
    titleRect.h = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO * .1 * text.transform.scale.y;
    titleRect.x = GetSystemMetrics(SM_CXSCREEN) * WINDOW_RATIO * .5 - titleRect.w * .5 + WINDOW_RATIO * text.transform.position.x;
    titleRect.y = GetSystemMetrics(SM_CYSCREEN) * WINDOW_RATIO * .5 - titleRect.h * .5 + WINDOW_RATIO * text.transform.position.y;
    // Render
    rendererObject renderTitle;
    renderTitle.pSurface = TTF_RenderText_Solid(textFont, text.caption, color);
    renderTitle.pTexture = SDL_CreateTextureFromSurface(sRenderer.pRenderer, renderTitle.pSurface);
    SDL_FreeSurface(renderTitle.pSurface);
    SDL_RenderCopy(sRenderer.pRenderer, renderTitle.pTexture, NULL, &titleRect);
    SDL_DestroyTexture(renderTitle.pTexture);
}

// Render background
void Render_Sprite(struct renderer sRenderer, struct sprite sprite){
    // Sprite
    SDL_Rect imageRect;
    imageRect.x = sprite.transform.position.x * WINDOW_RATIO;
    imageRect.y = sprite.transform.position.y * WINDOW_RATIO;
    imageRect.w = sprite.transform.scale.x * WINDOW_RATIO;
    imageRect.h = sprite.transform.scale.y * WINDOW_RATIO;
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
