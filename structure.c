// STRUCT
typedef struct renderer{
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
}renderer;

typedef struct rendererObject{
    SDL_Surface *pSurface;
    SDL_Texture *pTexture;
}rendererObject;

typedef struct vector3{
    float x;
    float y;
    // float z;
}vector3;

typedef struct sprite{
    // TRANSFORM
    vector3 position;
    // vector3 rotation;
    vector3 scale;

    // SOURCE
    char src[SRC_LENGTH];
}sprite;
