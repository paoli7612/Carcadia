#include "../include/map.h"

image_t EMPTY_IMAGE = {-1, -1};


void map_init(map_t &map, const char title[10], const int width, const int height)
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

void map_load(map_t &map, char title[10])
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::ifstream file(filename);

    if (! file)
        throw "Errore nella apertura della mappa " + filename;

    char t[10];
    int w, h;

    // char title[10];
    file.read((char*)&t, sizeof(char[10]));

    // int width, height;
    file.read((char*)&w, sizeof(int));
    file.read((char*)&h, sizeof(int));

    map_init(map, t, w, h);

    // tile_t **tiles;
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.read((char*)&map.tiles[y][x], sizeof(tile_t));
    
    // int n_doors;
    file.read((char*)&map.n_doors, sizeof(int));

    // door_t *doors;
    file.read((char*)&map.doors, sizeof(door_t[map.n_doors]));
        
    file.close();
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
    file.write((char*)&map.doors, sizeof(door_t[map.n_doors]));
        
    file.close();
}