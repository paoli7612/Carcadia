
#include "../include/map.h"

bool in_map(const map_t &map, const int x, const int y)
{
    if (x < 0 || x >= map.width)
        return false;
    if (y < 0 || y >= map.height)
        return false;
    return true;
}

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
    map.tiles = new tile_t*[height];
    for (int y=0; y<height; y++)
        map.tiles[y] = new tile_t[width];

    for (int y=0; y<height; y++)
        for (int x=0; x<width; x++)
        {
            tile_t &tile = map.tiles[y][x];
            tile.isSolid = false;
            for (int z=0; z<DEPTH; z++)
                tile.image[z] = EMPTY;
        }

    map.title = title;
    map.height = height;
    map.width = width;
}

void map_save(const map_t &map)
{
    std::string filename = "maps/" + (std::string)map.title + ".tomaoli";
    std::ofstream file(filename.c_str());

    file.write((char*)&map.width, sizeof(int));
    file.write((char*)&map.height, sizeof(int));

    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.write((char*)&map.tiles[y][x], sizeof(tile_t));

    file.close();
}

void map_load(map_t &map, const std::string title)
{
    std::string filename = "maps/" + title + ".tomaoli";
    std::ifstream file(filename.c_str());

    if (! file)
        throw "file mappa inesistente";

    int w, h;
    file.read((char*)&w, sizeof(int));
    file.read((char*)&h, sizeof(int));

    map_init(map, title, w, h);

    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.read((char*)&map.tiles[y][x], sizeof(tile_t));

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
    if (!in_map(map, x, y))
        return true; // fuori dalla mappa è solido

    return map.tiles[y][x].isSolid;
}


void map_addfile(const std::string title)
{
    std::ifstream file("maps/all_maps.txt");
    int n;
    file >> n;
    std::string *nomi = new std::string[n];
    for (int i=0; i<n; i++)
        file >> nomi[i];
    file.close();

    std::ofstream ofile("maps/all_maps.txt");
    ofile << n+1 << std::endl;
    for (int i=0; i<n; i++)
        ofile << nomi[i] << std::endl;
    
    ofile << title;


}

void map_setSolid(map_t &map, const bool isLeft, const int x, const int y){
    if (!in_map(map, x, y))
        return;
    
    map.tiles[y][x].isSolid = isLeft;
}
