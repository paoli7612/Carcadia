#include <iostream>
#include <cstring>

#include "sprite.h"

class Player : public Sprite {
    private:
    public:
        short dx = 0, dy = 0;
        Player();
        void update();
};