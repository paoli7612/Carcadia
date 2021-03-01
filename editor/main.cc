#include <iostream>
#include <fstream>
#include <cstring>

#include "../src/map.h"

using namespace std;

void vettore_verticale(map_t &map, const int x, const int y1, const int y2, const code_t code)
{
    for (int y=y1; y<=y2; y++)
        map.tiles[y][x].code = code;
}

void vettore_orizzontale(map_t &map, const int x1, const int x2, const int y, const code_t code)
{
    for (int x=x1; x<=x2; x++)
        map.tiles[y][x].code = code;
}

void area(map_t &map, const int x1, const int y1, const int x2, const int y2, const code_t code)
{
    for (int x=x1; x<=x2; x++)
        for (int y=y1; y<=y2; y++)
            map.tiles[y][x].code = code;
}


int main(int argc, char **argv)
{
    map_t map;

    const char menu[] =
        "\t1. Cambia valore cella [x, y, code]\n"
        "\t2. Cambia valore vettore verticale [x, y1, y2, code]\n"
        "\t3. Cambia valore vettore orizzontale [x1, x2, y, code]\n"
        "\t4. Cambia valore area [x1, y1, x2, y2, code]\n"
        "\n\n"
        "\t7. Salva mappa [nome]\n"
        "\t8. Carica mappa [nome]\n"
        "\t9. Termina\n";

    bool run = true;
    bool is_load = false;
    while (run)
    {
        int scelta;

        if (is_load)
            map_print(map);

        cout << menu << endl;
        cin >> scelta;

        string name, filename;
        
        switch (scelta)
        {
            int x1, y1, x2, y2;
            code_t code;
            case 1:
                cin >> x1 >> y1 >> code;
                map.tiles[y1][x1].code = code;
                break;
            case 2:
                cin >> x1 >> y1 >> y2 >> code;
                vettore_verticale(map, x1, y1, y2, code);
                break;
            case 3:
                cin >> x1 >> x2 >> x1 >> code;
                vettore_orizzontale(map, x1, x2, y1, code);
                break;
            case 4:
                cin >> x1 >> y1 >> x2 >> y2 >> code;
                area(map, x1, y1, x2, y2, code);
                break;
            case 7: // Salva
                cin >> name;
                filename = "maps/" + name + ".dat";
                map_save(map, filename);
                break;
            case 8: // Carica
                cin >> name;
                filename = "maps/" + name + ".dat";
                map_load(map, filename);
                is_load = true;
                break;
            case 9:
                run = false;
                break;
        }
    }

    return 0;
}