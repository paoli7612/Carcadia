#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/player.h"

class Game {
    public:
        const std::string TITLE = "Carcadia - paoli7612";
        Player player;

        map_t map;

        sf::Texture images_texture;
        sf::Sprite images_sprite;

        sf::RenderWindow window;
        sf::Clock clock; float dt;
        bool running;

        Game()
        {
            window.create(sf::VideoMode(WIDTH*32, HEIGHT*32), TITLE);
            player.init();
            player.setMap(&map);
            map_load(map, "spawn");

            images_texture.loadFromFile("img/tiles.png");
            images_sprite.setTexture(images_texture);
        }

        void start()
        {
            loop();
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
                update(dt);
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
                        if (event.key.code == sf::Keyboard::Key::Escape){
                            window.close();
                            running = false;}
                        break;
                }
            }
            
        }

        void update(float dt)
        {
            player.update(dt);
        }

        void draw()
        {
            sf::View view(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
            view.setCenter(player.getPosition());
            window.setView(view);

            window.clear();
            
            draw_grill();
            draw_map();

            window.draw(player);
            window.display();
        }


        void draw_map()
        {
            for (int z=0; z<DEPTH; z++)
                for (int y=0; y<HEIGHT; y++)
                    for (int x=0; x<WIDTH; x++)
                    {
                        image_t &image = map.tiles[y][x].image[z];
                        if (!image_equals(image, EMPTY))
                        {
                            images_sprite.setTextureRect(sf::IntRect(image.ix*32, image.iy*32, 32, 32));
                            images_sprite.setPosition(sf::Vector2f(x*32, y*32));
                            window.draw(images_sprite);
                        }
                    }
        }

        void draw_grill()
        {
            const int vertical_lines = (WIDTH*32/TILE)*4;
            const int horizontal_lines = (HEIGHT*32/TILE)*4;

            sf::Vertex *v_lines = new sf::Vertex[vertical_lines];
            sf::Vertex *h_lines = new sf::Vertex[horizontal_lines];
            
            for (int i=0; i<40*2; i+=2)
            {
                v_lines[i] = sf::Vertex(sf::Vector2f(i/2*TILE, 0));
                v_lines[i+1] = sf::Vertex(sf::Vector2f(i/2*TILE, HEIGHT*32));
            }
            for (int i=0; i<25*2; i+=2)
            {
                h_lines[i] = sf::Vertex(sf::Vector2f(0, i/2*TILE));
                h_lines[i+1] = sf::Vertex(sf::Vector2f(WIDTH*32, i/2*TILE));
            }

            window.draw(v_lines, vertical_lines, sf::Lines);
            window.draw(h_lines, horizontal_lines, sf::Lines);
        }
};

int main(int argc, char **argv)
{
    Game game;

    game.start();

    return 0;
}