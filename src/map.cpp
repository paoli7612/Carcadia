#include "../include/map.h"

#include "map/door.cpp"
#include "map/files.cpp"
#include "map/image.cpp"
#include "map/solid.cpp"
#include "map/memory.cpp"

bool map_in(const map_t &map, const int x, const int y)
{
    return !(x < 0 || y < 0 || x >= map.width || y >= map.height);
}

void map_init(map_t &map, const char title[10], const int width, const int height)
{
    strcpy(map.title, title);

    map.width = width;
    map.height = height;
    map.n_doors = 0;

    map_allocate_tiles(map, width, height);
    
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
        {
            tile_t &tile = map.tiles[y][x];
            for (int z=0; z<DEPTH; z++)
                tile.images[z] = EMPTY_IMAGE;
            tile.isCollide = false;    
        }
}

void map_print(const map_t &map)
{
    std::cout << map.title << std::endl;
    std::cout << "\t[size] " << map.width << " x " << map.height << std::endl;
    std::cout << "\t[#doors]" << map.n_doors << std::endl;
    for (int i=0; i<map.n_doors; i++)
    {
        std::cout <<"\t" << i << "] {";
        door_t &d = map.doors[i];
        std::cout << "\t[pos] (" << d.x << " x " << d.y << ")\n";
        std::cout << "\t\t[dest] " << d.dest << " (" << d.dx << " x " << d.dy << ")\n";
        std::cout << "\t\t[image] " << d.image.x << " x " << d.image.y;
        std::cout <<"\t}" << std::endl << std::endl;
    }
}
