#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/map.h"

class Game {
    private:
        const int WIDTH = 1080, HEIGHT = 720;
        const std::string TITLE = "Carcadia - paoli7612";

    public:
        sf::RenderWindow window;
        bool running;

        Game()
        {
            window.create(sf::VideoMode(WIDTH, HEIGHT), TITLE);
        }

        void loop()
        {
            running = true;
            while (running)
            {
                event();
                update();
                draw();
            }
        }

        void event()
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        window.close();
                        running = false;
                        break;

                    case sf::Event::KeyPressed:
                        break;
                }
            }
            
        }

        void update()
        {

        }

        void draw()
        {

        }
};

int main(int argc, char **argv)
{
    Game game;

    game.loop();

    return 0;
}