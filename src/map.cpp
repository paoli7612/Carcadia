
#include "../include/map.h"

void map_init(map_t &map)
{
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
        {
            tile_t &tile = map.tiles[y][x];
            tile.isSolid = false;
            for (int z=0; z<DEPTH; z++)
                tile.image[z] = EMPTY;
        }
}

void map_save(const map_t &);
void map_load(map_t &);