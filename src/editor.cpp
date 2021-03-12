#include <iostream>
#include <SFML/Graphics.hpp>


#include "../include/map.h"

class Editor {
    private:
        const int WIDTH = TILE*30, HEIGHT = TILE*25;
        const std::string TITLE = "Carcadia - paoli7612";

    public:
        sf::RenderWindow window;
        sf::Clock clock;
        float dt;
        bool running;

        Editor()
        {
            window.create(sf::VideoMode(WIDTH, HEIGHT), TITLE);
        }

        void loop()
        {
            
            running = true;
            while (running)
            {
                if (clock.getElapsedTime().asSeconds() >= 1.0f / 60){
                    dt = clock.getElapsedTime().asSeconds();
                    clock.restart();
                } else continue;
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
            window.clear();

            window.display();            
        }

        
};

int main(int argc, char **argv)
{
    Editor editor;

    editor.loop();

    return 0;
}