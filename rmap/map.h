#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

#include <iostream>
#include <fstream>

const int DEPTH = 3;

struct image_t {
    int ix, iy;
};

struct pos_t {
    int x, y;
};

struct tile_t {
    image_t image[DEPTH];
    bool is_collide;
};

struct door_t {
    image_t image;
    pos_t pos;
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
