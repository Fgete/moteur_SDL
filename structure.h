#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

// STRUCT
typedef struct renderer{
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
}renderer;

typedef struct rendererObject{
    SDL_Surface *pSurface;
    SDL_Texture *pTexture;
}rendererObject;

#endif // STRUCTURE_H_INCLUDED
