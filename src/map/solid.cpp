#include "../../include/map.h"



void map_set_solid(map_t &map, const int x, const int y, const bool col=true)
{
    if (! map_in(map, x, y))
        return;

    map.tiles[y][x].isCollide = col;
}

bool map_is_solid(const map_t &map, const int x, const int y)
{
    if (! map_in(map, x, y))
        return true;
    
    return map.tiles[y][x].isCollide;
}
