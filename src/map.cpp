#include <iostream>
#include <fstream>
#include <cstring>

#include "../include/map.h"

void map_print(map_t &map)
{
    for (int z=0; z<DEPTH; z++){
        for (int y=0; y<HEIGHT; y++){
            for (int x=0; x<WIDTH; x++)
                std::cout << map.tiles[y][x].image[z].x << " - " << map.tiles[y][x].image[z].y << "\t";
            std::cout << std::endl;
        }
    std::cout << std::endl << std::endl;
    }
}

void map_load(map_t &map, const std::string &name)
{
    std::string filename = "maps/" + name + ".dat";
    std::ifstream file(filename);

    std::cout << "Load: " << filename << std::endl;

    if (! file)
        throw "Errore lettura file mappa: " + name;

    file.read((char*)&map, sizeof(map_t));

    file.close();
}

void map_save(const map_t &map, const std::string &name)
{
    std::string filename = "maps/" + name + ".dat";
    std::ofstream file(filename);

    std::cout << "Save: " << filename << std::endl;

    if (! file)
        throw "Errore scrittura file mappa: " + name;

    file.write((char*)&map, sizeof(map_t));

    file.close();
}

void map_init(map_t &map)
{
    for (int z=0; z<DEPTH; z++)
        map_fill(map, EMPTY, z);
}

void map_change(map_t &map, const int x, const int y, const int z, const int cx, const int cy)
{
    map.tiles[y][x].image[z].x = cx;
    map.tiles[y][x].image[z].y = cy;
}

void map_fill(map_t &map, const image_t &image, const int z)
{
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
            map.tiles[y][x].image[z] = image;
}

void map_clear(map_t &map, const int x, const int y)
{
    for (int z=0; z<DEPTH; z++)
        map.tiles[y][x].image[z] = EMPTY;
}