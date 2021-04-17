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

bool is_empty(const image_t);

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

bool in_map(const map_t &map, const int x, const int y);

void map_init(map_t &map, const char title[10], const int width, const int height);

void map_load(map_t &map, const char title[10]);
void map_save(const map_t &map);

void map_add_door(map_t & map, const door_t door);
void map_add_door(map_t & map,
                const image_t image, // image of door
                const int x, // x
                const int y, // y ... poition door in map
                const char dest[10], // destination map title
                const int dx,   // dx
                const int dy);  // dy ... position in dest

void map_add_image(map_t &map, const int x, const int y, const image_t image);


#endif /* INCLUDE_MAP_H_ */

