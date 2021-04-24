#include <iostream>

#include "../include/map.h"

   /*
    *   Prende una mappa gia salvata e la stampa
    * 
    */

int main(int argc, char const *argv[])
{
    map_t map;

    map_load(map, "asd");

    map_print(map);

    return 0;
}
