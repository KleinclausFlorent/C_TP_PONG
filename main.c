#include "balle.h"
//D:\SDL2-2.0.5 chemin vers sdl
//D:\SDL2-2.0.5\SDL2_ttf-devel-2.0.14-mingw\SDL2_ttf-2.0.14 chemin vers sdl ttf
int main(int argc, char *argv[])
{

     game myGame;
     gameState state;
     font mFont;

     coordonnees dep;
     coordonnees dep2;
     EtatRaquette boo1;
     EtatRaquette boo2;
     EtatPause Pboo=Pause;

     balle bal1;

     int choix=0;
     int scoreJ1=0;
     int scoreJ2=0;


     state.g_bRunning=1;

    //Pour les 60 fps
    unsigned int frameLimit = SDL_GetTicks() + 16;

    //Create texture for drawing in texture or load picture
    myGame.g_ptexture=SDL_CreateTexture(myGame.g_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SCREEN_WIDTH,SCREEN_HEIGHT);
    printf("Bienvenue dans mon Pong !\n");
    printf("Joueur gauche : Monter avec z. Descendre avec s .\n");
    printf("Joueur droite : Monter avec fleche du haut. Descendre avec fleche du bas .\n");
    printf("Appuyer sur espace pour l'engagement et/ou mettre le jeu en pause .\n");
    printf("Appuyer sur echap pour quitter la partie. \n");
    while(state.g_bRunning)
    {
        if(choix==0)
        {
            printf("1: Jouer !\n");
            scanf("%i",&choix);
        }
        switch (choix)
        {
            case 1:
                init("Chapter 1 setting up SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame,&mFont,&dep,&dep2,&bal1);
                while(state.g_bRunning)
                {

                    handleEvents(&state,&boo1,&boo2,&Pboo);
                    renderRaquette1(&myGame,&dep);
                    renderRaquette2(&myGame,&dep2);
                    renderBalle(&myGame,&bal1);
                    if (Pboo==Jeu){
                        MouvementRaquette(&dep,&dep2,&boo1,&boo2);
                        jeu(&myGame,&bal1,&dep,&dep2,&scoreJ1,&scoreJ2,&Pboo);
                    }
                    writeSDL(&myGame,mFont,scoreJ1,scoreJ2);
                    SDL_RenderPresent(myGame.g_pRenderer);
                    delay(frameLimit);
                }

                 break;

        }

         destroy(&myGame,&mFont);

         TTF_Quit();
         SDL_Quit();
    }





  return 0;
}
















