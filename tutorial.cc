#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Tutorial {
    private:
        Texture texture;

    public:
        Sprite sprite;
        
        void load(){
            if (!texture.loadFromFile("img/tutorial.png"));
                texture.setSmooth(true);
            sprite.setTexture(texture);

            sprite.setPosition(Vector2f(0, 400));

        }

        void draw(RenderWindow &window){
            window.draw(sprite);
        }
};
