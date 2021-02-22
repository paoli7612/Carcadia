#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

enum Action{none, kick, punch};

class Player {
    private:
        char costume = '1';
        int frame = 0;
        sf::Texture texture;
        sf::Action action = none;

        void animate();

    public:


}
