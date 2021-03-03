
#include "../include/editor.h"

using namespace std;

Editor::Editor()
{
    tools.create(sf::VideoMode(32*32, 32*32), "Tools", sf::Style::Titlebar);
    sf::Texture texture;
    texture.loadFromFile("img/terrain.png");
    sf::Sprite sprite(texture);
    tools.clear(sf::Color(50, 50, 50));
    tools.draw(sprite);
    tools.display();
}

void Editor::start()
{
    world.load("spawn");
    window.start(WIDTH*TILE, HEIGHT*TILE);
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
    while (tools.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::MouseButtonPressed: {
                sf::Vector2i pos = sf::Mouse::getPosition(tools);
                cursor.set(pos.x, pos.y);
            }
        }
    }
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
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
                    
                    case sf::Keyboard::Space:
                        world.set(cursor.x, cursor.y, 1, cursor.cx, cursor.cy);
                        world.print();
                        break;
                    case sf::Keyboard::M:
                        world.set(cursor.x, cursor.y, 0, cursor.cx, cursor.cy);
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
    window.clear();
    //window.draw(world);
    //window.draw(text);
    draw_world();
    window.draw(cursor);
    window.display();
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