#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/player.h"

class Game {
    public:
        const int WIDTH = 1080, HEIGHT = 720;
        const std::string TITLE = "Carcadia - paoli7612";
        Player player;

        sf::RenderWindow window;
        sf::Clock clock; float dt;
        bool running;

        Game()
        {
            window.create(sf::VideoMode(WIDTH, HEIGHT), TITLE);
            player.init();
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                player.up();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                player.down();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                player.right();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                player.left();


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

            draw_grill();
            window.draw(player);
            window.display();
        }

        void draw_grill()
        {
            const int vertical_lines = (WIDTH/TILE)*4;
            const int horizontal_lines = (HEIGHT/TILE)*4;

            sf::Vertex *v_lines = new sf::Vertex[vertical_lines];
            sf::Vertex *h_lines = new sf::Vertex[horizontal_lines];
            
            for (int i=0; i<40*2; i+=2)
            {
                v_lines[i] = sf::Vertex(sf::Vector2f(i/2*TILE, 0));
                v_lines[i+1] = sf::Vertex(sf::Vector2f(i/2*TILE, HEIGHT));
            }
            for (int i=0; i<25*2; i+=2)
            {
                h_lines[i] = sf::Vertex(sf::Vector2f(0, i/2*TILE));
                h_lines[i+1] = sf::Vertex(sf::Vector2f(WIDTH, i/2*TILE));
            }

            window.draw(v_lines, vertical_lines, sf::Lines);
            window.draw(h_lines, horizontal_lines, sf::Lines);
        }
};

int main(int argc, char **argv)
{
    Game game;

    game.loop();

    return 0;
}