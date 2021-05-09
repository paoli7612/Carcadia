#include <iostream>

using namespace std;

#include "map.h"

int main(int argc, char const *argv[])
{

    map_t map;

    map_init(map, "prima", {20, 20});

    try
    {
        map_save(map);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
