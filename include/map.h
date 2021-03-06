#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

#define TILE 32

#include <iostream>
#include <fstream>
#include <cstring>

const int DEPTH = 3;

struct image_t
{
    int x, y;
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

/**
 * @brief structure representing each map
 * 
 */
struct map_t 
{
    char title[10];     //!< title of map

    int width, height;  //!< dimension of matrix-tiles
    tile_t **tiles;     //!< matrix of map tiles

    int n_doors;        //!< number of doors in map
    door_t *doors;      //!< array of doors
};

/**
 * @brief allocate memory that contain tiles
 * 
 * @param map 
 * @param width 
 * @param height 
 */
void map_allocate_tiles(map_t &map, const int width, const int height);

void map_allocate_doors(map_t &map, const int n_doors);

void map_init(map_t &map, const char title[10], const int width, const int height);
void map_print(const map_t &map);

void map_delete(const char title[10]);

void map_reload(map_t &map, const char title[10]);
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
void map_rem_image(map_t &map, const int x, const int y);

void map_set_solid(map_t &map, const int x, const int y, const bool col);
bool map_is_solid(const map_t &map, const int x, const int y);

void map_rem_door(map_t &map, const int x, const int y);
void map_rem_door(map_t &map, const int n);

int map_get_door(map_t &map, const int x, const int y);

bool map_in(const map_t &map, const int x, const int y);

#endif /* INCLUDE_MAP_H_ */

