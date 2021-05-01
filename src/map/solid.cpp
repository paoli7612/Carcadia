#include "../../include/map.h"



void map_set_solid(map_t &map, const int x, const int y, const bool col=true)
{
    if (! in_map(map, x, y))
        return;

    map.tiles[y][x].isCollide = col;
}

bool map_is_solid(const map_t &map, const int x, const int y)
{
    if (! in_map(map, x, y))
        return true;
    
    return map.tiles[y][x].isCollide;
}
