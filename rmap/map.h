#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

#include <iostream>
#include <fstream>

const int DEPTH = 3;

typedef char title_t[10];

struct dimension_t {
    int width, height;
};

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

    title_t dest;
    pos_t d_pos;
};

struct map_t {

    title_t title;

    int width, height;
    tile_t **tiles;

    int n_doors;
    door_t *doors;

};

void map_print(const map_t &map);

void map_init(map_t &map, const title_t title, const dimension_t dimension);

void map_save(const map_t &map);
void map_load(map_t &map, title_t title);

#endif /* INCLUDE_MAP_H_ */
