#include <cstring>

#define W 40
#define H 25
#define T 32



typedef uint16_t code_t;
const code_t EMPTY = 76;

struct tile_t {
  bool collide;
  code_t code;
};

struct map_t {
  tile_t tiles[H][W];
};

void map_init(map_t &);
void map_print(map_t &);
void map_save(const map_t &, std::string);

void map_load(map_t &, std::string);
