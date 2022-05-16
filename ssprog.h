#ifndef SSPROG_H_INCLUDED
#define SSPROG_H_INCLUDED



void initAlleg();

void mapArene();

typedef struct acteur
{
    int x, y;          // coordonnées (en pixels) des pieds de l'acteur
    BITMAP *img;       // image de l'acteur
} t_acteur;

BITMAP * load_bitmap_check();

int typesTuiles();

int typeTerrain();

int Mterrain();



#endif // SSPROG_H_INCLUDED
