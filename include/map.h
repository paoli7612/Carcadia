#include <iostream>
#include <fstream>

#define TILE 32

const int DEPTH = 3;

struct image_t {
    int ix, iy;
};
const image_t EMPTY = {-1, -1};

struct tile_t {
    bool isSolid;
    image_t image[DEPTH];
};

struct map_t {
    char title[10];
    int width, height;
    tile_t **tiles;
};
