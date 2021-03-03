#include <iostream>

#include "../include/map.h"

using namespace std;

const char menu[] =
    "\t1. save\n"
    "\t2. change (x, y, z, cx, cy)"
    "\n\t0. exit\n"
    "-> ";

int main(int argc, char **argv)
{
    map_t map;

    bool run = true;

    string name;
    cout << "Insrisci il nome della mappa: ";
    cin >> name;

    map_load(map, name);

    while (run)
    {
        map_print(map);

        int choice;
        
        cout << menu;
        cin >> choice;

        switch (choice)
        {
            int x, y, z, cx, cy;
        case 1:
            map_save(map, name);
            break;
        case 2:
        {
            cin >> x >> y >> z >> cx >> cy;
            map_change(map, x, y, z, cx, cy);
            break;
        }
        case 0:
            run = false;
        default:
            break;
        }
    } 
    cout << "close program" << endl;
    return 0;
}