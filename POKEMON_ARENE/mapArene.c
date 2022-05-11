#include <allegro.h>
#include <stdlib.h>


///Ce sous programme load (ouvre avec message d'erreur) et affiche à l'écran la map.



void mapArene()
{   //On charge la map
    BITMAP* map;
    map = load_bitmap("MapPokemon.bmp",NULL);
    if (!map)
    {
        allegro_message("La map n'a pas pu s'ouvrir");
        exit(EXIT_FAILURE);
    }
    //On charge la map avec les obstacles en rouge
    BITMAP*mapAvecObstacles;
    mapAvecObstacles = load_bitmap("mapAvecObstacles.bmp",NULL);

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
