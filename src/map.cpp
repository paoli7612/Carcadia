#include "../include/map.h"

void init(map_t &map, const char title[10], const int width, const int height)
{
    strcpy(map.title, title);

    map.width = width;
    map.height = height;

    map.n_doors = 0;

    map.tiles = new tile_t*[height];
    for (int y=0; y<height; y++)
        map.tiles[y] = new tile_t[width];
    
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
        { // per ogni tile della matrice
            tile_t &tile = map.tiles[y][x];
            for (int z=0; z<DEPTH; z++)
                tile.images[z] = EMPTY_IMAGE;
            tile.isCollide = false;    
        }
}

void load(map_t, char[10])
{

}
void save(map_t)
{

}