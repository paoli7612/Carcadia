#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#define S 48

enum Action{none, kick, punch};

class Player {
    private:
        char costume = '1';
        Texture texture;
        int frame = 0;
        Action action = none;

        void animate(){
            frame = (frame+1)%3;
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
            if (action == punch)
                sprite.setTextureRect(IntRect(8*S, ((2+(lx+1)/2))*S, S, S));
            else if (action == kick)
                sprite.setTextureRect(IntRect(9*S, ((2+(lx+1)/2))*S, S, S));
            else
                sprite.setTextureRect(IntRect((x+frame)*S, y*S, S, S));
            action = none;
        }

    public:
        Sprite sprite;
        int dx = 0;
        int dy = 0;
        int lx = -1;
        int speed = 5;

        void load(int x, int y, char costume){
            animate();
            change(costume);
            sprite.setPosition(Vector2f(x, y));
            sprite.scale(Vector2f(1.8f, 1.8f));
            
        }

        float t = 0;
        void update(float dt){
            t += dt;
            if (t > 0.1){
                animate();
                t = 0;
                if (dx != 0)
                    lx = dx;
            }
            sprite.move(dx*speed, dy*speed);

            // Touch edge
            Vector2f pos = sprite.getPosition();
            if (pos.x < -20) pos.x = -20;
            if (pos.x > 960-S-20) pos.x = 960-S-20;
            if (pos.y < 0) pos.y = 0;
            if (pos.y > 400-S-40) pos.y = 400-S-40;
            sprite.setPosition(pos);
        }

        void use(Action a){
            action = a;
        }

        void change(char c='0'){
            char path[] = "img/character/1.png";
            if (c == '0')
                c = ++costume;
            if (c == '8')
                costume = '1';
            path[14] = c;
            if (!texture.loadFromFile(path));
                texture.setSmooth(true);
            sprite.setTexture(texture);
        }


};
