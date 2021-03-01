#include <iostream>
#include <cstring>

#include "world.h"

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

void World::clear()
{
    
}