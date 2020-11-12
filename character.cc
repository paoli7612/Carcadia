#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Character: Sprite {
    private:
        Texture texture;
        int frame = 0;

    public:
        int dx = 0;
        int dy = 0;
        int lx = -1;
        int speed = 5;
        float t = 0;

        void load(char n){
            char name[] = "img/character/1.png";
            name[15] = n;
            animate();
            if (!texture.loadFromFile(name));
                texture.setSmooth(true);
            this->setTexture(texture);
            this->setScale(Vector2f(2, 2));
        }

        void update(float dt){
            t += dt;
            if (t > 0.1){
                frame = (frame+1)%3;
                animate();
                t = 0;
                if (dx != 0)
                    lx = dx;
            }
            this->move(dx*speed, dy*speed);
        }

        void animate(){
            int x=0, y=0;
            if (dx == dy || dx == -dy){
                if (dx == 0){
                    frame = 0;
                    y = (lx+1)/2;
                } 
                else {
                    x = 1;
                    y = (1 == dx);
                }
            } else if (dy == 0){
                x = 1;
                if (dx == -1) y=0;
                else if (dx == 1) y=1;
            } else if (dx == 0){
                x = 7;
                if (dy == 1) y = 0;
                else if (dy == -1) y = 1;
            }

            this->setTextureRect(IntRect((x+frame)*48, y*48, 48, 48));
        }
};
