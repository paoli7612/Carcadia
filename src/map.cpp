
#include "../include/map.h"

void map_print(const map_t &map)
{
    for (int z=0; z<DEPTH; z++)
    {
        for (int y=0; y<map.height; y++)
        {
            for (int x=0; x<map.width; x++)
            {
                const image_t &image = map.tiles[y][x].image[z];
                std::cout << "(" << image.ix << "/" << image.iy << ")";
            }
            std::cout << std::endl;
        }
    }
}

bool image_equals(const image_t a, const image_t b)
{
    return a.ix == b.ix && a.iy == b.iy;
}

void map_init(map_t &map, const std::string title, const int width, const int height)
{
    for (int y=0; y<height; y++)
        for (int x=0; x<width; x++)
        {
            tile_t &tile = map.tiles[y][x];
            tile.isSolid = false;
            for (int z=0; z<DEPTH; z++)
                tile.image[z] = EMPTY;
        }

    int c;
    for (c=0; title[c]!='\0'; c++)
        map.title[c] = title[c];
    map.title[c] = '\0';
}

void map_save(const map_t &map)
{
    std::string filename = "maps/" + (std::string)map.title + ".tomaoli";
    std::ofstream file(filename);

    file.write((char*)&map, sizeof(map_t));

    file.close();
}

void map_load(map_t &map, const std::string title)
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::ifstream file(filename);

    file.read((char*)&map, sizeof(map_t));

    file.close();
}

void map_down(map_t &map, const int x, const int y)
{
    for (int z=0; z<DEPTH-1; z++)
        map.tiles[y][x].image[z] = map.tiles[y][x].image[z+1];

    map.tiles[y][x].image[DEPTH-1] = EMPTY;
}

void map_add(map_t &map, const int x, const int y, const image_t image)
{
    tile_t &tile = map.tiles[y][x];

    int z;
    for (z=0; z<DEPTH; z++)
        if (image_equals(tile.image[z], EMPTY))
        {
            if (z > 0 && image_equals(tile.image[z-1], image))
                return;
            tile.image[z] = image;
            break;
        }

    if (z == DEPTH)
    {
        map_down(map, x, y);
        tile.image[DEPTH-1] = image;
    }

}

void map_remove(map_t &map, const int x, const int y)
{
    tile_t &tile = map.tiles[y][x];
    int z;
    for (z=0; z<DEPTH-1; z++)
        if (image_equals(tile.image[z+1], EMPTY))
        {
            tile.image[z] = EMPTY;
            break;
        }

    if (z == DEPTH-1)
        tile.image[z] = EMPTY;
}

bool isSolid(const map_t &map, const int x, const int y)
{
    std::cout << "isSolid" << x << " " << y << "\n";
    if (x < 0 || x >= map.width)
        return true;
    if (y < 0 || y >= map.height)
        return true;

    return map.tiles[y][x].isSolid;
}
