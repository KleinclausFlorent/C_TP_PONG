#include "SdlFont.h"
//Initialisation gestion de la fenêtre et de la font

//BUT : initialisation de la fenetre des raquettes de la balle et de la fonts
//ENTREE : bal, raquettes , fenetre , font
//SORTIE : tout est initialisé
int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame, font *mFont,coordonnees *dep, coordonnees *dep2, balle *bal1){


    //initialize SDL
    dep->x=0;
    dep->y=0;
    dep->w=10;
    dep->h=100;
    dep2->x=SCREEN_WIDTH-10;
    dep2->y=0;
    dep2->w=10;
    dep2->h=100;
    bal1->r=10;
    bal1->x=SCREEN_WIDTH/2;
    bal1->y=SCREEN_HEIGHT/2;
    bal1->d=1;
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            //if succeeded create our window
            myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,height,width,flags);
            //if succeeded create window, create our render
            if(myGame->g_pWindow!=NULL){
                myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_ACCELERATED);


            }


    }else{


        return 0;
    }

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    mFont->g_font=TTF_OpenFont("./assets/fonts/arial_narrow_7/arial_narrow_7.ttf",65);




    return 1;


}
//Gestion de l'affiche du texte
//BUT : affichage du score
//ENTREE : la fenêtre myGame et les scores
//SORTIE : Score afficher dans la page
void writeSDL(game *myGame,font mFont,int scoreJ1, int scoreJ2) {

        SDL_Color fontColor={255,0,0};
        char buffer[50];
        int affichage=sprintf(buffer," %d : %d",scoreJ1,scoreJ2);
        myGame->g_psurface=TTF_RenderText_Blended(mFont.g_font, buffer, fontColor);//Charge la police

        if(myGame->g_psurface){


                //Définition du rectangle dest pour blitter la chaine
                SDL_Rect rectangle;
                rectangle.x=SCREEN_WIDTH/2-40;//debut x
                rectangle.y=0;//debut y
                rectangle.w=80; //Largeur
                rectangle.h=80; //Hauteur


                 myGame->g_ptexture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_psurface); // Préparation de la texture pour la chaine
                 SDL_FreeSurface(myGame->g_psurface); // Libération de la ressource occupée par le sprite

                 if(myGame->g_ptexture){

                        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_ptexture,NULL,&rectangle); // Copie du sprite grâce au SDL_Renderer
                        //SDL_RenderPresent(myGame->g_pRenderer); // Affichage
                 }
                 else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de creation surface pour chaine (%s)\n",SDL_GetError());
        }

}
//Gestion du delay
//BUT : imposer un delay pour le rafraichissement (PAS FONCTIONNEL)
//ENTREE : notre limit de rafraichissement
//SORTIE : vitesse régulée
void delay(unsigned int frameLimit){
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}


//BUT : Gestion de la destruction de la fenetre
//ENTREE : la fenêtre myGame et la font
//SORTIE : fermeture de la fenetre
void destroy(game *myGame,font *mFont){


    if(mFont->g_font!=NULL){
        TTF_CloseFont(mFont->g_font); /* Doit être avant TTF_Quit() */
        mFont->g_font=NULL;
    }

    //Destroy texture
    if(myGame->g_ptexture!=NULL)
            SDL_DestroyTexture(myGame->g_ptexture);


    //Destroy render
    if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);


    //Destroy window
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}
