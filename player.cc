#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

#define S 48

using namespace sf;
using namespace std;

class Player {
    private:
        Texture texture;
        int frame = 0;

        void animate(){
            int x=0, y=0;
            if (dx == dy || dx == -dy){
                if (dx == 0) frame = 0;
                else {
                    x = 1;
                    y = 1 == dx;
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

            sprite.setTextureRect(IntRect((x+frame)*S, y*S, S, S));
        }

    public:
        Sprite sprite;
        int dx = 0;
        int dy = 0;
        int speed = 5;

        void load(){
            animate();
            if (!texture.loadFromFile("img/player.png"));
                texture.setSmooth(true);
            sprite.setTexture(texture);
            sprite.setScale(Vector2f(2, 2));
        }

        float t = 0;

        void update(float dt){
            t += dt;
            if (t > 0.1){
                frame = (frame+1)%3;
                animate();
                t = 0;
            }
            sprite.move(dx*speed, dy*speed);
        }
};
