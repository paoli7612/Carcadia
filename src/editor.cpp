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
            init(800, 600, "Carcadia");
            cursorTexture.loadFromFile("img/cursor.png");
            cursorSprite.setTexture(cursorTexture);
        }

        void event();
        void update(float);
        void draw();

        sf::Texture cursorTexture;
        sf::Sprite cursorSprite;
};

void Editor::event()
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
                if (event.key.code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                    running = false;
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
}

int main(int argc, char const *argv[])
{

    Editor e;

    e.start();


    return 0;
}
