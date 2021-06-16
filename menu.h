#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// PROTOTYPES
void Toggle_Fullscreen(struct renderer*, struct text*);
void Menu_Navigation(int* gameState, int* menuState, int menuGameState);
void Menu_Title(struct renderer, int*);
void Menu_Options(struct renderer*, int*);
void Menu_Credits(struct renderer, int*);
void Menu_Quit(struct renderer, int*);

#endif // MENU_H_INCLUDED
