#include <iostream>

#include "../include/map.h"

int main(int argc, char **argv)
{
    map_t map;

    map_init(map, "spawn");

    map_save(map);

    return 0;
}