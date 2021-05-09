#include "map.h"

void map_init(map_t &map, const title_t title, const dim_t dim)
{
    // title
    strcpy(map.title, title);

    // matrix
    map.dim = dim;

    map.tiles = new tile_t*[dim.height];
    for (int y=0; y<dim.height; y++)
        map.tiles[y] = new tile_t[dim.width];

    // doors
    map.n_doors = 0;
}

void map_load(map_t &map, title_t title)
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::ifstream file(filename);

    if (! file)
        throw "map not found";

    

    file.close();
}

void map_save(const map_t &map)
{
    std::string filename = "maps/" + (std::string)map.title + ".tomaoli";
    std::ofstream file(filename);

    if (! file)
        throw "map not found";

    file.write((char*)&map.dim, sizeof(dim_t));
    
    file.close();
}
