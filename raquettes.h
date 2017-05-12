//Création des raquettes et gestion des événements liées aux raquettes
#ifndef RAQUETTES_H_INCLUDED
#define RAQUETTES_H_INCLUDED
#include "SdlFont.h"


void handleEvents(gameState *state,EtatRaquette *boo1,EtatRaquette *boo2,EtatPause *Pboo);
void MouvementRaquette(coordonnees *dep,coordonnees *dep2,EtatRaquette *boo1,EtatRaquette *boo2);
void renderRaquette1(game *myGame,coordonnees *dep);
void renderRaquette2(game *myGame,coordonnees *dep2 );


#endif // RAQUETTES_H_INCLUDED
