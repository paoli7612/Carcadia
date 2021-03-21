#include <iostream>
#include <SFML/Graphics.hpp>


#include "../include/map.h"

class Editor {
    private:
        const std::string TITLE = "Carcadia - paoli7612";
        map_t map;
        bool running;
        sf::Clock clock;

        void click(const bool isLeft)
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);

            int x = pos.x/32;
            int y = pos.y/32;
            
            image_t image = {cursor_ix, cursor_iy};
            if (isLeft)
                map_add(map, x, y, image);
            //else
                //map_remove(map, x, y);
        }

        void draw_map()
        {
            for (int z=0; z<DEPTH; z++)
                for (int y=0; y<map.height; y++)
                    for (int x=0; x<map.width; x++)
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

    public:
        // main window
        sf::RenderWindow window;

        // tools window
        sf::RenderWindow tools;
        sf::Texture tools_back_texture;
        sf::Sprite tools_back_sprite;

        // tiles image
        sf::Texture images_texture;
        sf::Sprite images_sprite;

        // cursor
        sf::Texture cursor_texture;
        sf::Sprite cursor_sprite;
        int cursor_ix, cursor_iy;

        Editor(std::string title)
        {
            //map_init(map, "spawn", 10, 10);
            map_load(map, title);
            map_print(map);
            window.create(sf::VideoMode(map.width*TILE, map.height*TILE), TITLE);
            tools.create(sf::VideoMode(640, 352), "tools", sf::Style::Titlebar);

            tools_back_texture.loadFromFile("img/tiles.png");
            tools_back_sprite.setTexture(tools_back_texture);

            images_texture.loadFromFile("img/tiles.png");
            images_sprite.setTexture(images_texture);

            cursor_texture.loadFromFile("img/cursor.png");
            cursor_sprite.setTexture(cursor_texture);
            cursor_ix = 0; cursor_iy = 0;
        }
    
        void loop();

        void event() {
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
                        switch (event.key.code)
                        {
                            case sf::Keyboard::Key::Escape:
                                running = false;
                                break;

                            case sf::Keyboard::Key::Q:
                                map_save(map);
                                break;

                            case sf::Keyboard::Key::W:
                                cursor_sprite.move(0, -32);
                                cursor_iy--;
                                break;
                            case sf::Keyboard::Key::A:
                                cursor_sprite.move(-32, 0);
                                cursor_ix--;
                                break;
                            case sf::Keyboard::Key::S:
                                cursor_sprite.move(0, 32);
                                cursor_iy++;
                                break;
                            case sf::Keyboard::Key::D:
                                cursor_sprite.move(32, 0);
                                cursor_ix++;
                                break;
                            
                            case sf::Keyboard::Key::P:
                                map_print(map);
                                break;
                        }
                        break;
                }
            }
        }
        
        void update(const float) {

        }
        void draw() {
            // ________ TOOLS ________
            tools.clear(sf::Color(90, 90, 90));
            tools.draw(tools_back_sprite);
            tools.draw(cursor_sprite);
            tools.display();
            // ________ WINDOW _______
            window.clear();
            draw_map();

            window.display(); 
        }
};

void Editor::loop()
{
    running = true;
    float dt;
    while (running)
    {
        // clock
        if (clock.getElapsedTime().asSeconds() >= 1.0f / 60){
            dt = clock.getElapsedTime().asSeconds();
            clock.restart();
        } else continue;

        event();
        update(dt);
        draw();
    }
}

int main(int argc, char **argv)
{
    using namespace std;
    
    string title;
    cout << "Inserisci titolo della mappa da modificare: ";
    cin >> title;

    Editor editor(title);
    editor.loop();

    return 0;
}