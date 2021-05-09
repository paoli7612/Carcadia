#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

#include <iostream>
#include <fstream>

struct tile_t {

};

struct door_t {

};

struct map_t {

    char title[10];

    int width, height;
    tile_t **tiles;

    int n_doors;
    door_t *doors;

};

void map_print(const map_t &map);

#endif /* INCLUDE_MAP_H_ */
