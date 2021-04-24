#include <iostream>

#include "../include/map.h"

   /*
    *   Prende una mappa gia salvata e la stampa
    * 
    */

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "use [make map_editor MAP=\"spawn\"]" << std::endl;
        return 1;
    }

    map_t map;
    map_load(map, argv[1]);
    map_print(map);

    return 0;
}
