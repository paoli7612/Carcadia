#include <SFML/Graphics.hpp>

#define W 40
#define H 25
#define T 32

typedef uint16_t code_t;

struct tile_t {
  code_t code;
};

struct map_t {
  tile_t tiles[H][W];
};

void map_print(map_t &);
void map_init(map_t &);

void map_draw(sf::RenderWindow &, map_t &);

void map_save(const map_t &, const char[]);
void map_load(map_t &, const char[]);
