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

    // QUI

    map_save(map);

    return 0;
}
