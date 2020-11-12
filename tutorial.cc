#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Tutorial {
    private:
        Texture texture_arrows;
        Texture texture_space;

    public:
        Sprite arrows;
        Sprite space;

        
        void load(){
            if (!texture_arrows.loadFromFile("img/tutorial/arrows.png"));
                texture_arrows.setSmooth(true);
            if (!texture_space.loadFromFile("img/tutorial/space.png"));
                texture_space.setSmooth(true);
            arrows.setTexture(texture_arrows);
            space.setTexture(texture_space);

            arrows.setScale(Vector2f(.5f, .5f));
            space.setScale(Vector2f(.1f, .1f));

            arrows.setPosition(Vector2f(0, 400));
            space.setPosition(Vector2f(300, 400));

        }

        void draw(RenderWindow &window){
            window.draw(arrows);
            window.draw(space);
        }
};
