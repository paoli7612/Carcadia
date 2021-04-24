#include <iostream>

#include "../include/map.h"

   /*
    *   Crea una nuova mappa a determinate dimensioni
    *   
    */

int main(int argc, char const *argv[])
{
    map_t map;

    map_init(map, "asd", 20, 15);

    door_t door {
        {2, 2}, //image
        5, 5, // pos
        "paswn", // dest
        10, 10 // dest pos
    };
    map_add_door(map, door);

    map_save(map);

    return 0;
}
