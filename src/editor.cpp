// editor

#include <iostream>

#include "../include/loop.h"
#include "../include/map.h"
#include "../include/player.h"

using namespace std;

class Editor : public Loop {
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

void Editor::event()
{
    sf::Event event;
    while (tilesWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::MouseButtonPressed:
                sf::Vector2i m = sf::Mouse::getPosition(tilesWindow);
                int x = m.x/32*32;
                int y = m.y/32*32;
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
                if (event.key.code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                    running = false;
                }
                break;
            
            case sf::Event::MouseMoved:
                {
                    sf::Vector2i m = sf::Mouse::getPosition(window);
                    int x = m.x/32*32;
                    int y = m.y/32*32;
                    cursorSprite.setPosition(x, y);
                }
                break;
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
