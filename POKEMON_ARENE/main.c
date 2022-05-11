#include <allegro.h>
#include <stdlib.h>
#include "ssprog.h"




int main()
{


    initAlleg();

    while(!key[KEY_ESC])
    {
            mapArene();

    }





    allegro_exit();


    return 0;

}
END_OF_MAIN();


































///Ancien programme inutile mais je le garde au cas où

/*
BITMAP*fondPoke;
    //BITMAP*lancerP;
    //lancerP = load_bitmap("LancerPartie.bmp",NULL);
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




    //Affichage du fond du menu "Pokemon"
    blit(fondPoke,screen,0,0, (SCREEN_W-fondPoke->w)/2, (SCREEN_H-fondPoke->h)/2, fondPoke->w, fondPoke->h);
   //    masked_blit (lancerP,screen,365,485,585,550,lancerP->w,lancerP->h);

    //Affichage du "lancer partie"
    rectfill(screen,365,485,585,550,makecol(0,0,0));
    rectfill(screen,368,488,582,547,makecol(255,255,255));
    textprintf_ex(screen,font,400,516,makecol(0,0,0),-1,"LANCER UNE PARTIE");
    //                          x   y

        while(!key[KEY_ESC])
        {
        if(mouse_b & 1)
        {   if(mouse_x>364 && mouse_x<486 && mouse_y>586 && mouse_y<551)
            {
                   rectfill(fondPoke,365,605,585,550,makecol(255,0,0));
            }
        }
        }

*/
