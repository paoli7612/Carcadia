#include <iostream>
#include <cstring>
#include "../include/map.h"

using namespace std;


void set(image_t images[], const int ix, const int iy, kind_t kind, int i)
{
    images[i].ix = ix;
    images[i].iy = iy;
    images[i].kind = kind;
}

int main(int argc, char **argv)
{
    string name;

    if (argc != 2)
    {
        cout << "Inserisci il nome: ";
        cin >> name;
    }
    else 
        name = argv[1];

    map_t map;


    map_init(map, name);
    
    image_t images[5];

    set(images, 0, 11, TERRAIN, 0);
    set(images, 0, 11, TERRAIN, 1);
    set(images, 1, 11, TERRAIN, 2);
    set(images, 2, 11, TERRAIN, 3);
    set(images, 3, 11, TERRAIN, 4);
    set(images, 4, 11, TERRAIN, 5);


    map_fill_random(map, images, 5, 0);

    map_save(map, name);

    return 0;
}