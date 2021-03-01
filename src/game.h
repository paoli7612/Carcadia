#include <iostream>

#include "window.h"
#include "world.h"
#include "player.h"

class Game {
    private:
        Window window;
        World world;
        Player player;

        void draw_world();

    public:
        Game();
        void start();
        void loop();
        
        void event();
        void update();
        void draw();
};
