#include <iostream>
#include <fstream>
#include <cstring>

#include "errors.h"

#include "map.h"

void map_print(const map_t &map)
{
    for (int y=0; y<HEIGHT; y++)
    {
        for (int x=0; x<WIDTH; x++)
            std::cout << map.tiles[y][x].code << "\t";
        std::cout << "\n";
    }
}

void map_load(map_t &map, const std::string &filename)
{
    std::ifstream file(filename);

    if (! file)
        throw errors::FILE_OPEN_READ;

    file.read((char*)&map, sizeof(map_t));

    file.close();
}

void map_save(const map_t &map, const std::string &filename)
{
    std::ofstream file(filename);

    if (! file)
        throw errors::FILE_OPEN_WRITE;

    file.write((char*)&map, sizeof(map_t));

    file.close();
}

void map_init(map_t &map)
{
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
            map.tiles[y][x].code = EMPTY;
}