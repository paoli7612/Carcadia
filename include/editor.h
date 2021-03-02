#include <iostream>

#include "window.h"
#include "world.h"
#include "cursor.h"
#include "images.h"

class Editor {
    private:
        sf::Clock clock;
        float dt;

        Window window;
        sf::RenderWindow tools;

        World world;
        Cursor cursor;
        Images images;

        void draw_world();

    public:
        Editor();
        void start();
        void loop();

        void event();
        void update();
        void draw();
};
