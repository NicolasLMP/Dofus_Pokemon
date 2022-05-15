#include <allegro.h>
#include <stdlib.h>
#define TXTUILE    32    // Largeur des tuiles
#define TYTUILE    32   // Hauteur des tuiles

#define NXMAP      31     // Nombre de tuiles en largeur sur le terrain
#define NYMAP      25
#define NTUILES 775

typedef struct acteur
{
    int x, y;          // coordonnées (en pixels) des pieds de l'acteur
    BITMAP *img;       // image de l'acteur
} t_acteur;

/*void mapArene()
{   //On charge la map
    BITMAP* map;
    map = load_bitmap("pokemap.bmp",NULL);
    if (!map)
    {
        allegro_message("La map n'a pas pu s'ouvrir");
        exit(EXIT_FAILURE);
    }
    //On charge la map avec les obstacles en rouge
    BITMAP*mapAvecObstacles;
    mapAvecObstacles = load_bitmap("pokemapQuadri.bmp",NULL);

    if(!mapAvecObstacles)
    {
        allegro_message("La map avec les obstacles n'a pas pu s'ouvrir");
        exit(EXIT_FAILURE);
    }

     //affiche la map classique
    blit(map,screen,0,0,(SCREEN_W-map->w)/2, (SCREEN_H-map->h)/2, map->w, map->h);

    if(key[KEY_SPACE])
    {   //affiche la map avec les obstacles
        blit(mapAvecObstacles,screen,0,0,(SCREEN_W-mapAvecObstacles->w)/2, (SCREEN_H-mapAvecObstacles->h)/2, mapAvecObstacles->w, mapAvecObstacles->h);
    }



}
*/


int typesTuiles[NTUILES]={
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,
    1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,2,2,2,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,2,2,1,2,2,2,2,2,1,1,2,2,2,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2,0,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,1,1,
};


int typeTerrain(t_acteur *acteur, int dx, int dy, int type){

    int decx,decy;        // Pour visiter les coins...
    int cx,cy;            // Coordonnées des coins (en pixels)

    // Pour chacun des 4 coins...
    for (decy=-TYTUILE/2; decy<TYTUILE/2; decy+=TYTUILE-1)
        for (decx=-TXTUILE/2; decx<TXTUILE/2; decx+=TXTUILE-1)
        {
            // Coord. du coin
            cx=acteur->x+dx+decx;
            cy=acteur->y+dy+decy;

            // Si on sort du terrain...
            if (cx<0 || cx>=NXMAP*TXTUILE || cy<0 || cy>=NYMAP*TYTUILE)
            {
                if (type==1)  return 1;  // Oui c'est un obstacle
                else  return 0;          // Non ce n'est pas autre chose...
            }
            ///En gros ici on doit avoir ituile = le numero de la case ou se trouve le perso dans le  tableau d'arthur 
            ///Par exmple si le perso se trouve en haut à droite (on a px = 992 et py = 0) de la map on doit avoir ituile = 30 (pas 31 car 0 compte).
            
            
            
               if (typeTuiles[ituile]==type)
                return 1;

        }


    return 0;
}

