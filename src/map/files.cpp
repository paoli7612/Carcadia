#include "../../include/map.h"


void map_load(map_t &map, const char title[10])
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::ifstream file(filename);

    if (! file)
        throw "Errore nella apertura della mappa " + filename;

    // char title[10];
    file.read((char*)&map.title, sizeof(char[10]));

    // int width, height;
    file.read((char*)&map.width, sizeof(int));
    file.read((char*)&map.height, sizeof(int));

    map_allocate_tiles(map, map.width, map.height);

    // tile_t **tiles;
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.read((char*)&map.tiles[y][x], sizeof(tile_t));
    
    // int n_doors;
    file.read((char*)&map.n_doors, sizeof(int));

    map_allocate_doors(map, map.n_doors);

    // door_t *doors;
    for (int i=0; i<map.n_doors; i++)
        file.read((char*)&map.doors[i], sizeof(door_t));


    file.close();
}

void map_reload(map_t &map, const char title[10])
{
    
    delete[] map.doors;
    for (int y=0; y<map.height; y++)
        delete[] map.tiles[y];
    try
    {
        map_load(map, title);
    }
    catch(const std::exception& e)
    {
        std::cout << title << " ] inseistente";
    }
    
    
}

void map_save(const map_t &map)
{
    std::string filename = "maps/" + (std::string)map.title + ".tomaoli";
    std::ofstream file(filename);

    if (! file)
        throw "Errore nella apertura della mappa " + filename;

    // char title[10];
    file.write((char*)&map.title, sizeof(char[10]));

    // int width, height;
    file.write((char*)&map.width, sizeof(int));
    file.write((char*)&map.height, sizeof(int));

    // tile_t **tiles;
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.write((char*)&map.tiles[y][x], sizeof(tile_t));
    
    // int n_doors;
    file.write((char*)&map.n_doors, sizeof(int));

    // door_t *doors;
    for (int i=0; i<map.n_doors; i++)
        file.write((char*)&map.doors[i], sizeof(door_t));
        
    file.close();
}

void map_delete(const char title[10])
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::remove(filename.c_str());
}
