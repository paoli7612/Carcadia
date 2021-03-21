#include <iostream>

#include "../include/map.h"

using namespace std;

int main(int argc, char **argv)
{
    map_t map;
    int x, y;
    string title;

    cout << "Inserisci le dimensioni della mappa(x, y): ";
    cin >> x >> y;

    cout << "Inserisci il titolo della mappa: ";
    cin >> title;

    map_init(map, title, x, y);

    map_save(map);
    map_print(map);

    return 0;
}