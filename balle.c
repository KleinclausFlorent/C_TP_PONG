#include "balle.h"
//Gestion de la balle
//BUT : construction de la balle
//ENTREE : la fenêtre myGame et la balle
//SORTIE : Balle construite ( cercle)
void renderBalle(game *myGame,balle *bal1 ) {

        int i;
        SDL_Point Point1;

        SDL_Rect rectangle;
        SDL_SetRenderDrawColor(myGame->g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

        rectangle.x=11;//debut x
        rectangle.y=0;//debut y
        rectangle.w=SCREEN_WIDTH-22; //Largeur
        rectangle.h=SCREEN_HEIGHT; //Hauteur

        SDL_RenderFillRect(myGame->g_pRenderer,&rectangle);

        for (i=0; i<361 ;i++){
            Point1.x=bal1->x+bal1->r*cos(i);
            Point1.y=bal1->y+bal1->r*sin(i);
            SDL_SetRenderDrawColor(myGame->g_pRenderer,255,0,0,255);
            SDL_RenderDrawPoint(myGame->g_pRenderer,Point1.x,Point1.y);
        }


}
//Gestion de la balle
//BUT : Calcul position balle + collision, gestion du score
//ENTREE : la fenetre, la balle, les position des raquettes, les scores et l'enum pause
//SORTIE : la balle sa position, sa direction et le score

void jeu(game *myGame, balle *bal1,coordonnees *dep,coordonnees *dep2,int *scoreJ1,int *scoreJ2,EtatPause *Pboo){
    //HAUT gauche
    if (bal1->d==1){
        bal1->x=bal1->x-1;
        bal1->y=bal1->y-1;
    }
    //HAUT droite
    if (bal1->d==2){
        bal1->x=bal1->x+1;
        bal1->y=bal1->y-1;
    }
    //BAS droit
    if (bal1->d==3){
        bal1->x=bal1->x+1;
        bal1->y=bal1->y+1;
    }
    //BAS gauche
    if (bal1->d==4){
        bal1->x=bal1->x-1;
        bal1->y=bal1->y+1;
    }
    //Rebond ecran haut
    if (bal1->y<=bal1->r){
        if (bal1->d==1){
            bal1->d=4;
        } else if (bal1->d==2){
            bal1->d=3;
        }
    }
    //Rebond ecran bas
    if (bal1->y>=SCREEN_HEIGHT-bal1->r){
        if (bal1->d==3){
            bal1->d=2;
        } else if (bal1->d==4){
            bal1->d=1;
        }
    }
    //Rebond Raquette gauche
    if ((bal1->x<=dep->w)&&(bal1->y>=dep->y)&&(bal1->y<=dep->y+dep->h))
    {
        if (bal1->d==4){
            bal1->d=3;
        } else if (bal1->d==1){
            bal1->d=2;
        }
    }
    //Rebond Raquette droite
    if ((bal1->x>=SCREEN_WIDTH-dep2->w)&&(bal1->y>=dep2->y)&& (bal1->y<=dep2->y+dep2->h))
    {
        if (bal1->d==3){
            bal1->d=4;
        } else if (bal1->d==2){
            bal1->d=1;
        }
    }
    //But a gauche
    if (bal1->x<=1)
    {
        *scoreJ2=*scoreJ2+1;
        bal1->x=SCREEN_WIDTH/2;
        bal1->y=SCREEN_HEIGHT/2;
        bal1->d=2;
        *Pboo=Pause;
    }
    //But a droite
    if (bal1->x>=SCREEN_WIDTH-1)
    {
        *scoreJ1=*scoreJ1+1;
        bal1->x=SCREEN_WIDTH/2;
        bal1->y=SCREEN_HEIGHT/2;
        bal1->d=1;
        *Pboo=Pause;
    }

}
