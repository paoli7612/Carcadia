#include <iostream>

#include "classes/map.h"

using namespace std;

int main(int argc, char **argv)
{

  map_t map;
  map_init(map);
  map_save(map, "maps/spawn.dat");

  return 0;
}
