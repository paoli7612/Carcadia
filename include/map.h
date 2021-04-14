#include <iostream>
#include <fstream>

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

struct map_t 
{
    int width, height;
    tile_t **tiles;
};