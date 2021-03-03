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


    map_t map;

    map_init(map);
    map_save(map, name);

    return 0;
}