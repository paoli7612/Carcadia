
#include "../include/map.h"

void map_init(map_t &map, const std::string title="title")
{
    
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
        {
            for (int z=0; z<DEPTH; z++)
                map.tiles[y][x].image[z] = EMPTY;
            map.tiles[y][x].isSolid = false;
        }
}

void map_load(map_t &map, const std::string &name)
{
    std::string filename = "maps/" + name + ".dat";

    std::ifstream file(filename);

    if (! file)
        throw "Errore lettura mappa: " + filename;
    
    file.read((char *)&map, sizeof(map));

    file.close();    
}

void map_save(const map_t &map, const std::string &name)
{
    std::string filename = "maps/" + name + ".dat";

    std::ofstream file(filename);

    if (! file)
        throw "Errore scrittura mappa: " + filename;
    
    file.write((char *)&map, sizeof(map));

    file.close();    
}
