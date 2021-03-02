#include <iostream>
#include <cstring>

#include "sprite.h"

class Cursor : public Sprite {
    private:
    public:
        short dx = 0, dy = 0;
        int x=0, y=0;

        int code = 10;

        Cursor();
        void update();

        void up();
        void down();
        void left();
        void right();

        void change(const int);
        void set(const int, const int);

};

