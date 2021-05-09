#include <iostream>

using namespace std;

#include "map.h"

int main(int argc, char const *argv[])
{

    map_t map;

    map_init(map, "prima", {20, 20});

    map_save(map);

    return 0;
}
