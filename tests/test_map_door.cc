#include <iostream>

#include "../include/map.h"

   /*
    *   Prende una mappa gia salvata, aggiunge una
    *   porta verso una seconda mappa e salva su file.
    * 
    */

int main(int argc, char const *argv[])
{
    map_t map;

    map_load(map, "spawn");

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
