#include <iostream>
#include <cstring>

const int WIDTH = 40, HEIGHT = 25;
const int TILE = 32;
const int EMPTY = 7612;

typedef uint16_t code_t;

struct tile_t {
    code_t code;
};

struct map_t {
    tile_t tiles[WIDTH][HEIGHT];
};

void map_print(const map_t &);
void map_load(map_t &, const std::string &);
void map_save(const map_t &, const std::string &);
void map_init(map_t &);