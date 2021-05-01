#include "../../include/map.h"

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
        
        // aggiungo la nuova porta e 
        map.doors[map.n_doors] = door;

        //incremento il contatore delle porte nella mappa
        map.n_doors++;

        // elimino il vecchio array di porte
        delete [] old_doors;
    }
    
}

void map_rem_door(map_t &map, const int n)
{
    if (map.n_doors == 1)
    {
        delete [] map.doors;
        map.n_doors = 0;
    }

    // copio il puntatore alle porte attuali
    door_t *old_doors = map.doors;          

    // uso il puntatore della mappa per creare un'array lungo come prima -1
    map.doors = new door_t[map.n_doors - 1];    
    
    // ricopio tutte le porte precedenti a quella eliminata
    for (int i=0; i<n; i++)
        map.doors[i] = old_doors[i];
    
    // ricopio tutte le porte dopo quella eliminata
    for (int i=n; i<map.n_doors; i++)
        map.doors[i] = old_doors[i+1];
    
    //decremento il contatore delle porte nella mappa
    map.n_doors--;

    // elimino il vecchio array di porte
    delete [] old_doors;
}

void map_rem_door(map_t &map, const int x, const int y)
{
    int dd = map_get_door(map, x, y);
    if (dd >= 0)
        map_rem_door(map, dd);
}

int map_get_door(map_t &map, const int x, const int y)
{
    // ritorna la posizione nell'array delle door della door a posizione x y
    // ... se non sono presenti doors a quella posizione ritorna -1
    for (int i=0; i<map.n_doors; i++)
    {
        door_t &door = map.doors[i];
        if (door.x == x && door.y == y)
            return i;
    }
    return -1;
}
