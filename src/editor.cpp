// editor

#include <iostream>

#include "../include/loop.h"
#include "../include/map.h"
#include "../include/player.h"

using namespace std;

class Editor : public Loop {
    private:
        void click(const bool, const int, const int);

    public:
        Editor()
        {
            map_load(map, "spawn");

            // main window
            init(map.width*32, map.height*32, "Carcadia");          
            cursorTexture.loadFromFile("img/cursor.png");
            cursorSprite.setTexture(cursorTexture);

            // tiles window
            tilesWindow.create(sf::VideoMode(640, 704), "tiles", sf::Style::Titlebar);
            tilesTextureBackground.loadFromFile("img/tiles.png");
            tilesSpriteBackground.setTexture(tilesTextureBackground);
            tilesSpriteSelector.setTexture(cursorTexture);

            tilesSpriteSelector.setPosition(0, 0);

            std::cout << "Use Q key to save map" << std::endl;
        }

        void event();
        void update(float);
        void draw();
        
        sf::Texture cursorTexture;
        sf::Sprite cursorSprite;

        sf::RenderWindow tilesWindow;
        sf::Texture tilesTextureBackground; // background
        sf::Sprite tilesSpriteBackground; 
        sf::Sprite tilesSpriteSelector; // cursorTexture
};

void Editor::click(bool isLeft, const int x, const int y)
{
    if (isLeft)
    {
        sf::Vector2i pos = (sf::Vector2i)tilesSpriteSelector.getPosition();
        image_t image = {pos.x/TILE, pos.y/TILE};
        map_add_image(map, x, y, image);
    }
    else
    {
        map_rem_image(map, x, y);
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
                    
                    case sf::Keyboard::Key::Q:
                        map_save(map);
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
    window.draw(cursorSprite);

    // tiles

    tilesWindow.clear(sf::Color(90, 90, 90));
    tilesWindow.draw(tilesSpriteBackground);
    tilesWindow.draw(tilesSpriteSelector);
    tilesWindow.display();
}

int main(int argc, char const *argv[])
{

    Editor e;

    e.start();


    return 0;
}
