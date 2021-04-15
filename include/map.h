#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

#include <iostream>
#include <fstream>
#include <cstring>

const int DEPTH = 3;

struct image_t
{
    short int x, y;
};

struct tile_t
{
    image_t images[DEPTH];
    bool isCollide;
};

struct door_t {
    image_t image;
    int x, y;

    char dest[10];
    int dx, dy;
};

struct map_t 
{
    char title[10];

    int width, height;
    tile_t **tiles;

    int n_doors;
    door_t *doors;
};

void init(map_t &, const char title[10], const int width, const int height);

void print(const map_t &);

void load(map_t, char title[10]);
void save(map_t);

#endif /* INCLUDE_MAP_H_ */

