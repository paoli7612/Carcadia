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
