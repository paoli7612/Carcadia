
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

void map_save(const map_t &map)
{
    std::string filename = "maps/" + map.title + ".tomaoli";
    std::ofstream file(map.title);

    file.write((char*)&map, sizeof(map_t));

    file.close();
}

void map_load(map_t &map, const std::string title)
{
    std::string filename = "maps/" + title + ".tomaoli";
    std::ifstream file(title);

    file.read((char*)&map, sizeof(map_t));

    file.close();
}