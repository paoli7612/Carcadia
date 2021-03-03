
#include "../include/editor.h"

using namespace std;

Editor::Editor()
{
}

void Editor::start()
{
    world.load("spawn");

    window.start(WIDTH*TILE, HEIGHT*TILE);
    tools.start();

    images.set_window(window);
    loop();
}

void Editor::loop()
{
    while (window.isOpen())
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

void Editor::event()
{
    sf::Event event;
    while (tools.pollEvent(event)){}
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::MouseMoved: {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                int x = pos.x/32;
                int y = pos.y/32;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    world.set(x, y, cursor.z, cursor.x, cursor.y);
                break;
            }
            case sf::Event::MouseButtonPressed: {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                int x = pos.x/32;
                int y = pos.y/32;

                world.set(x, y, cursor.z, cursor.x, cursor.y);
                break;
            }
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        cursor.up();
                        break;
                    case sf::Keyboard::Down:
                        cursor.down();
                        break;
                    case sf::Keyboard::Right:
                        cursor.right();
                        break;
                    case sf::Keyboard::Left:
                        cursor.left();
                        break;
                    
                    case sf::Keyboard::Q:
                        cursor.z = 2;
                        break;
                    case sf::Keyboard::A:
                        cursor.z = 1;
                        break;
                    case sf::Keyboard::Z:
                        cursor.z = 0;
                        break;
                    
                    
                    case sf::Keyboard::S:
                        world.save("spawn");
                        break;
                }
                break;
            }
            case sf::Event::Closed: {
                window.close();
                break;
            }

        }
      
    }
  
}

void Editor::update()
{
    cursor.update();
}

void Editor::draw()
{
    // WINDOW
    window.clear();
    draw_world();
    window.display();

    // TOOLS
    tools.clear();
    tools.background();
    tools.draw(cursor);
    tools.display();
}

void Editor::draw_world()
{
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
        {
            tile_t tile = world.get(x, y);
            for (int z=0; z<DEPTH; z++)
            {
                images.draw(x, y, tile.image[z].x, tile.image[z].y);
            }
        }
            
}