#include <iostream>

#include "map.h"

class World {
    private:
        map_t map;
    public:
        World();
        void load(const std::string);
        void create(const std::string);
        void clear();
};