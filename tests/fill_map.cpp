#include <iostream>
#include <cstring>
#include "../include/map.h"

using namespace std;

int main(int argc, char **argv)
{
    string name;

    if (argc != 2)
    {
        cout << "Inseri il nome della mappa da creare: ";
        cin >> name;
    }
    else
    {
        name = argv[1];
    }

    image_t image;
    map_t map;

    cout << "Inserisci x y: ";
    cin >> image.x >> image.y;
    
    map_load(map, name);
    
    map_fill(map, image, 0);

    map_save(map, name);

    return 0;
}