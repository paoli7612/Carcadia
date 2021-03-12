#include <iostream>
#include <SFML/Graphics.hpp>


#include "../include/map.h"

class Editor {
    private:
        const std::string TITLE = "Carcadia - paoli7612";

        map_t map;

    public:
        sf::RenderWindow window;
        sf::RenderWindow tools;

        sf::Texture tools_back_texture;
        sf::Sprite tools_back_sprite;

        sf::Texture images_texture;
        sf::Sprite images_sprite;

        sf::Texture cursor_texture;
        sf::Sprite cursor_sprite;
        int cursor_ix, cursor_iy;

        sf::Clock clock;
        float dt;
        bool running;

        Editor()
        {
            map_load(map, "spawn");

            window.create(sf::VideoMode(WIDTH*32, HEIGHT*32), TITLE);
            tools.create(sf::VideoMode(512, 216), "tools", sf::Style::Titlebar);

            tools_back_texture.loadFromFile("img/tiles.png");
            tools_back_sprite.setTexture(tools_back_texture);

            images_texture.loadFromFile("img/tiles.png");
            images_sprite.setTexture(images_texture);

            cursor_texture.loadFromFile("img/cursor.png");
            cursor_sprite.setTexture(cursor_texture);
            cursor_ix = 0; cursor_iy = 0;
            
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
            while (tools.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::MouseButtonPressed:{
                        sf::Vector2i pos = sf::Mouse::getPosition(tools);

                        cursor_ix = pos.x/32;
                        cursor_iy = pos.y/32;

                        cursor_sprite.setPosition(sf::Vector2f(cursor_ix*32, cursor_iy*32));
                    }
                }
            }

            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::MouseMoved: {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                            click(true);
                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                            click(false);
                        break;
                    }
                    case sf::Event::MouseButtonPressed:
                        if (event.mouseButton.button == sf::Mouse::Left)
                            click(true);
                        else if (event.mouseButton.button == sf::Mouse::Right)
                            click(false);
                        break;

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
            // ________ TOOLS ________
            tools.clear();
            tools.draw(tools_back_sprite);
            tools.draw(cursor_sprite);
            tools.display();
            // ________ WINDOW _______
            window.clear();
            draw_grill();
            draw_map();
            window.display();            
        }

        void click(const bool isLeft)
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);

            int x = pos.x/32;
            int y = pos.y/32;

            image_t image = {cursor_ix, cursor_iy};
            if (isLeft)
                map_add(map, x, y, image);
            else
                map_remove(map, x, y);
            
            std::cout << image.ix << std::endl;
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
    Editor editor;

    editor.loop();

    return 0;
}