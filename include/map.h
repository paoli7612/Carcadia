#include <iostream>
#include <fstream>

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
    std::string title;
    tile_t tiles[HEIGHT][WIDTH];
};

void map_init(map_t &);
void map_save(const map_t &);
void map_load(map_t &, const std::string);