#include "../include/map.h"

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
    int i=0;
    for (; i<DEPTH && (!is_empty(image[i])); i++) ;
    return i;
}

bool equals(const image_t a, const image_t b)
{
    return (a.x == b.x) && (a.y == b.y);
}

void tile_down(tile_t &tile)
{
    for (int i=0; i<DEPTH-1; i++)
        tile.images[i] = tile.images[i+1];
    tile.images[DEPTH-1] = EMPTY_IMAGE;
}

void map_init(map_t &map, const char title[10], const int width, const int height)
{
    strcpy(map.title, title);

    map.width = width;
    map.height = height;

    map.n_doors = 0;

    map.tiles = new tile_t*[height];
    for (int y=0; y<height; y++)
        map.tiles[y] = new tile_t[width];
    
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
        { // per ogni tile della matrice
            tile_t &tile = map.tiles[y][x];
            for (int z=0; z<DEPTH; z++)
                tile.images[z] = EMPTY_IMAGE;
            tile.isCollide = false;    
        }
}

void map_load(map_t &map, const char title[10])
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::ifstream file(filename);

    if (! file)
        throw "Errore nella apertura della mappa " + filename;

    char t[10];
    int w, h;

    // char title[10];
    file.read((char*)&t, sizeof(char[10]));

    // int width, height;
    file.read((char*)&w, sizeof(int));
    file.read((char*)&h, sizeof(int));

    map_init(map, t, w, h);

    // tile_t **tiles;
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.read((char*)&map.tiles[y][x], sizeof(tile_t));
    
    // int n_doors;
    file.read((char*)&map.n_doors, sizeof(int));

    // door_t *doors;
    file.read((char*)&map.doors, sizeof(door_t[map.n_doors]));
        
    file.close();
}

void map_save(const map_t &map)
{
    std::string filename = "maps/" + (std::string)map.title + ".tomaoli";
    std::ofstream file(filename);

    if (! file)
        throw "Errore nella apertura della mappa " + filename;

    // char title[10];
    file.write((char*)&map.title, sizeof(char[10]));

    // int width, height;
    file.write((char*)&map.width, sizeof(int));
    file.write((char*)&map.height, sizeof(int));

    // tile_t **tiles;
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.write((char*)&map.tiles[y][x], sizeof(tile_t));
    
    // int n_doors;
    file.write((char*)&map.n_doors, sizeof(int));

    // door_t *doors;
    file.write((char*)&map.doors, sizeof(door_t[map.n_doors]));
        
    file.close();
}

void map_add_door(map_t &map, const door_t door)
{
    if (map.n_doors == 0)
    {
        map.doors = new door_t[1];
        map.doors[0] = door;
    }
    else
    {
        // copio il puntatore alle porte attuali
        door_t *old_doors = map.doors;          

        // uso il puntatore della mappa per creare un'array lungo come prima +1
        map.doors = new door_t[map.n_doors + 1];    
        
        // ricopio tutte le porte nel nuovo array
        for (int i=0; i<map.n_doors; i++)
            map.doors[i] = old_doors[i];
        
        // aggiungo la nuova porta e incremento il contatore delle porte nella mappa
        map.doors[++map.n_doors] = door;

        // elimino il vecchio array di porte
        delete [] old_doors;
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