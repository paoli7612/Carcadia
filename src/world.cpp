#include <iostream>
#include <cstring>

#include "../include/world.h"

using namespace std;

World::World()
{
    load("spawn");
    load("home");
}

void World::load(const string name)
{
    string filename = "maps/" + name + ".dat";
    
    map_load(map, filename);
}

void World::create(const string name)
{
    string filename = "maps/" + name + ".dat";

    map_init(map);
    map_save(map, filename);
}

tile_t World::get(const int x, const int y)
{
    return map.tiles[y][x];
}

void World::set(const int x, const int y, const code_t code)
{
    map.tiles[y][x].code = code;
}

void World::save()
{
    map_save(map, "maps/spawn.dat");
}