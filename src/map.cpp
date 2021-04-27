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
        width x height
            porta.x porta.y
    */
    std::cout << map.title << std::endl;
    std::cout << "\t[size] " << map.width << " x " << map.height << std::endl;
    std::cout << "\t[doors] #" << map.n_doors << std::endl;
    for (int i=0; i<map.n_doors; i++)
    {
        door_t &d = map.doors[i];
        std::cout << "\t\t[pos] (" << d.x << " x " << d.y << ") ";
        std::cout << "[dest] " << d.dest << std::endl;
    }
        
}

void map_load(map_t &map, const char title[10])
{
    std::cout << "map_loat(" << title << ")" << std::endl;
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::ifstream file(filename);

    if (! file)
        throw "Errore nella apertura della mappa " + filename;

    // char title[10];
    file.read((char*)&map.title, sizeof(char[10]));

    // int width, height;
    file.read((char*)&map.width, sizeof(int));
    file.read((char*)&map.height, sizeof(int));

    map_allocate_tiles(map, map.width, map.height);

    // tile_t **tiles;
    for (int y=0; y<map.height; y++)
        for (int x=0; x<map.width; x++)
            file.read((char*)&map.tiles[y][x], sizeof(tile_t));
    
    // int n_doors;
    file.read((char*)&map.n_doors, sizeof(int));

    map_allocate_doors(map, map.n_doors);

    // door_t *doors;
    for (int i=0; i<map.n_doors; i++)
        file.read((char*)&map.doors[i], sizeof(door_t));

    std::cout << map.doors[0].x << std::endl;

    file.close();
}

void map_reload(map_t &map, const char title[10])
{
    
    delete[] map.doors;
    for (int y=0; y<map.height; y++)
        delete[] map.tiles[y];
    try
    {
        map_load(map, title);
    }
    catch(const std::exception& e)
    {
        std::cout << title << " ] inseistente";
    }
    
    
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
    for (int i=0; i<map.n_doors; i++)
        file.write((char*)&map.doors[i], sizeof(door_t));
        
    file.close();
}

void map_delete(const char title[10])
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::remove(filename.c_str());
}

void map_add_door(map_t &map, const door_t door)
{
    if (map.n_doors == 0)
    {
        map.doors = new door_t[1];
        map.doors[0] = door;
        map.n_doors = 1;
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

void map_rem_door(map_t &map)
{
    delete [] map.doors;
    map.n_doors = 0;
}

int map_get_door(map_t &map, const int x, const int y)
{
    std::cout << x << " " << std::endl;
    // ritorna la posizione nell'array delle door della door a posizione x y
    // ... se non sono presenti doors a quella posizione ritorna -1
    for (int i=0; i<map.n_doors; i++)
    {
        door_t &door = map.doors[i];
        std::cout << "d: " << door.x << " " << door.y << std::endl;
        if (door.x == x && door.y == y)
            return i;
    }
    return -1;
}
