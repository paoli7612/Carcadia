#include <iostream>

#include "../include/map.h"

int main(int argc, char const *argv[])
{
    std::string title;
    if (argc != 2)
    {
        std::cerr << "Inserisci il nome della mappa da creare come primo argomento" << std::endl;
        return 1;
    }

    map_delete(argv[1]);
    
    std::cout << "map deleted: " << argv[1] << std::endl;

    return 0;
}
