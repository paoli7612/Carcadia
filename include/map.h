#include <iostream>
#include <fstream>
#include <cstring>

const int WIDTH = 40, HEIGHT = 25, DEPTH = 3;
const int TILE = 32;

enum kind_t { TERRAIN, OUTSIDE, INTERIOR };

struct image_t {
    unsigned short int ix, iy;
    kind_t kind = TERRAIN;
};

struct tile_t {
    image_t image[DEPTH];
    bool isSolid;
};

struct map_t {
    std::string title;
    tile_t tiles[HEIGHT][WIDTH];
};

const image_t EMPTY = {7612, 7612, TERRAIN};

void map_init(map_t &, const std::string);

void map_load(map_t &, const std::string &);
void map_save(const map_t &, const std::string &);

/*
void map_change(map_t &, const int, const int, const int, const int, const int);
void map_fill(map_t &, const image_t &, const int z);
void map_clear(map_t &, const int, const int);
*/