#include <iostream>

#include "../include/map.h"

   /*
    *   Prende una mappa gia salvata, imposta
    *   alcune celle con delle immagini
    * 
    */

int main(int argc, char const *argv[])
{
    map_t map;

    map_load(map, "spawn");

    map_add_image(map, 3, 4, {0, 0});
    map_add_image(map, 2, 4, {0, 0});

    map_save(map);

    return 0;
}
