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
    float z;
}vector3;

typedef struct vector2{
    float x;
    float y;
}vector2;

typedef struct transform{
    vector3 position;
    // vector3 rotation;
    vector3 scale;
}transform;

typedef struct sprite{
    transform transform;
    char src[SRC_LENGTH];
    vector2 spriteSize;
    vector2 tileCount;
    int frame;
    int nTile;
}sprite;

typedef struct text{
    transform transform;
    char caption[TITLE_LENGTH];
    SDL_Color color;
}text;
