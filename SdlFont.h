//Création des types initialisation sdl et gestion de la font
#ifndef SDLFONT_H_INCLUDED
#define SDLFONT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 780

typedef struct game{


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_ptexture;
     SDL_Surface *g_psurface;


}game;

typedef struct gameState{

    int g_bRunning;


}gameState;

typedef struct font{

    TTF_Font *g_font;

}font;


typedef struct coordonnees{

    double x;
    double y;
    double w;
    double h;
}coordonnees;

typedef enum {

    Verslehaut=-1,
    Immobile=0,
    Verslebas=1
}EtatRaquette;

typedef enum {
    Pause=-1,
    Jeu=1,
}EtatPause;

typedef struct balle{
    double x;
    double y;
    double r;
    int d;

}balle;

int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame, font *mFont,coordonnees *dep, coordonnees *dep2, balle *bal1);
void delay(unsigned int frameLimit);
void destroy(game *myGame,font *mFont);
void writeSDL(game *myGame,font mFont,int scoreJ1,int scoreJ2);



#endif // SDLFONT_H_INCLUDED
