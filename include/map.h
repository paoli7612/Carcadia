#include <iostream>
#include <cstring>

const int WIDTH = 40, HEIGHT = 25, DEPTH = 2;
const int TILE = 32;

struct code_t {
    unsigned short int x, y;
};

const code_t EMPTY = {7612, 7612};

struct tile_t {
    code_t image[DEPTH];
};

struct map_t {
    tile_t tiles[WIDTH][HEIGHT];
};

void map_load(map_t &, const std::string &);
void map_save(const map_t &, const std::string &);
void map_init(map_t &);
