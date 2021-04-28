#include <iostream>

#include "../include/map.h"

   /*
    *   Prende una mappa gia salvata, stampa le sue porte
    *   e permette di cambiare i loro valori
    * 
    */

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "use [make map_editor MAP=\"spawn\"]" << std::endl;
        return 1;
    }

    map_t map;
    map_load(map, argv[1]);
    
    const char menu[] =
    "____MENU___\n"
        "\t1. add new door...\n"
        "\t3. delete door...\n"
        "\t4. save and exit\n";

    bool runnning = true;
    while (runnning)
    {
        map_print(map);
        cout << menu << endl;

        int choice;
        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
            case 1: // add
                {
                    door_t door;
                    cout << "dest: ";
                    cin >> door.dest;

                    cout << "x y: ";
                    cin >> door.x >> door.y;
                
                    cout << "image (x y): ";
                    cin >> door.image.x >> door.image.y;
                
                    cout << "dx dy: ";
                    cin >> door.dx >> door.dy;
                    map_add_door(map, door);
                }
                break;
            case 3: // delete
                {
                    int n;
                    cout << "n: ";
                    cin >> n;
                    
                }
                break;

            case 4: // save and exit
                map_save(map);
                runnning = false;
                break;
        }
    }


    return 0;
}
