#include "../include/map.h"

#include "map/door.cpp"
#include "map/files.cpp"

image_t EMPTY_IMAGE = {-1, -1};

bool is_empty(const image_t image)
{
    return (image.x == -1) && (image.y == -1);
}

bool in_map(const map_t &map, const int x, const int y)
{
    return !(x < 0 || y < 0 || x >= map.width || y >= map.height);
}

int top(const image_t image[DEPTH])
{
    // profondità della prima immagine vuota a partire dal basso
    // se sono tutte "occupate" ritorna DEPTH
    int i=0;
    for (; i<DEPTH && (!is_empty(image[i])); i++) ;
    return i;
}

bool equals(const image_t a, const image_t b)
{
    // true -> le due immagini sono uguali
    return (a.x == b.x) && (a.y == b.y);
}

void tile_down(tile_t &tile)
{
    // sposta tutte le immagini verso il basso
    // la prima immagine viene persa
    for (int i=0; i<DEPTH-1; i++)
        tile.images[i] = tile.images[i+1];
    tile.images[DEPTH-1] = EMPTY_IMAGE;
}

void map_allocate_tiles(map_t &map, const int width, const int height)
{
    // alloca la memoria per tutte le tile della mappa
    map.tiles = new tile_t*[height];
    for (int y=0; y<height; y++)
        map.tiles[y] = new tile_t[width];
}

void map_allocate_doors(map_t &map, const int n_doors)
{
    map.doors = new door_t[n_doors];
}

void map_init(map_t &map, const char title[10], const int width, const int height)
{
    strcpy(map.title, title);

    map.width = width;
    map.height = height;
    map.n_doors = 0;

    map_allocate_tiles(map, width, height);
    
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
        { // per ogni tile della matrice
            tile_t &tile = map.tiles[y][x];
            // ... imposta le immagini vuote
            for (int z=0; z<DEPTH; z++)
                tile.images[z] = EMPTY_IMAGE;
            tile.isCollide = false;    
        }
}

void map_print(const map_t &map)
{
    /*
    title
        map.width x map.height
        & for door in map.doors:
            door.x door.y door.dest door.dx door.dy
    */
    std::cout << map.title << std::endl;
    std::cout << "\t[size] " << map.width << " x " << map.height << std::endl;
    std::cout << "\t[doors] #" << map.n_doors << std::endl;
    for (int i=0; i<map.n_doors; i++)
    {
        std::cout <<"\t" << i << "] {";
        door_t &d = map.doors[i];
        std::cout << "\t[pos] (" << d.x << " x " << d.y << ")\n";
        std::cout << "\t\t[dest] " << d.dest << " (" << d.dx << " x " << d.dy << ")\n";
        std::cout << "\t\t[image] " << d.image.x << " x " << d.image.y;
        std::cout <<"\t}" << std::endl << std::endl;
    }
        
}

void map_add_image(map_t &map, const int x, const int y, const image_t image)
{
    if (!in_map(map, x, y))
        return;
    
    tile_t &tile = map.tiles[y][x];

    // parte dalla prima immagine della tile e sale finche non trova una immagine vuota
    int z = top(tile.images);

    if (z > 0 && equals(tile.images[z-1], image)) // ultima immagine inserita uguale
        return;

    if (z == DEPTH) // cella piena di immagini
    {
        tile_down(tile);
        z--;
    }

    tile.images[z] = image;
}

void map_rem_image(map_t &map, const int x, const int y)
{
    if (!in_map(map, x, y))
        return;

    tile_t &tile = map.tiles[y][x];

    int z = top(tile.images);

    if (z)
        tile.images[z-1] = EMPTY_IMAGE;
}

void map_set_solid(map_t &map, const int x, const int y, const bool col=true)
{
    if (! in_map(map, x, y))
        return;

    map.tiles[y][x].isCollide = col;
}

bool map_is_solid(const map_t &map, const int x, const int y)
{
    if (! in_map(map, x, y))
        return true;
    
    return map.tiles[y][x].isCollide;
}
