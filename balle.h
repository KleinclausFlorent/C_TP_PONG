#ifndef BALLE_H_INCLUDED
#define BALLE_H_INCLUDED
#include "SdlFont.h"
#include "raquettes.h"

void renderBalle(game *myGame,balle *bal1);
void jeu(game *myGame, balle *bal1,coordonnees *dep,coordonnees *dep2,int *scoreJ1,int *scoreJ2,EtatPause *Pboo);


#endif // BALLE_H_INCLUDED
