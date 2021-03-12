#include <iostream>
#include <SFML/Graphics.hpp>

#define TILE 32

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
            const int vertical_lines = (WIDTH/TILE)*2;
            const int horizontal_lines = (HEIGHT/TILE)*2;

            sf::Vertex *v_lines = new sf::Vertex[vertical_lines];
            sf::Vertex *h_lines = new sf::Vertex[horizontal_lines];
            
            for (int i=0; i<40; i+=2)
            {
                v_lines[i] = sf::Vertex(sf::Vector2f(i*TILE, 0));
                v_lines[i+1] = sf::Vertex(sf::Vector2f(i*TILE, HEIGHT));
            }
            for (int i=0; i<25; i+=2)
            {
                h_lines[i] = sf::Vertex(sf::Vector2f(0, i*TILE));
                h_lines[i+1] = sf::Vertex(sf::Vector2f(WIDTH, i*TILE));
            }

            window.draw(v_lines, vertical_lines, sf::Lines);
            window.draw(h_lines, horizontal_lines, sf::Lines);
            window.display();            
        }
};

int main(int argc, char **argv)
{
    Editor editor;

    editor.loop();

    return 0;
}