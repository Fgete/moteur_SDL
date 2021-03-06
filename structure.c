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
    SDL_Surface *surface;
    vector2 spriteSize;
    vector2 tileCount;
    int frame;
    int nTile;
    // I will add an animation speed value
    // int frameRate;
    // I will also add a physic type and some associated values
    // physic sPhysic;
}sprite;

typedef struct text{
    transform transform;
    char caption[TITLE_LENGTH];
    SDL_Color color;
}text;

enum physicTypeList {none, solid, soft};
enum colliderShapeList {circle, box};

typedef struct physic{
    enum physicTypeList physicType;
    enum colliderShapeList colliderShape;
    vector3 colliderBox;
    int colliderRadius;
}physic;
