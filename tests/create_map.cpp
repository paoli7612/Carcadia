#include <iostream>
#include <cstring>
#include "../include/map.h"

using namespace std;

int main()
{
    string name;
    cout << "Inseri il nome della mappa da creare: ";
    cin >> name;

    map_t map;

    map_init(map);
    map_save(map, name);

    return 0;
}