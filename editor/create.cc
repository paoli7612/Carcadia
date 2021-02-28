#include <iostream>
#include <cstring>

#include "../classes/map.h"

using namespace std;

void ask_map(map_t &map)
{
  bool run = true;
  system("clear");
  map_print(map);
  while (run)
  {
    cout << "Inserisci le coordinate (x, y)";
    int x, y;
    cin >> x >> y;
    cout << "Inserisci il nuovo codice (c)";
    int c;
    cin >> c;

    map.tiles[y][x].code = c;
    system("clear");
    map_print(map);

    cout << "Continuare? (s/n): ";
    char r;
    cin >> r;
    if (r == 'n')
      run = false;
  }
}

int main(int argc, char **argv)
{
  if (argc != 2)
    throw 1;

  string map_name = argv[1];
  string file_name = "maps/" + map_name + ".dat";

  if (map_name == "spawn")
  {
    map_t map;

    try {
      map_load(map, file_name);
    } catch (int e) {
      map_init(map);
    }
    map_print(map);

    ask_map(map);

    map_save(map, file_name);
  }

  return 0;
}
