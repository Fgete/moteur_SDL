#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// PROTOTYPES
void Menu_Title(struct renderer, int*);
void Menu_Credits(struct renderer, int*);
void Menu_Quit(struct renderer, int*);
void Menu_Validation(int* gameState, int* menuState, int menuGameState);

#endif // MENU_H_INCLUDED
