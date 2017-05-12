#include "raquettes.h"
//Gestion des raquettes et des touches

//But : récupérer les entrées utilisateur pour déplacer les raquettes mettre le jeu en pause ou quitter le jeu ( manque la posibilité de rejouer prévue mais pas en place)
//ENTRE : etat du jeu, les booleens liées aux raquettes et l'état pause
//SORTIE: changement des booleens pour l'état demandé
void handleEvents(gameState *state,EtatRaquette *boo1,EtatRaquette *boo2,EtatPause *Pboo){


    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                {
                    case SDLK_z: *boo1=Verslehaut ; break;
                    case SDLK_s: *boo1=Verslebas; break;
                    case SDLK_UP: *boo2=Verslehaut; break;
                    case SDLK_DOWN: *boo2=Verslebas; break;
                    case SDLK_SPACE: *Pboo=*Pboo*-1; break;
                    case SDLK_ESCAPE: state->g_bRunning=0;break;
                }
                break;

        case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_z: *boo1=Immobile ; break;
                    case SDLK_s: *boo1=Immobile; break;
                    case SDLK_UP: *boo2=Immobile; break;
                    case SDLK_DOWN: *boo2=Immobile; break;
                }
                break;

        default:break;

        }
    }


}
//But : déplacer les raquettes en suivant l'état des booleens
//ENTRE : les boolens des raquettes et leurs positions
//SORTIE: nouvelle position des raquettes
void MouvementRaquette(coordonnees *dep,coordonnees *dep2,EtatRaquette *boo1,EtatRaquette *boo2){
    //dep->y-- dep->y++ dep2->y-- dep2->y++
    //Gestion raquette 1 (gauche)
    if ((*boo1==Verslebas) && (dep->y<SCREEN_HEIGHT-dep->h))
    {
        dep->y++;
    } else if (*boo1==Verslehaut && dep->y>0){
        dep->y--;
    }
    //Gestion raquette 2 (droite)
    if (*boo2==Verslebas && dep2->y<SCREEN_HEIGHT-dep2->h)
    {
        dep2->y++;
    } else if (*boo2==Verslehaut && dep2->y>0){
        dep2->y--;
    }

}

//But : COnstruction raquette 1
//ENTRE : la fenetre et la position de la raquette 1
//SORTIE: la raquette dans la fenetre
void renderRaquette1(game *myGame,coordonnees *dep) {

        SDL_Rect rectangle;
        SDL_SetRenderDrawColor(myGame->g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

        rectangle.x=0;//debut x
        rectangle.y=0;//debut y
        rectangle.w=11; //Largeur
        rectangle.h=SCREEN_HEIGHT; //Hauteur

        SDL_RenderFillRect(myGame->g_pRenderer,&rectangle);

        SDL_SetRenderDrawColor(myGame->g_pRenderer,255,0,0,255);
        //Définition du rectangle 1 a dessiner

        rectangle.x=dep->x;//debut x
        rectangle.y=dep->y;//debut y
        rectangle.w=dep->w; //Largeur
        rectangle.h=dep->h; //Hauteur

        SDL_RenderFillRect(myGame->g_pRenderer,&rectangle);

        //SDL_RenderPresent(myGame->g_pRenderer);



}
//But : COnstruction raquette 2
//ENTRE : la fenetre et la position de la raquette 2
//SORTIE: la raquette dans la fenetre
void renderRaquette2(game *myGame,coordonnees *dep2) {

        SDL_Rect rectangle2;

        SDL_SetRenderDrawColor(myGame->g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

        rectangle2.x=SCREEN_WIDTH-11;//debut x
        rectangle2.y=0;//debut y
        rectangle2.w=11; //Largeur
        rectangle2.h=SCREEN_HEIGHT; //Hauteur

        SDL_RenderFillRect(myGame->g_pRenderer,&rectangle2);

        SDL_SetRenderDrawColor(myGame->g_pRenderer,255,0,0,255);

        rectangle2.x=dep2->x;//debut x
        rectangle2.y=dep2->y;//debut y
        rectangle2.w=dep2->w; //Largeur
        rectangle2.h=dep2->h; //Hauteur

        SDL_RenderFillRect(myGame->g_pRenderer,&rectangle2);

        //SDL_RenderPresent(myGame->g_pRenderer);


}
