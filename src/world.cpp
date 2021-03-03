#include <iostream>
#include <cstring>

#include "../include/world.h"

using namespace std;

World::World()
{
    load("spawn");
}

void World::create(const string name)
{
    map_init(map);
    map_save(map, name);
}

tile_t World::get(const int x, const int y)
{
    return map.tiles[y][x];
}

void World::set(const int x, const int y, const int z, const int cx, const int cy)
{
    map_change(map, x, y, z, cx, cy);
}

void World::save(const std::string name)
{
    map_save(map, name);
}

void World::load(const string name)
{
    map_load(map, name);
}

void World::print()
{
    map_print(map);
}