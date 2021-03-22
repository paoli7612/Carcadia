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
    std::string title;
    int width, height;
    tile_t **tiles;
};

void map_addfile(const std::string);

void map_init(map_t &, const std::string, const int, const int);
void map_print(const map_t &);

void map_add(map_t &, const int, const int, const image_t);
void map_remove(map_t &, const int, const int);

void map_save(const map_t &);
void map_load(map_t &, const std::string);

bool image_equals(const image_t, const image_t);
bool isSolid(const map_t &, const int, const int);

void map_setSolid(map_t &, const bool, const int, const int);