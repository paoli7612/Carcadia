#include <iostream>

#include "../include/map.h"

int main(int argc, char const *argv[])
{
    map_t map;
    std::string title;
    if (argc != 2)
    {
        std::cerr << "Inserisci il nome della mappa da creare come primo argomento" << std::endl;
        return 1;
    }

    std::cout << "Inserisci le dimensioni (w-h): ";
    int w, h;
    std::cin >> w >> h;

    map_init(map, argv[1], w, h);
    map_save(map);

    return 0;
}
