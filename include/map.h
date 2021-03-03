#include <iostream>
#include <cstring>

const int WIDTH = 40, HEIGHT = 25, DEPTH = 2;
const int TILE = 32;

struct image_t {
    unsigned short int x, y;
};

struct tile_t {
    image_t image[DEPTH];
};

struct map_t {
    tile_t tiles[HEIGHT][WIDTH];
};

const image_t EMPTY = {5, 5};

void map_print(map_t &);
void map_load(map_t &, const std::string &);
void map_save(const map_t &, const std::string &);
void map_init(map_t &);

void map_change(map_t &, const int, const int, const int, const int, const int);
