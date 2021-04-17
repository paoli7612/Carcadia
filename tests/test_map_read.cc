#include <iostream>

#include "../include/map.h"

using namespace std;

   /*
    *   Prende una mappa gia salvata
    *   e la legge e stampa alcuni dei suoi dati
    * 
    */

int main(int argc, char const *argv[])
{
    map_t map;

    map_load(map, "spawn");

    cout << map.title << endl;

    cout << "(" << map.width << " x " << map.height << ")" << endl;

    cout << map.tiles[4][3].images[0].x << endl;

    return 0;
}
