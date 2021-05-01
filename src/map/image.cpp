#include "../../include/map.h"

image_t EMPTY_IMAGE = {-1, -1};


int top(const image_t image[DEPTH])
{
    // profondità della prima immagine vuota a partire dal basso
    // se sono tutte "occupate" ritorna DEPTH
    int i=0;
    for (; i<DEPTH && (!is_empty(image[i])); i++) ;
    return i;
}

void tile_down(tile_t &tile)
{
    // sposta tutte le immagini verso il basso
    // la prima immagine viene persa
    for (int i=0; i<DEPTH-1; i++)
        tile.images[i] = tile.images[i+1];
    tile.images[DEPTH-1] = EMPTY_IMAGE;
}


void map_add_image(map_t &map, const int x, const int y, const image_t image)
{
    if (!in_map(map, x, y))
        return;
    
    tile_t &tile = map.tiles[y][x];

    // parte dalla prima immagine della tile e sale finche non trova una immagine vuota
    int z = top(tile.images);

    if (z > 0 && equals(tile.images[z-1], image)) // ultima immagine inserita uguale
        return;

    if (z == DEPTH) // cella piena di immagini
    {
        tile_down(tile);
        z--;
    }

    tile.images[z] = image;
}

void map_rem_image(map_t &map, const int x, const int y)
{
    if (!in_map(map, x, y))
        return;

    tile_t &tile = map.tiles[y][x];

    int z = top(tile.images);

    if (z)
        tile.images[z-1] = EMPTY_IMAGE;
}
