#include <allegro.h>
#include <stdlib.h>
#define TXTUILE    32    // Largeur des tuiles
#define TYTUILE    32   // Hauteur des tuiles

#define NXMAP      31     // Nombre de tuiles en largeur sur le terrain
#define NYMAP      25
#include "ssprog.h"




int main()
{
    t_acteur *acteur;    // Un acteur (à créer)
    BITMAP *page;
    BITMAP *map;


    initAlleg();

    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);

    map = load_bitmap_check("pokemap.bmp");

    acteur = (t_acteur *)malloc(1*sizeof(t_acteur));

    // Pour la position : multiples de l'unité de déplacement...
    acteur->x = 64;
    acteur->y = 96;
    acteur->img = load_bitmap_check("sprite.bmp");





    while(!key[KEY_ESC])
    {
        blit(map,page,0,0,(SCREEN_W-map->w)/2, (SCREEN_H-map->h)/2, map->w, map->h);
        if (    key[KEY_RIGHT] && !typeTerrain(acteur,4,0,1) )
            acteur->x+=4;

        if (    key[KEY_LEFT] && !typeTerrain(acteur,-4,0,1) )
            acteur->x-=4;

        if (    key[KEY_DOWN] && !typeTerrain(acteur,0,4,1) )
            acteur->y+=4;

        if (    key[KEY_UP] && !typeTerrain(acteur,0,-4,1) )
            acteur->y-=4;

        draw_sprite(page, acteur->img, acteur->x - acteur->img->w/2, acteur->y - acteur->img->h + 8);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        // on fait une petite pause
        rest(15);



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
