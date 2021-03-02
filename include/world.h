#include <iostream>

#include "map.h"

class World {
    private:
        map_t map;
    public:
        World();
        void load(const std::string);
        void save(const std::string);

        tile_t get(const int, const int);
        void set(const int, const int, const int, const int, const int);
        void create(const std::string);
        
};