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
        "\t2. edit door...\n"
        "\t3. delete door...\n";

    bool runnning = true;
    while (runnning)
    {
        map_print(map);
        cout << menu << endl;
        int scelta;
        cout << "-> ";
        cin >> scelta;

    }
    


    

    return 0;
}
