#include <allegro.h>
#include <stdlib.h>


void afficherMenu()
{
    BITMAP*fondPoke;
    BITMAP*lancerP;
    lancerP = load_bitmap("LancerPartie.bmp",NULL);
    if(!lancerP)
    {
        allegro_message("pas pu trouver/charger LancerPartie.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    fondPoke = load_bitmap("AffichagePoke2.bmp",NULL);
    if(!fondPoke)
    {
        allegro_message("pas pu trouver/charger AffichagePoke2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

}
