#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

// PROTOTYPES
void Render_Background(struct renderer);
void Render_Title(struct renderer, char title[TITLE_LENGTH], float xOffset, float yOffset, float size, SDL_Color color);

#endif // RENDER_H_INCLUDED
