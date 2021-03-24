#include <iostream>

#include "../include/map.h"

using namespace std;

int main(int argc, char **argv)
{
    string title;
    if (argc != 2)
    {
        cout << "Inserisci il nome della mappa: ";
        cin >> title;
    }
    else {
        title = argv[1];
    }

    map_t map;
    map_init(map, title, 10, 10);

    map_print(map);

    char r;
    cout << "Save? (y/n): ";
    cin >> r;
    cout << r << " " << (int)r << endl;
    if (r == 'y')
    {
        cout << "Salvataggio in corso...";
        map_save(map);
    }

    return 0;
}