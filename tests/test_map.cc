#include <iostream>

#include "../include/map.h"

int main(int argc, char const *argv[])
{
    map_t map;

    map_init(map, "spawn", 30, 20);

    map_save(map);

    return 0;
}
