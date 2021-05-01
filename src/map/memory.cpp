#include "../../include/map.h"

void map_allocate_tiles(map_t &map, const int width, const int height)
{
    // alloca la memoria per tutte le tile della mappa
    map.tiles = new tile_t*[height];
    for (int y=0; y<height; y++)
        map.tiles[y] = new tile_t[width];
}

void map_allocate_doors(map_t &map, const int n_doors)
{
    map.doors = new door_t[n_doors];
}