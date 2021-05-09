#include <iostream>

using namespace std;

#include "map.h"

int main(int argc, char const *argv[])
{

    map_t map;

    map_init(map, "prima", {20, 20});
    map_save(map);


    map_t map2;
    map_load(map2, "prima");
    map_print(map2);
    

    return 0;
}
