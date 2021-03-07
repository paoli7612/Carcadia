
#include "../include/map.h"

bool image_equals(const image_t &a, const image_t &b)
{
    if (a.ix != b.ix)
        return false;
    
    if (a.iy != b.iy)
        return false;
    
    return a.kind == b.kind;
}

void map_init(map_t &map, const std::string title="title")
{
    
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
        {
            for (int z=0; z<DEPTH; z++)
                map.tiles[y][x].image[z] = EMPTY;
            map.tiles[y][x].isSolid = false;
        }
}

void map_load(map_t &map, const std::string &name)
{
    std::string filename = "maps/" + name + ".dat";

    std::ifstream file(filename);

    if (! file)
        throw "Errore lettura mappa: " + filename;
    
    file.read((char *)&map, sizeof(map));

    file.close();    
}

void map_save(const map_t &map, const std::string &name)
{
    std::string filename = "maps/" + name + ".dat";

    std::ofstream file(filename);

    if (! file)
        throw "Errore scrittura mappa: " + filename;
    
    file.write((char *)&map, sizeof(map));

    file.close();    
}

void map_fill(map_t &map, const image_t &image, const int z)
{
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
            map.tiles[y][x].image[z] = image;
}

void map_fill_random(map_t &map, const image_t *images, const int len, const int z)
{
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
            map.tiles[y][x].image[z] = images[rand()%len];
}

 /*
  * Sposta verso il basso tutte le immagini in una certa cella
  * L'immagine piu bassa andrà persa
  */
void map_down(map_t &map, const int x, const int y)
{
    for (int z=0; z<DEPTH-1; z++)
        map.tiles[y][x].image[z] = map.tiles[y][x].image[z+1];

    map.tiles[y][x].image[DEPTH-1] = EMPTY;
} 

void map_add_up(map_t &map, const int x, const int y, const image_t image)
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

 /*
  * Cancella l'immagine piu alta nella cella x y
  * 
  */
void map_remove_up(map_t &map, const int x, const int y)
{
    tile_t &tile = map.tiles[y][x];
    
    int z;
    for (z=1; z<DEPTH; z++)
        if (image_equals(tile.image[z], EMPTY))
        {
            tile.image[z-1] = EMPTY; 
            break;
        }

    if (z == DEPTH)
        tile.image[DEPTH-1] = EMPTY;
}

void map_set_solid(map_t &map, const int x, const int y)
{
    map.tiles[y][x].isSolid = true;
}

void map_set_nonsolid(map_t &map, const int x, const int y)
{
    map.tiles[y][x].isSolid = false;
}