#include <iostream>
#include <fstream>

#define TILE 32

const int WIDTH = 40, HEIGHT = 25, DEPTH = 3;

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
    tile_t tiles[HEIGHT][WIDTH];
};

void map_print(const map_t &);
void map_init(map_t &, const std::string);
void map_save(const map_t &);
void map_load(map_t &, const std::string);

bool image_equals(const image_t, const image_t);

void map_add(map_t &, const int, const int, const image_t);
void map_remove(map_t &, const int, const int);

bool isSolid(const map_t &, const int, const int);