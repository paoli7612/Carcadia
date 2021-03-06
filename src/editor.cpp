// editor

#include <iostream>

#include "../include/loop.h"
#include "../include/map.h"
#include "../include/editor.h"

using namespace std;

Editor::Editor(const char title[10])
{
    map_load(map, title);
    mode = TILE_MODE;

    // main window
    init(map.width*32, map.height*32, "Carcadia");          
    cursorTexture.loadFromFile("img/cursor.png");
    cursorSprite.setTexture(cursorTexture);

    // tiles window
    tilesWindow.create(sf::VideoMode(704, 704), "tiles", sf::Style::Titlebar);
    tilesTextureBackground.loadFromFile("img/tiles.png");
    tilesSpriteBackground.setTexture(tilesTextureBackground);
    tilesSpriteSelector.setTexture(cursorTexture);

    tilesSpriteSelector.setPosition(0, 0);

    std::cout << "Use Q key to save map" << std::endl;
}

void Editor::click(bool isLeft, const int x, const int y)
{
    sf::Vector2i pos = (sf::Vector2i)tilesSpriteSelector.getPosition();
    image_t image = {pos.x/TILE, pos.y/TILE};
    switch (mode)
    {
        case TILE_MODE:
            if (isLeft)
                map_add_image(map, x, y, image);
            else
                map_rem_image(map, x, y);
            break;
        
        case SOLID_MODE:
            map_set_solid(map, x, y, isLeft);
            break;

        case DOOR_MODE:
            if (isLeft)
            {
                door_t door;
                door.x = x;
                door.y = y;
                door.image = image; 
                std::cout << "dest: ";
                std::cin >> door.dest;
                std::cout << "(dx - dy): ";
                std::cin >> door.dx >> door.dy;
                map_add_door(map, door);
            }
            else
                map_rem_door(map, x, y);
            break;
    }
}

void Editor::event()
{
    sf::Event event;
    while (tilesWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::MouseButtonPressed:
                sf::Vector2i m = sf::Mouse::getPosition(tilesWindow);
                int x = m.x/TILE*32;
                int y = m.y/TILE*32;
                tilesSpriteSelector.setPosition(x, y);
                break;
        }
    }
    while (window.pollEvent(event))
    {  
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                running = false;
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Key::Escape:
                        window.close();
                        running = false;
                        break;
                    
                    // E -> change editor mode
                    case sf::Keyboard::Key::E:
                        mode = (editor_mode)((mode+1)%3);
                        break;

                    // Q -> save map
                    case sf::Keyboard::Key::Q:
                        map_save(map);
                        std::cout << "[!] map saved [!]" << std::endl;
                        break;
                }
                break;
            
            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i m = sf::Mouse::getPosition(window);
                int x = m.x/TILE;
                int y = m.y/TILE;

                if (event.mouseButton.button == sf::Mouse::Left)
                    click(true, x, y);
                else if (event.mouseButton.button == sf::Mouse::Right)
                    click(false, x, y);                
                break;
            }
            
            case sf::Event::MouseMoved:
            {
                sf::Vector2i m = sf::Mouse::getPosition(window);
                int x = m.x/TILE;
                int y = m.y/TILE;
                cursorSprite.setPosition(x*32, y*32);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    click(true, x, y);
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                    click(false, x, y);
                break;
            }
        }
    }
}

void Editor::update(float dt)
{
}

void Editor::draw()
{
    if (mode == SOLID_MODE)
        draw_solid();
    window.draw(cursorSprite);


    // tiles

    tilesWindow.clear(sf::Color(90, 90, 90));
    tilesWindow.draw(tilesSpriteBackground);
    tilesWindow.draw(tilesSpriteSelector);
    tilesWindow.display();
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "use [make editor map=\"spawn\"]" << std::endl;
        return 1;
    }
    Editor e(argv[1]);
    e.start();
    
    return 0;
}
